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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, k;
ll a[105];

bool check(ll d)
{
	ll ret = 0;
	rep(i, 1, n){
		ret += (a[i]+d-1)/d * d - a[i];
	}
	return ret <= k;
}

bool check2(ll np, ll p)
{
	rep(i, 1, n) if((a[i]+np-1)/np != (a[i]+p-1)/p) return true;
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i];
	sort(a+1, a+n+1);
	
	ll ub = 1e15, lb = a[n], mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	if(check(lb)){
		cout << lb << endl;
		return 0;
	}
	
	ll ans = 0, p = max(k/n, 1LL);
	while(p <= a[n]){
		ll ub = a[n]+1, lb = p, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(check2(mid, p)) ub = mid;
			else lb = mid;
		}
		ll np = ub;
		
		ub = np, lb = p, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(check(mid)) lb = mid;
			else ub = mid;
		}
		if(check(lb)) chmax(ans, lb);
		
		p = np;
	}
	cout << ans << endl;
	
	return 0;
}