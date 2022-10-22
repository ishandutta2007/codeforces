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

ll Q;
ll n;

ll calc(ll x)
{
	return min(2*(n-x), x*(x-1)/2+n-x);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	while(Q--){
		cin >> n;
		
		//rep(i, 1, n-1) cout << calc(i) << endl;
		
		ll ub = n-1, lb = 1, mid, mid2;
		while(ub-lb>4){
			mid = (ub+lb*2)/3, mid2 = (ub*2+lb)/3;
			if(calc(mid) < calc(mid2)) lb = mid;
			else ub = mid2;
		}
		ll ans = 0;
		rep(i, lb, ub) chmax(ans, calc(i));
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}