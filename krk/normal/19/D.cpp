#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 2000000000;
const int Maxn = 200005;
const int Maxm = 1048576;

int n;
int a[Maxn], b[Maxn], c[Maxn];
vector <int> un;
set <int> has[Maxn];
int st[Maxm];

void Update(int v, int l, int r, int x)
{
	if (l == r) st[v] = has[x].empty()? 0: *has[x].rbegin();
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x);
		else Update(2 * v + 1, m + 1, r, x);
		st[v] = max(st[2 * v], st[2 * v + 1]);
	}
}

int getY(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int res = 0;
		int m = l + r >> 1;
		if (a <= m) res = max(res, getY(2 * v, l, m, a, min(m, b)));
		if (m + 1 <= b) res = max(res, getY(2 * v + 1, m + 1, r, max(m + 1, a), b));
		return res;
	}
}

int getX(int v, int l, int r, int a, int b, int y)
{
	if (l == a && l == b) return st[v] > y? l: Inf;
	else {
		int m = l + r >> 1;
		if (b <= m) return getX(2 * v, l, m, a, b, y);
		if (m + 1 <= a) return getX(2 * v + 1, m + 1, r, a, b, y);
		return getY(2 * v, l, m, a, m) > y? getX(2 * v, l, m, a, m, y): getX(2 * v + 1, m + 1, r, m + 1, b, y);
	}
}

int main()
{
	char tmp[15];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", tmp, &b[i], &c[i]);
		if (tmp[0] == 'a') a[i] = 0;
		else if (tmp[0] == 'r') a[i] = 1;
		else a[i] = 2;
		un.push_back(b[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) {
		b[i] = lower_bound(un.begin(), un.end(), b[i]) - un.begin();
		if (a[i] == 0) { has[b[i]].insert(c[i]); Update(1, 0, un.size() - 1, b[i]); }
		else if (a[i] == 1) { has[b[i]].erase(c[i]); Update(1, 0, un.size() - 1, b[i]); }
		else {
			int x = b[i] + 1 < un.size()? getX(1, 0, un.size() - 1, b[i] + 1, un.size() - 1, c[i]): Inf;
			if (x == Inf) printf("-1\n");
			else printf("%d %d\n", un[x], *has[x].upper_bound(c[i]));
		}
	}
	return 0;
}