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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, k, m, d;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> m >> d;
	
	ll ans = 0;
	rep(i, 1, d){
		if(i-1 > n/k+1) continue;
		ll x = min(m, n/((i-1)*k+1));
		if(x <= 0) continue;
		ll p = (n/x-1)/k+1;
		if(p > d || p <= 0) continue;
		chmax(ans, p*x);
	}
	cout << ans << endl;
	
	return 0;
}