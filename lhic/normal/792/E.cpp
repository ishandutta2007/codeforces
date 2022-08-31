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
ll a[600];
vector<int> vv;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 1; i < 40000; ++i) {
		if (a[0] / i >= a[0] % i)
			vv.push_back(i);
	}
	for (int i = 1; i < 40000; ++i) {
		ll k = a[0] / i;
		if (k > 0 && (a[0] / k >= a[0] % k))
			vv.push_back(k);
		k -= 1;
		if (k > 0 && (a[0] / k >= a[0] % k))
			vv.push_back(k);
	}
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	random_shuffle(a, a + n);
	for (int i = vv.size() - 1; i >= 0; --i) {
		int x = vv[i];
		int fl = 0;
		for (int j = 0; j < n; ++j) {
			if (a[j] / x < a[j] % x) {
				fl = 1;
				break;
			}
		}
		if (!fl) {
			ll ans = 0;
			for (int j = 0; j < n; ++j) {
				ans += a[j] / (x + 1);
				if (a[j] % (x + 1))
					++ans;
			}
			cout << ans << "\n";
			return 0;
		}
	}
	return 0;
}