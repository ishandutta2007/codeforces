#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
		cerr << (*i) << " ";
    }
    cerr << "\n";
}

set<pair<ll, ll> > ss;
int q;
ll m;

int bd(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
	b.first -= a.first;
	b.second -= a.second;
	c.first -= a.first;
	c.second -= a.second;
	return ((ld)b.first * (ld)c.second - (ld)b.second * (ld)c.first) <= 0;
}

int main() {
	scanf("%d%lld", &q, &m);
	int ij = 0;
	ss.insert(make_pair(0, 0));
	for (int i = 0; i < q; ++i) {
		int k, t, h;
		ll x, y, a, b;
		scanf("%d%d%d", &k, &t, &h);
		if (k == 1) {
			x = (t + ij) % 1000000 + 1;
			y = (h + ij) % 1000000 + 1;
			auto it = ss.lower_bound(make_pair(x, 0));
			if (it != ss.end() && it->second <= y)
				continue;
			auto it2 = prev(it);
			if (it != ss.end() && bd(*it2, make_pair(x, y), *it))
				continue;
			it = ss.insert(make_pair(x, y)).first;
			while (next(it) != ss.end() && next(it)->first == x)
				ss.erase(next(it));
			while (prev(it) != ss.begin() && bd(*prev(prev(it)), *prev(it), *it))
				ss.erase(prev(it));
		}
		else {
			b = (t + ij) % 1000000 + 1;
			a = (h + ij) % 1000000 + 1;
			auto it = ss.lower_bound(make_pair((a + b - 1) / b, 0));
			int fl = 0;
			if (it != ss.end()) {
				if (it->second * b <= m)
					fl = 1;
				else {
					auto it2 = prev(it);
					if (bd(make_pair(it2->first * b, it2->second * b), make_pair(a, m), make_pair(it->first * b, it->second * b)))
						fl = 1;
				}
			}
			if (fl) {
				printf("YES\n");
				ij = i + 1;
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}