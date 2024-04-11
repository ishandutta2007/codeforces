#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 100005;
const int Maxm = 524288;

struct node {
	int mx;
	ll fl;
	int cnt;
	node(int mx = 0, ll fl = 0, int cnt = 0): mx(mx), fl(fl), cnt(cnt) {}
};

int n, q;
int h[Maxn];
ll A[Maxn], B[Maxn], C[Maxn];
vector <int> un;
node st[Maxm];

node Union(const node &a, const node &b)
{
	node c; c.mx = max(a.mx, b.mx);
	c.fl = a.fl + b.fl;
	if (c.mx > a.mx) c.fl += ll(c.mx - a.mx) * a.cnt;
	if (c.mx > b.mx) c.fl += ll(c.mx - b.mx) * b.cnt;
	c.cnt = a.cnt + b.cnt;
	return c;
}

void Change(int v, int l, int r, int x, int delt)
{
	if (l == r) {
		st[v].cnt += delt;
		st[v].mx = st[v].cnt? un[l]: 0;
	} else {
		int m = l + r >> 1;
		if (x <= m) Change(2 * v, l, m, x, delt);
		else Change(2 * v + 1, m + 1, r, x, delt);
		st[v] = Union(st[2 * v], st[2 * v + 1]);
	}
}

node Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int m = l + r >> 1;
		if (b <= m) return Get(2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
		return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
	}
}

ld Solve(ll x)
{
	int l = 0, r = un.size() - 1;
	int res = -1;
	node best;
	while (l <= r) {
		int m = l + r >> 1;
		node got = Get(1, 0, un.size() - 1, 0, m);
		if (got.fl <= x) { res = m; best = got; l = m + 1; }
		else r = m - 1;
	}
	return best.mx + ld(x - best.fl) / best.cnt;
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]); un.push_back(h[i]);
	}
	for (int i = 0; i < q; i++) {
		scanf("%I64d %I64d", &A[i], &B[i]);
		if (A[i] == 1) {
			scanf("%I64d", &C[i]);
			un.push_back(C[i]);
		}
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 1; i <= n; i++) {
		h[i] = lower_bound(un.begin(), un.end(), h[i]) - un.begin();
		Change(1, 0, un.size() - 1, h[i], 1);
	}
	for (int i = 0; i < q; i++)
		if (A[i] == 1) {
			Change(1, 0, un.size() - 1, h[B[i]], -1);
			h[B[i]] = lower_bound(un.begin(), un.end(), C[i]) - un.begin();
			Change(1, 0, un.size() - 1, h[B[i]], 1);
		} else printf("%.7lf\n", double(Solve(B[i])));
	return 0;
}