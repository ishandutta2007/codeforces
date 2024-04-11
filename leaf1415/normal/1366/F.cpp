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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

struct edge{
	llint to, cost;
	edge(){}
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

llint n, m, Q;
llint dp[2005][2005];
vector<edge> G[2005];
vector<P> vec;
vector<E> evec;
llint r[2005];
map<llint, llint> mp;

llint get(llint a, llint b, llint c, llint d)
{
	llint ub = Q+1, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(a*mid+b >= c*mid+d) lb = mid;
		else ub = mid;
	}
	return lb;
}

llint calc(llint l, llint r, llint a, llint b)
{
	b = (b%mod+mod) % mod;
	llint ret = r*(r+1)/2 - l*(l-1)/2;
	ret %= mod;
	ret *= a, ret %= mod;
	ret += b * (r-l+1) % mod, ret %= mod;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> Q;
	llint u, v, w;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));
		evec.push_back(E(w, P(u, v)));
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = -inf;
		}
	}
	dp[0][1] = 0;
	
	for(int i = 0; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 0; k < G[j].size(); k++){
				llint u = G[j][k].to;
				chmax(dp[i+1][u], dp[i][j] + G[j][k].cost);
			}
		}
	}
	/*for(int i = 0; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	llint ans = 0;
	for(int i = 0; i <= min(Q, n); i++){
		llint mx = -inf;
		for(int j = 1; j <= n; j++){
			mx = max(mx, dp[i][j]);
		}
		ans += mx, ans %= mod;
	}
	//cout << ans << endl;

	
	for(int i = 0; i < evec.size(); i++){
		llint w = evec[i].first, u = evec[i].second.first, v = evec[i].second.second;
		llint mx = -inf;
		for(int j = 0; j <= n; j++){
			if(dp[j][u] < 0) continue;
			mx = max(mx, dp[j][u] - w * j);
		}
		for(int j = 0; j <= n; j++){
			if(dp[j][v] < 0) continue;
			mx = max(mx, dp[j][v] - w * j);
		}
		if(mp.count(w) == 0) mp[w] = -inf;
		mp[w] = max(mp[w], mx);
	}
	for(auto it = mp.begin(); it != mp.end(); it++) vec.push_back(P(it->first, it->second));
	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < vec.size(); i++){
		llint a = vec[i].first, b = vec[i].second;
		
		//cout << a << " " << b << endl;
		
		r[i] = Q;
		for(int j = i+1; j < vec.size(); j++){
			llint c = vec[j].first, d = vec[j].second;
			if(b <= d){
				r[i] = -1;
				continue;
			}
			//cout << a << " " << b << " " << c << " " << d << " " << get(a, b, c, d) << endl;
			r[i] = min(r[i], get(a, b, c, d));
		}
	}
	
	llint l = n+1;
	for(int i = 0; i < vec.size(); i++){
		//cout << l << " " << r[i] << " " << vec[i].first << " " << vec[i].second << endl;
		if(r[i] < l) continue;
		ans += calc(l, r[i], vec[i].first, vec[i].second);
		ans %= mod;
		l = r[i]+1;
	}
	cout << ans << endl;
	
	return 0;
}