#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, k;
int a[Maxn];

int Solve()
{
	bool ch = true;
	while (ch) {
		ch = false;
		for (int i = 0; i + 1 < n; i++)
			if (a[i] < a[i + 1]) {
				int tk = a[i + 1] - a[i];
				if (i > 0) tk = min(tk, a[i - 1] + 1 - a[i]);
				if (tk >= k) return i + 1;
				a[i] += tk; k -= tk;
				ch = true;
				break;
			}
	}
	return -1;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("%d\n", Solve());
	}
    return 0;
}