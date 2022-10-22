#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int Maxm = 21;

int q, a0, c0;
int P[Maxn][Maxm];
int A[Maxn], C[Maxn];

int Get(int v)
{
	for (int i = Maxm - 1; i >= 0; i--)
		if (A[P[v][i]] > 0)
			v = P[v][i];
	return v;
}

int main()
{
	scanf("%d %d %d", &q, &a0, &c0);
	A[1] = a0; C[1] = c0;
	for (int i = 2; i <= q + 1; i++) {
		int typ; scanf("%d", &typ);
		if (typ == 1) {
			int p, a, c; scanf("%d %d %d", &p, &a, &c);
			A[i] = a; C[i] = c;
			P[i][0] = ++p;
			for (int j = 1; j < Maxm; j++)
				P[i][j] = P[P[i][j - 1]][j - 1];
		} else {
			int v, w; scanf("%d %d", &v, &w); v++;
			ll g = 0, res = 0;
			while (w > 0) {
				int u = Get(v);
				if (A[u] == 0) break;
				int tk = min(A[u], w);
				g += tk;
				res += ll(tk) * C[u];
				A[u] -= tk; w -= tk;
			}
			printf("%I64d %I64d\n", g, res);
			fflush(stdout);
		}
	}
    return 0;
}