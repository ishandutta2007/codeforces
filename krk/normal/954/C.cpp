#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); a[i]--;
	}
	int my = 1;
	for (int i = 0; i + 1 < n; i++) {
		int cur = abs(a[i + 1] - a[i]);
		if (cur != 1)
			if (my != 1 && my != cur) { printf("NO\n"); return 0; }
			else my = cur;
	}
	int y = my;
	if (y == 0) { printf("NO\n"); return 0; }
	int x = 1000000000;
	for (int i = 0; i + 1 < n; i++) {
		int fir = a[i] / y + 1;
		int sec = a[i] % y + 1;
		x = max(x, fir);
		if (a[i] + y == a[i + 1]) {
			if (fir >= x) { printf("NO\n"); return 0; }
		} else if (a[i] - y == a[i + 1]) {
			if (fir <= 1) { printf("NO\n"); return 0; }
		} else if (a[i] + 1 == a[i + 1]) {
			if (sec >= y) { printf("NO\n"); return 0; }
		} else if (a[i] - 1 == a[i + 1]) {
			if (sec <= 1) { printf("NO\n"); return 0; }
		}
	}
	printf("YES\n");
	printf("%d %d\n", x, y);
	return 0;
}