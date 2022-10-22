#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {
	
	ll n, a, b, c;
	cin >> n >> a >> b >> c;

	if(n < a && n < b) {
		cout << 0 << '\n';
	}else {
		if(a <= (b - c)) {
			cout << n / a << '\n';
		}else {
		   if(n >= b) {
			ll x = (n - b) / (b - c) + 1;
			ll ans = x;
			n -= x * (b - c);
			// n < b
			ans += n / a;
			cout << ans << '\n';
		   }else cout << n / a << '\n';
		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}