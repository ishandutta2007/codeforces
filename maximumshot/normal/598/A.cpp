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
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve()
{
	ll n;
	int t;

	cin >> t;

	for(;t;t--) {
		cin >> n;

		ll ans = (n + 1) * n / 2;
		ll q = 0;

		while((1ll << q) <= n) ans -= 2 * (1ll << q), q++;

		cout << ans << '\n';
	}

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}