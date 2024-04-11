#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int main()
{
	int t; scanf ("%d", &t); while (t--){
		int n, m; bool g = 1;
		scanf ("%d %d", &n, &m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
			int a, o = 4;  scanf ("%d", &a);
			if (i == 0 || i == n - 1) o--;
			if (j == 0 || j == m - 1) o--;
			if (a > o) g = 0;
		}
		puts(g ? "YES" : "NO");
		if (g){
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
				int o = 4;
				if (i == 0 || i == n - 1) o--;
				if (j == 0 || j == m - 1) o--;
				printf ("%d%c", o, j + 1 < m ? ' ' : '\n');
			}
		}
	}
	return 0;
}