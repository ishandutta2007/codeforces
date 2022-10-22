#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Inf = 2000000005;

int n;
ii xw[Maxn];
vector <int> un;
int st[Maxm];

void Union(int v)
{
	st[v] = max(st[2 * v], st[2 * v + 1]);
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int res = 0;
		int m = l + r >> 1;
		if (a <= m) res = max(res, Get(2 * v, l, m, a, min(m, b)));
		if (m + 1 <= b) res = max(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
		return res;
	}
}

void Update(int v, int l, int r, int x, int val)
{
	if (l == r) st[v] = max(st[v], val);
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, val);
		else Update(2 * v + 1, m + 1, r, x, val);
		Union(v);
	}
}

int getInd(int val)
{
	return lower_bound(un.begin(), un.end(), val) - un.begin();
}

void getInterval(int u, int v, int &a, int &b)
{
	a = lower_bound(un.begin(), un.end(), u) - un.begin();
	b = upper_bound(un.begin(), un.end(), v) - un.begin() - 1;
}

void Update(int X, int W)
{
	int a, b; getInterval(-Inf, X - W, a, b);
	int got = a > b? 0: Get(1, 0, un.size() - 1, a, b);
	Update(1, 0, un.size() - 1, getInd(X + W), got + 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &xw[i].first, &xw[i].second);
		un.push_back(xw[i].first + xw[i].second);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	sort(xw, xw + n);
	for (int i = 0; i < n; i++)
		Update(xw[i].first, xw[i].second);
	printf("%d\n", st[1]);
	return 0;
}