#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

int q;
map <ll, ll> M;

ll getCost(ll x) { return M.find(x) != M.end()? M[x]: 0; }

int main()
{
	scanf("%d", &q);
	while (q--) {
		int typ; scanf("%d", &typ);
		if (typ == 1) {
			ll v, u, w; scanf("%I64d %I64d %I64d", &v, &u, &w);
			while (v != u)
				if (v > u) { M[v] += w; v /= 2; }
				else { M[u] += w; u /= 2; }
		} else {
			ll v, u; scanf("%I64d %I64d", &v, &u);
			ll res = 0;
			while (v != u)
				if (v > u) { res += getCost(v); v /= 2; }
				else { res += getCost(u); u /= 2; }
			printf("%I64d\n", res);
		}
	}
	return 0;
}