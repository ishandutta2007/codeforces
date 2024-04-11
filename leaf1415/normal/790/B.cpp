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

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<ll, ll> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;}

struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){
		to = a, cost = b;
	}
};

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


ll n, k;
vector<ll> G[200005];
ll num[200005][5], sum[200005][5];

ll ans = 0;
void dfs(int v, int p)
{
	for(auto u : G[v]){
		if(u == p) continue;
		dfs(u, v);
		rep(i, 0, k-1) rep(j, 0, k-1){
			ans += sum[v][i] * num[u][j];
			ans += sum[u][j] * num[v][i];
			ans += ceil(i+j+2, k) * num[v][i] * num[u][j];
		}
		rep(i, 0, k-1) ans += sum[u][i], ans += ceil(i+1, k) * num[u][i];
		rep(i, 0, k-1) num[v][i] += num[u][i], sum[v][i] += sum[u][i];
	}
	//outl(v, ans);
	
	ll tmp = num[v][k-1];
	for(int i = k-1; i >= 1; i--) num[v][i] = num[v][i-1];
	num[v][0] = tmp;
	
	tmp = sum[v][k-1];
	for(int i = k-1; i >= 1; i--) sum[v][i] = sum[v][i-1];
	sum[v][0] = tmp;
	
	sum[v][0] += num[v][0];
	num[v][0]++;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	ll u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, -1);
	
	/*rep(i, 1, n){
		rep(j, 0, k-1) cout << sum[i][j] << " "; cout << endl;
	}*/
	
	outl(ans);
	
	return 0;
}