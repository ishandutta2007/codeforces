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

ll a[120];

int main() {
	ll n;
	cin >> n;
	a[0] = 1;
	a[1] = 2;
	int mx = 1;
	for (int i = 2; a[i - 1] <= n; ++i) {
		mx = i;
		a[i] = a[i - 1] + a[i - 2];
	}
	int ans = 0;
	for (int i = 0; i <= mx; ++i)
		if (n >= a[i])
			ans = i;
	cout << ans << "\n";
	return 0;
}