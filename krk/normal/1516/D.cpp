#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxm = 20;

int mx[Maxn];
int n, q;
int a[Maxn];
int nxt[Maxn][Maxm];
int was[Maxn];

int main()
{
	for (int i = 2; i < Maxn; i++) if (mx[i] == 0)
		for (int j = i; j < Maxn; j += i)
			mx[j] = i;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < Maxm; i++)
		nxt[n][i] = n;
	fill(was, was + Maxn, n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = n - 1; i >= 0; i--) {
		nxt[i][0] = nxt[i + 1][0];
		while (a[i] > 1) {
			int cur = mx[a[i]];
			while (a[i] % cur == 0) a[i] /= cur;
			nxt[i][0] = min(nxt[i][0], was[cur]);
			was[cur] = i;
		}
		for (int j = 1; j < Maxm; j++)
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
	}
	for (int i = 0; i < q; i++) {
		int l, r; scanf("%d %d", &l, &r); l--; r--;
		int res = 1;
		for (int j = Maxm - 1; j >= 0; j--) if (nxt[l][j] <= r) {
			res += 1 << j;
			l = nxt[l][j];
		}
		printf("%d\n", res);
	}
    return 0;
}