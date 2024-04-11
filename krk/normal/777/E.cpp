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

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 524288;

struct triple {
	int a, b, h;
	bool operator <(const triple &u) const {
		if (b != u.b) return b > u.b;
		if (a != u.a) return a > u.a;
		return h < u.h;
	}
};

int n;
triple t[Maxn];
vector <int> un;
ll st[Maxm];

ll Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		ll res = 0;
		int m = l + r >> 1;
		if (a <= m) res = max(res, Get(2 * v, l, m, a, min(m, b)));
		if (m + 1 <= b) res = max(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
		return res;
	}
}

void Update(int v, int l, int r, int x, ll val)
{
	if (l == r) st[v] = max(st[v], val);
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, val);
		else Update(2 * v + 1, m + 1, r, x, val);
		st[v] = max(st[2 * v], st[2 * v + 1]);
	}
}

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &t[i].a, &t[i].b, &t[i].h);
		un.push_back(t[i].a);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	sort(t, t + n);
	for (int i = 0; i < n; i++) {
		int ind = lower_bound(un.begin(), un.end(), t[i].b) - un.begin() - 1;
		ll res = 0;
		if (ind >= 0) res = Get(1, 0, un.size() - 1, 0, ind);
		res += t[i].h;
		ind = lower_bound(un.begin(), un.end(), t[i].a) - un.begin();
		Update(1, 0, un.size() - 1, ind, res);
	}
	printf("%I64d\n", Get(1, 0, un.size() - 1, 0, un.size() - 1));
    return 0;
}