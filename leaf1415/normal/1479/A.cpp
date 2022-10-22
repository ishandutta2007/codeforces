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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;

ll query(ll x){
	ll ret;
	cout << "? " << x << endl;
	cin >> ret;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	if(n == 1){
		cout << "! " << 1 << endl;
		return 0;
	}
	
	ll l = query(1);
	if(query(2) > l){
		cout << "! " << 1 << endl;
		return 0;
	}
	ll r = query(n);
	if(query(n-1) > r){
		cout << "! " << n << endl;
		return 0;
	}
	
	ll ub = n-1, lb = 1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		ll res = query(mid), res2 = query(mid+1);
		if(res < res2) ub = mid;
		else lb = mid;
	}
	cout << "! " << ub << endl;
	
	return 0;
}