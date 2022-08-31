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
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
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
ll k;
ll a[123000];

int main() {
    scanf("%d%lld", &n, &k);
    ll mn = 1e9 + 100;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
        mn = min(mn, a[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if ((a[i] - mn) % k != 0) {
            cout << -1 << "\n";
            return 0;
        }
        ans += (a[i] - mn) / k;
    }
    cout << ans << "\n";
	return 0;
}