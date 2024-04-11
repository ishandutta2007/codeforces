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
int n;
ll a[120000];
ll d[120000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	ll ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (i % 2 == 0)
			d[i] = abs(a[i] - a[i + 1]);
		else
			d[i] = -abs(a[i] - a[i + 1]);
	}
	ll now = 0;
	for (int i = n - 2; i >= 0; --i) {
		now += d[i];
		if (now < 0)
			now = 0;
		if (i % 2 == 0) {
			ans = max(ans, now);
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		if (i % 2 == 1)
			d[i] = abs(a[i] - a[i + 1]);
		else
			d[i] = -abs(a[i] - a[i + 1]);
	}
	now = 0;
	for (int i = n - 2; i >= 0; --i) {
		now += d[i];
		if (now < 0)
			now = 0;
		if (i % 2 == 1) {
			ans = max(ans, now);
		}
	}
	cout << ans << "\n";
	return 0;
}