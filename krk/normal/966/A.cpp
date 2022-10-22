#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const ll Inf = 1000000000000000000ll;

int n, m, cl, ce, v;
int L[Maxn];
int E[Maxn];
int q;
ll res;

void Check(int col, int X1, int Y1, int X2, int Y2, int E[], int siz, int v)
{
	int rig = lower_bound(E, E + siz, col) - E;
	if (rig < siz) {
		ll cand = ll(abs(X1 - X2) + v - 1) / v + ll(abs(Y1 - E[rig])) + ll(abs(Y2 - E[rig]));
		res = min(res, cand);
	}
	int lef = rig - 1;
	if (lef >= 0) {
		ll cand = ll(abs(X1 - X2) + v - 1) / v + ll(abs(Y1 - E[lef])) + ll(abs(Y2 - E[lef]));
		res = min(res, cand);
	}
}

int main()
{
	scanf("%d %d %d %d %d", &n, &m, &cl, &ce, &v);
	for (int i = 0; i < cl; i++)
		scanf("%d", &L[i]);
	for (int i = 0; i < ce; i++)
		scanf("%d", &E[i]);
	scanf("%d", &q);
	while (q--) {
		int X1, Y1, X2, Y2; scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
		res = Inf;
		if (X1 == X2) res = min(res, ll(abs(Y1 - Y2)));
		Check(Y1, X1, Y1, X2, Y2, L, cl, 1);
		Check(Y2, X1, Y1, X2, Y2, L, cl, 1);
		Check(Y1, X1, Y1, X2, Y2, E, ce, v);
		Check(Y2, X1, Y1, X2, Y2, E, ce, v);
		printf("%I64d\n", res);
	}
	return 0;
}