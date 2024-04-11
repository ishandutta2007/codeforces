#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <deque>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 524288;
const int mod = 1000000007;

vector <ii> V[Maxm];
int h, w, n;
int u[Maxn], l[Maxn], r[Maxn], s[Maxn];
int res[Maxn];

bool Less(const int &a, const int &b) 
{
	return u[a] < u[b];
}

int Min(const int &a, const int &b)
{
	return Less(a, b)? b: a;
}

void Update(int v, int l, int r, int a, int b, int ind, int val)
{
	if (l == a && r == b) {
		while (!V[v].empty() && V[v].back().first <= val) V[v].pop_back();
		V[v].push_back(ii(val, ind));
	} else {
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), ind, val);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, ind, val);
	}
}

int Get(int v, int l, int r, int x, int nd)
{
	int lef = 0, rig = int(V[v].size()) - 1;
	int got = -1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (V[v][mid].first >= nd) { got = mid; lef = mid + 1; }
		else rig = mid - 1;
	}
	int res = n;
	if (got >= 0) res = Min(res, V[v][got].second);
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) return Min(res, Get(2 * v, l, m, x, nd));
		else return Min(res, Get(2 * v + 1, m + 1, r, x, nd));
	}
	return res;
}

int main() 
{
	scanf("%d %d %d", &h, &w, &n);
	vector <int> seq;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &u[i], &l[i], &r[i], &s[i]);
		seq.push_back(i);
	}
	sort(seq.begin(), seq.end(), Less);
	u[n] = -1; res[n] = 1;
	for (int i = 0; i < seq.size(); i++) {
		int ind = seq[i];
		int a = l[ind] > 1? Get(1, 1, w, l[ind] - 1, u[ind]): Get(1, 1, w, r[ind] + 1, u[ind]);
		int b = r[ind] < w? Get(1, 1, w, r[ind] + 1, u[ind]): Get(1, 1, w, l[ind] - 1, u[ind]);
		res[ind] = (res[ind] + res[a]) % mod;
		res[ind] = (res[ind] + res[b]) % mod;
		Update(1, 1, w, l[ind], r[ind], ind, u[ind] + s[ind]);
	}
	int tres = 0;
	for (int i = 1; i <= w; i++)
		tres = (tres + res[Get(1, 1, w, i, h + 1)]) % mod;
	printf("%d\n", tres);
    return 0;
}