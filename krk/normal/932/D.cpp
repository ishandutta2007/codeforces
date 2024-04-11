#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 20;
const int Maxn = 400004;

int cnt = 1;
int L[Maxn], tot[Maxn];
int P[Maxn][Maxm];
int mx[Maxn][Maxm];
int nxt[Maxn][Maxm];
ll sum[Maxn][Maxm];
int q;

void Add(int v, int par, int W)
{
	L[v] = L[par] + 1;
	int u = par;
	int curmx = W;
	for (int i = 0; (1 << i) <= L[v]; i++) {
		P[v][i] = u; mx[v][i] = curmx;
		curmx = max(curmx, mx[u][i]);
		u = P[u][i];
	}
	u = par;
	for (int i = Maxm - 1; i >= 0; i--) if ((1 << i) <= L[u] && mx[u][i] < W)
		u = P[u][i];
	tot[v] = tot[u] + 1;
	ll S = W;
	for (int i = 0; (1 << i) <= tot[v]; i++) {
		nxt[v][i] = u; sum[v][i] = S;
		S += sum[u][i];
		u = nxt[u][i];
	}
}

int getVal(int v, ll S)
{
	int res = 0;
	for (int i = Maxm - 1; i >= 0; i--) if ((1 << i) <= tot[v] && sum[v][i] <= S) {
		res += 1 << i;
		S -= sum[v][i];
		v = nxt[v][i];
	}
	return res;
}

int main()
{
	L[1] = 1;
	tot[1] = 1;
	ll lst = 0;
	scanf("%d", &q);
	while (q--) {
		int typ; ll p, q; scanf("%d %I64d %I64d", &typ, &p, &q);
		ll A = (p ^ lst);
		ll B = (q ^ lst);
		if (typ == 1) {
			cnt++; Add(cnt, A, B);
		} else if (typ == 2) {
			lst = getVal(A, B);
			printf("%I64d\n", lst);
		}
	}
	return 0;
}