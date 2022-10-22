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

ll n, m, seed, vmax;
ll a[100005];
map<ll, ll> mp;

llint modpow(llint a, llint n, llint mod)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1, mod)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2, mod) % mod;
	}
}

ll get()
{
	ll ret = seed;
	seed = (seed * 7 + 13) % 1000000007;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> seed >> vmax;
	rep(i, 1, n) a[i] = get() % vmax + 1;
	
	rep(i, 1, n) mp[i] = a[i];
	mp[n+1] = -1;
	
	ll op, l, r, x, y;
	rep(i, 1, m){
		op = get() % 4 + 1;
		l = get() % n + 1, r = get() % n + 1;
		if(l > r) swap(l, r);
		
		if(op == 3) x = get() % (r-l+1) + 1;
		else x = get() % vmax + 1;
		if(op == 4) y = get() % vmax + 1;
		
		auto it = mp.upper_bound(l); it--;
		if(it->first != l) mp[l] = it->second;
		
		it = mp.upper_bound(r);
		if(it->first != r+1){
			it--;
			mp[r+1] = it->second;
		}
		
		if(op == 1){
			it = mp.lower_bound(l);
			for(;it != mp.end(); it++){
				if(it->first == r+1) break;
				it->second += x;
			}
		}
		if(op == 2){
			it = mp.lower_bound(l);
			for(;it != mp.end();){
				if(it->first == r+1) break;
				auto tmp = it; it++;
				mp.erase(tmp);
			}
			mp[l] = x;
		}
		if(op == 3){
			map<ll, ll> tmp;
			it = mp.lower_bound(l);
			for(;it != mp.end(); it++){
				if(it->first == r+1) break;
				auto nit = it; nit++;
				tmp[it->second] += nit->first - it->first;
			}
			for(auto z : tmp){
				x -= z.second;
				if(x <= 0){
					cout << z.first << "\n";
					break;
				}
			}
		}
		if(op == 4){
			ll ret = 0;
			it = mp.lower_bound(l);
			for(;it != mp.end(); it++){
				if(it->first == r+1) break;
				auto nit = it; nit++;
				ret += modpow(it->second%y, x, y) * (nit->first - it->first) % y, ret %= y;
			}
			cout << ret << "\n";
		}
	}
	flush(cout);
	
	return 0;
}