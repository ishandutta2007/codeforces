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
int n, k;
bitset<1010> dp;
bitset<1010> dp2;
vector<int> vv;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i) {
		int x;
		scanf("%d", &x);
		vv.push_back(x - n);
	}
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	for (int i: vv) {
		if (i == 0) {
			cout << 1 << "\n";
			return 0;
		}
	}
	int fl1 = 0, fl2 = 0;
	for (int i: vv) {
		if (i < 0)
			fl1 = 1;
		if (i > 0)
			fl2 = 1;
	}
	if (!fl1 || !fl2) {
		cout << -1 << "\n";
		return 0;
	}
	int ans = 1001;
	dp[n] = 1;
	for (int i = 1; i <= ans; ++i) {
		dp2.reset();
		for (int j: vv) {
			if (j < 0) {
				dp2 |= dp >> (-j);
			}
			else {
				dp2 |= dp << j;
			}
		}
		dp = dp2;
		if (dp[n]) {
			cout << i << "\n";
			return 0;
		}
	}
	return 0;
}