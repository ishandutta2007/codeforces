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

ll n;
int q;
char s[120000];

int main() {
	scanf("%lld%d", &n, &q);
	for (int i = 0; i < q; ++i) {
		ll u;
		scanf("%lld %s", &u, s);
		int l = strlen(s);
		ll now = 1;
		while (u % (2 * now) == 0)
			now *= 2;
		for (int j = 0; j < l; ++j) {
			if (s[j] == 'U') {
				if (2 * now > n)
					continue;
				if ((u + now) % (4 * now) == 0)
					u -= now;
				else
					u += now;
				now *= 2;
			}
			else if (s[j] == 'L') {
				if (u % 2 == 1)
					continue;
				now /= 2;
				u -= now;
			}
			else {
				if (u % 2 == 1)
					continue;
				now /= 2;
				u += now;
			}
		}
		printf("%lld\n", u);
	}
	return 0;
}