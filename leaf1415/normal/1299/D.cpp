#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#define llint long long
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

struct edge{
	llint to, cost;
	edge(){}
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

llint n, m;
vector<edge> G[100005];
bool used[100005];
bool skip[100005];

llint val[100005];
vector<llint> vec[100005];
llint cycle[100005];

vector<llint> svec;
vector<P> pvec;
map<llint, llint> mp;
llint sum[405][405];
llint dp[100005][405];

void dfs(llint v, llint p, llint id, llint x)
{
	//cout << v << " " << id << " " << x << endl;
	used[v] = true, val[v] = x;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == p) continue;
		llint u = G[v][i].to;
		if(used[u]){
			if(u > v) continue;
			llint t = val[v]^val[u]^G[v][i].cost;
			//cout << t << endl;
			if(u == 1) cycle[id] = t;
			else vec[id].push_back(t);
		}
		else dfs(u, v, id, x^G[v][i].cost);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v, w;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));
	}
	used[1] = true;
	
	llint d = G[1].size();
	for(int i = 0; i < d; i++){
		cycle[i] = -1;
		if(used[G[1][i].to]){
			skip[i] = true;
			continue;
		}
		dfs(G[1][i].to, 1, i, G[1][i].cost);
	}
	
	/*cout << endl;
	for(int i = 0; i < d; i++){
		for(int j = 0; j < vec[i].size(); j++) cout << vec[i][j] << " "; cout << endl;
	}*/
	
	for(int i = 1; i <= 5; i++){
		llint N = 1<<i, comb = (1<<i)-1;
		while(comb < (1LL<<32)){
			
			vector<llint> tmp;
			for(int j = 0; j < 32; j++){
				if(comb & (1LL<<j)) tmp.push_back(j);
			}
			llint mask = 0;
			for(int j = 1; j < N; j++){
				llint x = 0;
				for(int k = 0; k < i; k++){
					if(j & (1<<k)) x ^= tmp[k];
				}
				mask |= 1LL<<x;
			}
			if((mask & 1) == 0) svec.push_back(mask);
			
			llint x = comb & -comb, y = comb + x;
			comb = ((comb & ~y) / x >> 1) | y;
		}
	}
	svec.push_back(0);
	sort(svec.begin(), svec.end());
	svec.erase(unique(svec.begin(), svec.end()), svec.end());
	llint s = svec.size();
	for(int i = 0; i < s; i++) mp[svec[i]] = i;
	
	for(int i = 0; i < s; i++){
		for(int j = 0; j < s; j++){
			if(svec[i] & svec[j]){
				sum[i][j] = -1;
				continue;
			}
			llint mask = svec[i] | svec[j];
			for(int k = 0; k < 32; k++){
				for(int l = 0; l < 32; l++){
					if((svec[i]&(1LL<<k)) && (svec[j]&(1LL<<l))) mask |= 1LL<<(k^l);
				}
			}
			if(mp.count(mask) == 0) sum[i][j] = -1;
			else sum[i][j] = mp[mask];
		}
	}
	
	for(int i = 0; i < d; i++){
		llint num = vec[i].size();
		if(skip[i]) continue;
		if(num == 0){
			pvec.push_back(P(0LL, cycle[i]));
			continue;
		}
		if(num >= 6){
			pvec.push_back(P(-1, cycle[i]));
			continue;
		}
		//cout << num << endl;
		llint N = 1 << num;
		llint mask = 0;
		for(int j = 1; j < N; j++){
			llint x = 0;
			for(int k = 0; k < num; k++){
				if(j & (1<<k)) x ^= vec[i][k];
			}
			mask |= 1LL<<x;
		}
		
		if(mp.count(mask) == 0) pvec.push_back(P(-1, cycle[i]));
		else pvec.push_back(P(mp[mask], cycle[i]));
	}
	d = pvec.size();
	
	//for(int i = 0; i < d; i++) cout << pvec[i].first << " " << pvec[i].second << endl;
	
	dp[0][0] = 1;
	for(int i = 0; i < d; i++){
		for(int j = 0; j < s; j++){
			llint space = pvec[i].first, cycle = pvec[i].second;
			dp[i+1][j] += dp[i][j], dp[i+1][j] %= mod;
			if(space == -1) continue;
			if(cycle == -1){
				if(sum[j][space] != -1) (dp[i+1][sum[j][space]] += dp[i][j]) %= mod;
			}
			else{
				if(sum[j][space] != -1) (dp[i+1][sum[j][space]] += dp[i][j]*2%mod) %= mod;
				if(cycle != 0){
					cycle = mp[1LL<<cycle];
					space = sum[space][cycle];
					if(space != -1 && sum[j][space] != -1) (dp[i+1][sum[j][space]] += dp[i][j]) %= mod;
				}
			}
		}
	}
	
	llint ans = 0;
	for(int j = 0; j < s; j++) ans += dp[d][j], ans %= mod;
	cout << ans << endl;
	
	return 0;
}