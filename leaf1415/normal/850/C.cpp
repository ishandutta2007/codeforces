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

ll n;
ll a[105];
bool prime[1000005];
map<ll, vector<ll> > mp;
int dp[1<<20];

inline int trans(int b, int x)
{
	return (b%(1<<x)) | (b>>(x+1));
}

int calc(int b)
{
	if(b < (1<<20)) return dp[b];
	
	ll h = -1;
	rep(j, 0, 30) if(b & (1<<j)) h = j;
	
	set<int> S;
	rep(j, 0, h) S.insert(calc(trans(b, j)));
	
	int ret = 0;
	while(S.count(ret)) ret++;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 2, 1000){
		if(prime[i]) continue;
		for(int j = 2*i; j < 1000005; j*=i) prime[j] = true;
	}
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	map<ll, ll> tmp;
	rep(i, 1, n){
		ll x = a[i]; tmp.clear();
		rep(j, 2, 40000){
			if(prime[j]) continue;
			while(x % j == 0){
				tmp[j]++;
				x /= j;
			}
		}
		if(x > 1) tmp[x]++;
		for(auto p : tmp) mp[p.first].push_back(p.second);;
	}
	
	ll N = 1<<20; set<int> S;
	rep(i, 0, N-1){
		ll h = -1;
		rep(j, 0, 19) if(i & (1<<j)) h = j;
		S.clear();
		rep(j, 0, h) S.insert(dp[trans(i, j)]);
		while(S.count(dp[i])) dp[i]++;
	}
	
	ll ans = 0;
	for(auto p : mp){
		ll b = 0;
		for(auto x : p.second) b |= 1<<(x-1);
		ans ^= calc(b);
	}
	
	if(ans == 0) cout << "Arpa" << endl;
	else cout << "Mojtaba" << endl;
	
	return 0;
}