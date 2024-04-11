#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;
const int Maxm = Maxn * Maxn;
const int Maxq = Maxn * Maxn;

int n, m, q;
int a[Maxm], b[Maxm], c[Maxm];
vector <ii> E;
int par[Maxn], fl[Maxn], siz[Maxn];

int getPar(int x)
{
	if (x == par[x]) return x;
	getPar(par[x]);
	fl[x] ^= fl[par[x]]; 
	return par[x] = par[par[x]];
}

bool oddCycle(int a, int b)
{
	int para = getPar(a), parb = getPar(b);
	if (para == parb) return fl[a] == fl[b];
	if (siz[para] >= siz[parb]) { siz[para] += siz[parb]; fl[parb] ^= fl[a] ^ fl[b] ^ 1; par[parb] = para; }
	else { siz[parb] += siz[para]; fl[para] ^= fl[a] ^ fl[b] ^ 1; par[para] = parb; }
	return false;
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		E.push_back(ii(c[i], i));
	}
	sort(E.begin(), E.end());
	for (int i = 0; i < q; i++) {
		int l, r; scanf("%d %d", &l, &r);
		for (int j = 1; j <= n; j++)
			par[j] = j, siz[j] = 1, fl[j] = 0;
		bool found = false;
		for (int j = E.size() - 1; j >= 0 && !found; j--)
			if (l <= E[j].second && E[j].second <= r)
				if (oddCycle(a[E[j].second], b[E[j].second])) {
					printf("%d\n", E[j].first); found = true;
				}
		if (!found) printf("-1\n");
	}
	return 0;
}