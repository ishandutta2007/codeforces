#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, int> ii;

const int Maxn = 100005;
const int lim = 1000000000;

int n, m, p, q;
int par[Maxn], siz[Maxn];
ll len[Maxn];
int c;
vector <int> res1, res2;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	int para = getPar(a), parb = getPar(b);
	if (siz[para] >= siz[parb]) { siz[para] += siz[parb]; par[parb] = para; len[para] += len[parb]; }
	else { siz[parb] += siz[para]; par[para] = parb; len[parb] += len[para]; }
	c--;
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &p, &q);
	for (int i = 1; i <= n; i++) { par[i] = i; siz[i] = 1; len[i] = 0; }
	c = n;
	while (m--) {
		int a, b, l; scanf("%d %d %d", &a, &b, &l);
		if (getPar(a) != getPar(b)) unionSet(a, b);
		len[getPar(a)] += l;
	}
	if (c < q) { printf("NO\n"); return 0; }
	priority_queue <ii> Q;
	for (int i = 1; i <= n; i++)
		if (getPar(i) == i) Q.push(ii(-len[i], i));
	while (c > q) {
		int v = Q.top().second; Q.pop();
		int u = Q.top().second; Q.pop();
		unionSet(v, u); int npar = getPar(v);
		ll add = min(ll(lim), len[npar] + 1ll);
		len[npar] += add; Q.push(ii(-len[npar], npar));
		res1.push_back(u); res2.push_back(v);
	}
	if (res1.size() > p) { printf("NO\n"); return 0; }
	if (res1.size() < p) {
		int pr = 1;
		while (pr <= n && (getPar(pr) != pr || siz[pr] < 2)) pr++;
		if (pr > n) { printf("NO\n"); return 0; }
		int i = 1;
		while (getPar(i) != pr) i++;
		int j = i + 1;
		while (getPar(j) != pr) j++;
		while (res1.size() < p) { res1.push_back(i); res2.push_back(j); }
	}
	printf("YES\n");
	for (int i = 0; i < res1.size(); i++)
		printf("%d %d\n", res1[i], res2[i]);
	return 0;
}