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

ll T;
ll n, k;
ll p[105];

bool check(ll x)
{
	ll sum = p[0]+x;
	rep(i, 1, n-1){
		if(p[i]*100 > k*sum) return false;
		sum += p[i];
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> k;
		rep(i, 0, n-1) cin >> p[i];
		
		ll ub = 1e14, lb = -1, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(check(mid)) ub = mid;
			else lb = mid;
		}
		cout << ub << endl;
	}
	
	return 0;
}