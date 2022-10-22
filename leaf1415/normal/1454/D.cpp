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
ll n;
bool prime[100005];
vector<ll> pvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 2, 1005){
		if(prime[i]) continue;
		for(int j = 2*i; j < 100005; j+=i) prime[j] = true;
	}
	rep(i, 2, 100000) if(!prime[i]) pvec.push_back(i);
	
	cin >> T;
	while(T--){
		cin >> n;
		
		map<ll, ll> mp;
		for(auto p : pvec)
		{
			if(p > n) break;
			while(n % p == 0){
				mp[p]++;
				n /= p;
			}
		}
		if(n > 1) mp[n]++;
		
		ll len = 0;
		for(auto x : mp) chmax(len, x.second);
		vector<ll> ans(len);
		rep(i, 0, len-1) ans[i] = 1;
		
		for(auto x : mp){
			rep(i, 0, x.second-1){
				ans[i] *= x.first;
			}
		}
		reverse(all(ans));
		
		cout << ans.size() << endl;
		for(auto x : ans) cout << x << " "; cout << endl;
	}
	
	return 0;
}