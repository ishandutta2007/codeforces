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

ll k, a, b;

int main() {
	cin >> k >> a >> b;
	ll cnt = a / k + b / k;
	if (a % k != 0 && b / k == 0) {
		cout << -1 << "\n";
	}
	else if (a / k == 0 && b % k != 0) {
		cout << -1 << "\n";
	}
	else
		cout << cnt << "\n";
	return 0;
}