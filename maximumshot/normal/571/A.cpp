#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve() 
{
	ll a, b, c, l, ans = 0;

	cin >> a >> b >> c >> l;

	ans = (l + 1) * (l + 2) * (l + 3) / 6ll;

	for(ll i = 0;i <= l;i++) {
		ll x;
		if(a + i >= b + c) {
			x = min(l - i, a + i - b - c);
			x = max(x, 0ll);
			ans -= (x + 1) * (x + 2) / 2;
		}
		if(b + i >= a + c) {
			x = min(l - i, b + i - a - c);
			x = max(x, 0ll);
			ans -= (x + 1) * (x + 2) / 2;
		}
		if(c + i >= a + b) {
			x = min(l - i, c + i - a - b);
			x = max(x, 0ll);
			ans -= (x + 1) * (x + 2) / 2;
		}
	}
	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();    

	return 0;
}