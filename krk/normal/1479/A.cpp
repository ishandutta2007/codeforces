#include <bits/stdc++.h>
using namespace std;

int Ask(int ind)
{
	printf("? %d\n", ind); fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

void Write(int ind)
{
	printf("! %d\n", ind); fflush(stdout);
}

int main()
{
	int n; scanf("%d", &n);
	if (n == 1) { Write(1); return 0; }
	int a = Ask(1), b = Ask(2);
	int c = Ask(n - 1), d = Ask(n);
	int l = 1, r = n;
	if (a < b) { Write(1); return 0; }
	if (c > d) { Write(n); return 0; }
	while (l <= r) {
		int m = l + r >> 1;
		int fir = Ask(m - 1);
		int sec = Ask(m);
		int thir = Ask(m + 1);
		if (fir < sec) { c = fir; d = sec; r = m; }
		else if (sec > thir) { a = sec; b = thir; l = m; }
		else { Write(m); return 0; }
	}
    return 0;
}