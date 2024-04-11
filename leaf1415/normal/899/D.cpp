#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;

ll calc(ll x)
{
	ll l = max(1LL, x-n), r = min(n, x-1);
	return max(0LL, r-l+1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	if(2*n < 10){
		cout << n*(n-1)/2 << endl;
		return 0;
	}
	
	ll mul = 1;
	for(ll t = 2*n; t; t/=10) mul *= 10;
	mul /= 10;
	
	ll ans = 0;
	rep(i, 0, 9){
		ans += calc(mul*i + mul-1);
	}
	cout << ans/2 << endl;
	
	return 0;
}