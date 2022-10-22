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

ll n;
ll a[100005];
map<ll, ll> mp, tmp;

ll get(ll x)
{
	ll ret = 1;
	for(ll t = x; t; t/=2) ret *= 2;
	return ret/2;
}

bool check(ll x)
{
	//cout << x << endl;
	tmp = mp; vector<ll> vec;
	rep(i, 1, x){
		rep(j, 0, inf){
			if(tmp[1LL<<j]) tmp[1LL<<j]--;
			else{
				vec.push_back(1LL<<(j-1));
				break;
			}
		}
	}
	
	//for(auto x : vec) cout << x << " "; cout << endl;
	
	for(auto x : vec){
		while(tmp.size() && tmp.rbegin()->second == 0) tmp.erase(tmp.rbegin()->first);
		if(tmp.size() == 0) break;
		if(get(tmp.rbegin()->first) > x) return false;
		tmp.rbegin()->second--;
	}
	while(tmp.size() && tmp.rbegin()->second == 0) tmp.erase(tmp.rbegin()->first);
	//for(auto p : tmp) cout << p.first << " " << p.second << " "; cout << endl;
	
	return tmp.size() == 0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], mp[a[i]]++;
	
	tmp = mp; ll cnt = 0;
	while(tmp[1]){
		rep(i, 0, inf){
			if(tmp[1LL<<i]) tmp[1LL<<i]--;
			else break;
		}
		cnt++;
	}
	
	ll ub = cnt+1, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	if(ub == cnt+1) cout << -1 << endl;
	else{
		rep(i, ub, cnt) cout << i << " ";
		cout << endl;
	}
	
	return 0;
}