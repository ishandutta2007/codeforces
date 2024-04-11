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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
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

ll query(ll l, ll r){
	assert(l < r);
	ll ret;
	cout << "?" << " " << l << " " << r << endl;
	cin >> ret;
	return ret;
}

ll n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	ll p = query(1, n);
	
	if(p >= 2 && query(1, p) == p){
		ll ub = p, lb = 1, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(query(mid, p) == p) lb = mid;
			else ub = mid;
		}
		cout << "! " << lb << endl;
	}
	else{
		ll ub = n, lb = p, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(query(p, mid) == p) ub = mid;
			else lb = mid;
		}
		cout << "! " << ub << endl;
	}
	
	return 0;
}