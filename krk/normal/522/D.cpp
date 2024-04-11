#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 500005;
const int Maxm = 2097152;
const int Inf = 1000000000;

int n, m;
int a[Maxn];
map <int, int> M;
vector <ii> st[Maxm];

void addVector(vector <ii> &V, ii val)
{
	if (V.empty() || V.back().second > val.second)
		V.push_back(val);
}

void Add(int v, int l, int r, int a, int b, ii val)
{
	if (l == a && r == b) addVector(st[v], val);
	else {
		int m = l + r >> 1;
		if (a <= m) Add(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
	}
}

int getVector(const vector <ii> &V, int r)
{
	int ind = upper_bound(V.begin(), V.end(), ii(r, Inf)) - V.begin() - 1;
	if (ind < 0) return Inf;
	return V[ind].second;
}

int Get(int v, int l, int r, int x, int R)
{
	int res = getVector(st[v], R);
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) res = min(res, Get(2 * v, l, m, x, R));
		if (m + 1 <= x) res = min(res, Get(2 * v + 1, m + 1, r, x, R));
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (M.find(a[i]) != M.end()) {
			int ind = M[a[i]];
			Add(1, 1, n, 1, ind, ii(i, i - ind));
		}
		M[a[i]] = i;
	}
	while (m--) {
		int l, r; scanf("%d %d", &l, &r);
		int res = Get(1, 1, n, l, r);
		printf("%d\n", res == Inf? -1: res);
	}
	return 0;
}