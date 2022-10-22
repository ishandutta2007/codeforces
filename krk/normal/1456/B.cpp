#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxb = 30;

int n;
int a[Maxn];

int Solve(int b, int n)
{
	if (b < 0 || n <= 0) return Maxn;
	int pnt = 0;
	while (pnt < n && !(a[pnt] & 1 << b)) pnt++;
	if (pnt >= n) return Solve(b - 1, n);
	if (n - pnt > 2) return 1;
	int res = Solve(b - 1, pnt);
	if (n - pnt == 2) {
		int cur = 0;
		for (int i = n - 2; i >= 0; i--) {
			cur ^= a[i];
			if (cur > a[n - 1]) {
				res = min(res, n - 2 - i);
				break;
			}
		}
		if (n > 2 && a[n - 3] > (a[n - 2] ^ a[n - 1]))
			res = 1;
		else {
			int mem = a[n - 2];
			a[n - 2] ^= a[n - 1];
			res = min(res, 1 + Solve(b - 1, n - 1));
			a[n - 2] = mem;
		}
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int res = Solve(Maxb - 1, n);
	printf("%d\n", res < Maxn? res: -1);
    return 0;
}