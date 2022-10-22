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
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

ll T;
ll n, m;
vector<ll> pavec, pbvec, navec, nbvec;

ll calc(vector<ll> &avec, vector<ll> &bvec)
{
	sort(all(avec)), sort(all(bvec));
	
	ll ret = 0, cnt = 0;
	for(ll i = (ll)avec.size()-1; i >= 0; i--){
		ll p = upper_bound(all(bvec), avec[i]) - bvec.begin();
		rep(j, p, (ll)bvec.size()-1){
			if(i < (ll)avec.size()-1 && bvec[j] >= avec[i+1]) break;
			ll num = upper_bound(all(bvec), bvec[j]) - lower_bound(all(bvec), bvec[j]-i);
			chmax(ret, num + cnt);
		}
		p = lower_bound(all(bvec), avec[i]) - bvec.begin();
		if(p < (ll)bvec.size() && bvec[p] == avec[i]) cnt++;
		//cout << avec[i] << " " << ret << " " << cnt << endl;
	}
	chmax(ret, cnt);
	
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> m;
		pavec.clear(), pbvec.clear(), navec.clear(), nbvec.clear();
		
		ll x;
		rep(i, 1, n){
			cin >> x;
			if(x > 0) pavec.push_back(x);
			else navec.push_back(-x);
		}
		rep(i, 1, m){
			cin >> x;
			if(x > 0) pbvec.push_back(x);
			else nbvec.push_back(-x);
		}
		cout << calc(pavec, pbvec) + calc(navec, nbvec) << endl;
	}
	
	return 0;
}