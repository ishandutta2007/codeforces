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

ll gcd(ll a, ll b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll T;
ll n, k;
ll x[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> k;
		rep(i, 1, n) cin >> x[i];
		sort(x+1, x+n+1);
		
		ll g = 0;
		rep(i, 1, n-1) g = gcd(x[i+1]-x[i], g);
		
		if(abs(k-x[1])%g == 0) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	flush(cout);
	
	return 0;
}