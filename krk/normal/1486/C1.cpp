#include <bits/stdc++.h>
using namespace std;

int n;

int Ask(int l, int r)
{
	printf("? %d %d\n", l, r); fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

int main()
{
	scanf("%d", &n);
	int cur = Ask(1, n);
	if (cur == 1 || Ask(1, cur) != cur) {
		int l = cur + 1, r = n;
		while (l <= r) {
			int m = l + r >> 1;
			if (Ask(1, m) == cur) r = m - 1;
			else l = m + 1;
		}
		printf("! %d\n", l);
	} else {
		int l = 1, r = cur - 1;
		while (l <= r) {
			int m = l + r >> 1;
			if (Ask(m, n) == cur) l = m + 1;
			else r = m - 1;
		}
		printf("! %d\n", r);
	}
	fflush(stdout);
    return 0;
}