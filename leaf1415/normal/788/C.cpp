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
ll cnt[1005];
vector<ll> G[2005];
ll dist[2005];

void bfs(vector<llint> G[], int S, llint dist[])
{
	queue<int> Q;
	for(int i = 0; i <= 2000; i++) dist[i] = inf;
	for(auto v : G[S]) Q.push(v), dist[v] = 1;
	
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
	
	cin >> n >> k;
	ll x;
	rep(i, 1, k) cin >> x, cnt[x]++;
	
	if(cnt[n]){
		outl(1);
		return 0;
	}
	
	rep(i, 0, 1000){
		if(cnt[i] == 0) continue;
		rep(j, 0, 2000){
			ll v = j+i-n;
			if(v >= 0 && v <= 2000) G[j].push_back(v);
		}
	}
	bfs(G, 1000, dist);
	
	if(dist[1000] > inf/2) outl(-1);
	else outl(dist[1000]);
	
	return 0;
}