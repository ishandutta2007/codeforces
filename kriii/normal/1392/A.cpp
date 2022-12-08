#include <stdio.h>

int main()
{
	int t; scanf ("%d", &t); while (t--){
		int n, x, g = 0; scanf ("%d %d", &n, &x);
		for (int i = 1; i < n; i++){
			int y; scanf ("%d", &y);
			if (x != y) g = 1;
		}
		printf ("%d\n", g ? 1 : n);
	}
	return 0;
}