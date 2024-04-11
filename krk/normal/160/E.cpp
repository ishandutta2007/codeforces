#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 2000000000;
const int Maxn = 400005;
const int Maxm = 2097152;

int n, m;
int s[Maxn], f[Maxn], t[Maxn];
int l[Maxn], r[Maxn], b[Maxn];
vector <int> un;
ii E[Maxn];
set <ii> st[Maxm];
int res[Maxn];

int Get(int v) { return lower_bound(un.begin(), un.end(), v) - un.begin(); }

void Insert(int v, int l, int r, int a, int b, ii nw)
{
	if (l == a && r == b) st[v].insert(nw);
	else {
		int m = l + r >> 1;
		if (a <= m) Insert(2 * v, l, m, a, min(m, b), nw);
		if (m + 1 <= b) Insert(2 * v + 1, m + 1, r, max(m + 1, a), b, nw);
	}
}

ii Get(int v, int l, int r, int x, int b)
{
	set <ii>::iterator it = st[v].lower_bound(ii(b, 0));
	ii res = it == st[v].end()? ii(Inf, -1): *it;
	if (l < r) {
		int m = l + r >> 1;
		ii got = x <= m? Get(2 * v, l, m, x, b): Get(2 * v + 1, m + 1, r, x, b);
		if (got.first < res.first) res = got;
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &s[i], &f[i], &t[i]);
		un.push_back(s[i]); un.push_back(f[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &l[i], &r[i], &b[i]);
		un.push_back(l[i]); un.push_back(r[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) {
		s[i] = Get(s[i]); f[i] = Get(f[i]);
		E[i] = ii(s[i], i);
	}
	for (int i = 0; i < m; i++) {
		l[i] = Get(l[i]); r[i] = Get(r[i]);
		E[n + i] = ii(l[i], n + i);
	}
	sort(E, E + n + m);
	for (int i = 0; i < n + m; i++) {
		ii p = E[i];
		if (p.second < n) Insert(1, 0, un.size() - 1, s[p.second], f[p.second], ii(t[p.second], p.second + 1));
		else res[p.second - n] = Get(1, 0, un.size() - 1, r[p.second - n], b[p.second - n]).second;
	}
	for (int i = 0; i < m; i++)
		printf("%d%c", res[i], i + 1 < m? ' ': '\n');
	return 0;
}