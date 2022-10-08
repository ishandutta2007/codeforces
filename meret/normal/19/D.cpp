#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int N = (1 << 18) + 5;

int x[N], y[N];
bool active[N];

struct IntervalTree {
	inline int ls(int x) { return x << 1; }
	inline int rs(int x) { return (x << 1) + 1; }

	int biggestY[2 * N];

	void swapActive(int x, int l, int r, int c) {
		if (l == r) {
			active[c] ^= 1;
			if (active[c])
				biggestY[x] = y[c];
			else
				biggestY[x] = -1;
			return;
		}
		int m = (l + r) / 2;
		if (c <= m)
			swapActive(ls(x), l, m, c);
		else
			swapActive(rs(x), m + 1, r, c);
		biggestY[x] = max(biggestY[ls(x)], biggestY[rs(x)]);
	}

	int findFirst(int x, int l, int r, int cl, int cr, int minY) {
		if (cr < cl)
			return -1;
		if (biggestY[x] < minY)
			return -1;
		if (l == r)
			return l;
		int m = (l + r) / 2;
		int res = -1;
		if (cl <= m)
			res = findFirst(ls(x), l, m, cl, min(m, cr), minY);
		if (cr > m && res == -1)
			res = findFirst(rs(x), m + 1, r, max(m + 1, cl), cr, minY);
		return res;
	}
};

IntervalTree tree;

int n, m;

struct Query {
	int x, y, index;
};

bool operator < (Query a, Query b) {
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

int ind[N];

int next[N];

Query queries[N];
string command[N];

int main() {
	cin >> n;
	m = 1;
	while (m < n)
		m <<= 1;
	for (int i = 1; i <= 2 * m - 1; ++i)
		tree.biggestY[i] = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> command[i] >> queries[i].x >> queries[i].y;
		queries[i].index = i;
	}
	sort(queries + 1, queries + n + 1);
	int p = 0;
	for (int i = 1; i <= n; ++i) {
		x[i] = queries[i].x;
		y[i] = queries[i].y;
		if (p == 0 || x[p] != x[i] || y[p] != y[i])
			p = i;
		ind[queries[i].index] = p;
	}
	next[0] = 1;
	for (int i = 1; i <= n; ++i) {
		next[i] = next[i - 1];
		while (next[i] <= n && x[next[i]] == x[i])
			++next[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (command[i] == "find") {
			int res = tree.findFirst(1, 1, m, next[ind[i]], m, y[ind[i]] + 1);
			if (res == -1)
				cout << "-1\n";
			else
				cout << x[res] << " " << y[res] << "\n";
		} else
			tree.swapActive(1, 1, m, ind[i]);
	}
}