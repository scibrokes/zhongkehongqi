#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

int main()
{
	WINDOW *pad_ptr;
	int x, y;
	int pad_lines;
	int pad_cols;
	char disp_char;

	initscr();
	pad_lines = LINES + 50;
	pad_cols = COLS + 50;
	pad_ptr = newpad(pad_lines, pad_cols);
	disp_char = '甲';

	for (x = 0; x < pad_lines; x++) {
		for (y = 0; y < pad_cols; y++) {
			mvwaddch(pad_ptr, x, y, disp_char);
			if (disp_char == '癸') disp_char = '甲';
			else disp_char++;
		}
	}
	
	prefresh(pad_ptr, 5, 7, 2, 2, 9, 9);
	sleep(1);
	prefresh(pad_ptr, LINES + 5, COLS + 7, 5, 5, 21, 19);
	sleep(1);
	delwin(pad_ptr);
	endwin();
	exit(EXIT_SUCCESS);
}









