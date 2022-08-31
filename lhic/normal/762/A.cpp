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

ll n, k;

int main() {
	cin >> n >> k;
	vector<ll> vv;
	for (ll i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			vv.push_back(i);
			if (i * i != n)
				vv.push_back(n / i);
		}
	}
	sort(vv.begin(), vv.end());
	if (vv.size() < k)
		cout << -1 << "\n";
	else
		cout << vv[k - 1] << "\n";
	return 0;
}