#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 524288;

int m;
ii st[Maxm];
int my[Maxn];

void Union(int v)
{
	int lc = 2 * v, rc = 2 * v + 1;
	int tk = min(st[lc].second, st[rc].first);
	st[v] = ii(st[lc].first + st[rc].first - tk, st[lc].second + st[rc].second - tk);
}

void Update(int v, int l, int r, int x, bool pop)
{
	if (l == r) 
		if (pop) st[v].first++;
		else st[v].second++;
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, pop);
		else Update(2 * v + 1, m + 1, r, x, pop);
		Union(v);
	}
}

int Get(int v, int l, int r, int rem)
{
	if (l == r) return my[l];
	else {
		int m = l + r >> 1;
		if (st[2 * v + 1].second <= rem) return Get(2 * v, l, m, rem - st[2 * v + 1].second + st[2 * v + 1].first);
		else return Get(2 * v + 1, m + 1, r, rem);
	}
}

int main() 
{
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int p, t; scanf("%d %d", &p, &t);
		if (t == 0) Update(1, 1, m, p, true);
		else {
			scanf("%d", &my[p]);
			Update(1, 1, m, p, false);
		}
		if (st[1].second == 0) printf("-1\n");
		else printf("%d\n", Get(1, 1, m, 0));
	}
    return 0;
}