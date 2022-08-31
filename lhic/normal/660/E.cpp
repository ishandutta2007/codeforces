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


typedef long long ll;
typedef long double ld;

using namespace std;
ll n, m;

ll go[2];

const ll MOD = 1000000007;



int main() {
	cin >> n >> m;
	go[0] = 1;
	ll sum = 1;
	for (int i = 0; i < n; ++i) {
		go[1] = (go[1] * (m - 1) + sum) % MOD;
		go[0] = (go[0] * m) % MOD;
		sum = (go[0] + m * go[1]) % MOD;
	}
	cout << sum << "\n";
	return 0;
}