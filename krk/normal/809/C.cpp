#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

struct pos {
	int r, c, val;
	pos(int r = 0, int c = 0, int val = 0): r(r), c(c), val(val) {}
	bool operator <(const pos &u) const {
		if (r != u.r) return r < u.r;
		if (c != u.c) return c < u.c;
		return val < u.val;
	}
};

const int mod = 1000000007;
const int Maxd = 31;

int sum[Maxd];
map <pos, ii> M;

ii Get(pos p)
{
	if (p.r <= 0 || p.c <= 0 || p.val <= 0) return ii(0, 0);
	int sz = 0;
	while (1 << sz < p.r || 1 << sz < p.c) sz++;
	if (1 << sz <= p.val) p.val = 1 << sz;
	map <pos, ii>::iterator it = M.find(p);
	if (it == M.end()) {
		int sz = 0;
		while (1 << sz < p.r || 1 << sz < p.c) sz++;
		ii res = ii(0, 0);
		if (1 << sz <= p.val) p.val = 1 << sz;
		if ((1 << sz == p.r) && (1 << sz == p.c) && (1 << sz) <= p.val) res = ii(sum[sz], ll(1 << sz) * ll(1 << sz) % mod);
		else {
			sz--;
			int r1 = min(p.r, 1 << sz), c1 = min(p.c, 1 << sz);
			ii add = Get(pos(r1, c1, p.val));
			res.first = (res.first + add.first) % mod;
			res.second = (res.second + add.second) % mod;

			r1 = p.r - (1 << sz);
			add = Get(pos(r1, c1, p.val - (1 << sz)));
			res.first = (res.first + ll(add.first) + ll(add.second) * ll(1 << sz)) % mod;
			res.second = (res.second + add.second) % mod;

			r1 = min(p.r, 1 << sz), c1 = p.c - (1 << sz);
			add = Get(pos(r1, c1, p.val - (1 << sz)));
			res.first = (res.first + ll(add.first) + ll(add.second) * ll(1 << sz)) % mod;
			res.second = (res.second + add.second) % mod;

			r1 = p.r - (1 << sz);
			add = Get(pos(r1, c1, p.val));
			res.first = (res.first + add.first) % mod;
			res.second = (res.second + add.second) % mod;
		}
		M[p] = res;
		return res;
	}
	return it->second;
}

int main()
{
	sum[0] = 1;
	for (int i = 1; i < Maxd; i++)
		sum[i] = (4ll * ll(sum[i - 1]) + 2ll * ll(1 << i - 1) * ll(1 << i - 1) % mod * ll(1 << i - 1) % mod) % mod;
	int q; scanf("%d", &q);
	while (q--) {
		int X1, Y1, X2, Y2, k; scanf("%d %d %d %d %d", &X1, &Y1, &X2, &Y2, &k);
		int res = (Get(pos(X2, Y2, k)).first - Get(pos(X1 - 1, Y2, k)).first + mod) % mod;
		res = (res - Get(pos(X2, Y1 - 1, k)).first + mod) % mod;
		res = (res + Get(pos(X1 - 1, Y1 - 1, k)).first) % mod;
		printf("%d\n", res);
	}
	return 0;
}