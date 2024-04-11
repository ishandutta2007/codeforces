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

ll n, m;
vector<ll> G[300005];
ll dif[300005], sum[300005];
ll dcnt[300005], lcnt[300005], tcnt[300005];
ll s[300005], t[300005];
map<P, ll> mp[300005];

const int VNUM = 300005, LOG_VNUM = 19;
int Prev[VNUM][LOG_VNUM];
int depth[VNUM];

void predfs(int v, int p, int d)
{
	depth[v] = d;
	Prev[v][0] = p;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		predfs(G[v][i], v, d+1);
	}
}

int getLCA(int u, int v){
	int x = u, y = v;
	if(depth[y] > depth[x]) swap(x, y);
	
	for(int i = LOG_VNUM-1; i >= 0; i--){
		if(depth[x] - (1<<i) >= depth[y]) x = Prev[x][i];
	}
	if(x == y) return x;
	for(int i = LOG_VNUM-1; i >= 0; i--){
		if(Prev[x][i] != Prev[y][i]){
			x = Prev[x][i];
			y = Prev[y][i];
		}
	}
	x = Prev[x][0];
	return x;
}
int getSub(int u, int v){
	if(u == v) return -1;
	
	ll d = depth[u] - depth[v] - 1;
	for(int i = LOG_VNUM-1; i >= 0; i--) if(d & (1<<i)) u = Prev[u][i];
	return u;
}

void sumdfs(int v)
{
	sum[v] = dif[v];
	for(auto u : G[v]){
		if(u == Prev[v][0]) continue;
		sumdfs(u);
		sum[v] += sum[u];
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	ll u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cin >> m;
	rep(i, 1, m) cin >> s[i] >> t[i];
	
	predfs(1, 0, 0);
	for(int i = 1; i < LOG_VNUM; i++){
		for(int j = 1; j <= n; j++){
			Prev[j][i] = Prev[Prev[j][i-1]][i-1];
		}
	}
	
	rep(i, 1, m){
		ll lca = getLCA(s[i], t[i]); lcnt[lca]++;
		if(lca != s[i]) tcnt[s[i]]++;
		if(lca != t[i]) tcnt[t[i]]++;
		ll S = getSub(s[i], lca), T = getSub(t[i], lca);
		//cout << s[i] << " " << t[i] << " " << lca << " " << S << " " << T << endl;
		if(S != -1) dcnt[S]++, dif[s[i]]++, dif[S]--;
		if(T != -1) dcnt[T]++, dif[t[i]]++, dif[T]--;
		if(S != -1 && T != -1){
			if(S > T) swap(S, T);
			mp[lca][P(S, T)]++;
		}
	}
	sumdfs(1);
	
	//rep(i, 1, n) cout << lcnt[i] << " " << tcnt[i] << " " << dcnt[i] << " " << sum[i] << endl;
	
	ll ans = 0;
	rep(i, 1, n){
		for(auto u : G[i]){
			if(u == Prev[i][0]) continue;
			ans += sum[u] * (lcnt[i] - dcnt[u]);
		}
		//cout << i << " " << ans << endl;
		ans += tcnt[i] * lcnt[i];
		//cout << i << " " << ans << endl;
	}
	
	//cout << ans << endl;
	
	rep(i, 1, n){
		ans += lcnt[i] * (lcnt[i]-1) / 2;
		for(auto u : G[i]){
			if(u == Prev[i][0]) continue;
			ans -= dcnt[u] * (dcnt[u]-1) / 2;
		}
		for(auto t : mp[i]) ans += t.second * (t.second-1) / 2;
		//cout << i << " " << ans << endl;
	}
	cout << ans << endl;
	
	return 0;
}