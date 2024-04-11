#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

struct pos {
	ll s, x, f;
	pos(ll s = 0, ll x = 0, ll f = 0): s(s), x(x), f(f) {}
	bool operator <(const pos &b) const {
		if (s != b.s) return s < b.s;
		if (x != b.x) return x < b.x;
		return f < b.f;
	}
};

ll s, x;
map <pos, ll> M;

ll Get(ll s, ll x, ll f)
{
	pos p = pos(s, x, f);
	if (s == 0 && x == 0) return f == 0;
	if (M.find(p) == M.end()) {
		ll res = 0;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				if (bool(s & 1) == bool((f + i + j) % 2) &&
					bool(x & 1) == bool(i ^ j)) 
					res += Get(s / 2, x / 2, (f + i + j) / 2);
		M[p] = res;
	}
	return M[p];
}

int main()
{
	cin >> s >> x;
	ll res = Get(s, x, 0);
	if (s == x) res -= 2;
	printf("%I64d\n", res);
	return 0;
}