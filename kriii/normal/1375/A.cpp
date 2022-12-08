#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int main()
{
	int t; scanf ("%d", &t); while (t--){
		int n, a[100];
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
		
		int h = n / 2;
		while (1){
			int p[2] = { 0, };
			for (int i = 0; i < n; i++){
				if (rand() % 2) a[i] = -a[i];
			}
			for (int i = 1; i < n; i++){
				if (a[i - 1] - a[i] >= 0) p[0]++;
				if (a[i - 1] - a[i] <= 0) p[1]++;
			}
			if (p[0] >= h && p[1] >= h) break;
		}
		for (int i = 0; i < n; i++) printf ("%d%c", a[i], i + 1 < n ? ' ' : '\n');
	}
	return 0;
}