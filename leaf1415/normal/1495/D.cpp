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
#define sz(x) ((ll)(x).size())
#define ceil(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(...) dump_func(__VA_ARGS__)
#define inf 1e18
#define mod 998244353

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<ll, ll> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;}

template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for(int i = 0; i<vec.size(); i++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, pair<T, U>& pair_var) {
	os << "(" << pair_var.first << ", " << pair_var.second << ")";
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, map<T, U>& map_var) {
	for(typename map<T, U>::iterator itr = map_var.begin(); itr != map_var.end(); itr++) {
		os << "(" << itr->first << ", " << itr->second << ")";
		itr++;
		if(itr != map_var.end()) os << ",";
		itr--;
	}
	return os;
}
template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
	for(typename set<T>::iterator itr = set_var.begin(); itr != set_var.end(); itr++) {
		os << *itr;
		++itr;
		if(itr != set_var.end()) os << " ";
		itr--;
	}
	return os;
}
void dump_func() {cout << endl;}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    cout << head;
    if(sizeof...(Tail) > 0) cout << " ";
    dump_func(std::move(tail)...);
}



ll n, m;
vector<ll> G[405];
ll dist[405][405];
ll mul[405]; bool used[405];

void bfs(vector<llint> G[], int S, ll dist[])
{
	queue<int> Q;
	Q.push(S);
	
	for(int i = 1; i <= n; i++) dist[i] = inf;
	dist[S] = 0;
	
	while(Q.size()){
		int v = Q.front();
		Q.pop();
		for(int i = 0; i < G[v].size(); i++){
			if(dist[G[v][i]] < inf/2) continue;
			Q.push(G[v][i]);
			dist[G[v][i]] = dist[v] + 1;
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	ll u, v;
	rep(i, 1, m){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	rep(i, 1, n) bfs(G, i, dist[i]);
	
	rep(i, 1, n){
		rep(j, 1, n){
			
			rep(k, 1, n) used[k] = false;
			ll v = i;
			while(v != j){
				//outl(i, j, v);
				used[v] = true;
				for(auto u : G[v]){
					if(used[u]) continue;
					if(dist[i][v]+1 == dist[i][u] && dist[j][u]+1 == dist[j][v]){
						v = u;
						break;
					}
				}
			}
			used[j] = true;
			
			ll ans = 1;
			rep(k, 1, n){
				if(used[k]) continue;
				ll cnt = 0;
				for(auto u : G[k]){
					if(dist[i][u] + 1 == dist[i][k] && dist[j][u] + 1 == dist[j][k]) cnt++;
				}
				ans *= cnt, ans %= mod;
			}
			
			cout << ans << " ";
		}
		cout << endl;
	}
	
	
	return 0;
}