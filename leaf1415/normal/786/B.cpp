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

struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){
		to = a, cost = b;
	}
};

ll n, Q, s;
vector<edge> G[1<<19];
ll A = 1<<17, B = 1<<18;
ll dist[1<<19];

void query(int a, int b, int k, int l, int r, ll s, ll w)
{
	if(b < l || r < a) return;
	if(a <= l && r <= b){
		G[A+s].push_back(edge(k, w));
		return;
	}
	query(a, b, k*2, l, (l+r)/2, s, w);
	query(a, b, k*2+1, (l+r)/2+1, r, s, w);
}
void query(int a, int b, ll s, ll w)
{
	return query(a, b, 1, 0, (1<<17)-1, s, w);
}

void query2(int a, int b, int k, int l, int r, ll s, ll w)
{
	if(b < l || r < a) return;
	if(a <= l && r <= b){
		G[B+k].push_back(edge(B+A+s, w));
		return;
	}
	query2(a, b, k*2, l, (l+r)/2, s, w);
	query2(a, b, k*2+1, (l+r)/2+1, r, s, w);
}
void query2(int a, int b, ll s, ll w)
{
	return query2(a, b, 1, 0, (1<<17)-1, s, w);
}

void dijkstra(vector<edge> G[], llint S, llint dist[])
{
	for(int i = 0; i < (1<<19); i++) dist[i] = inf;
	dist[S] = 0;
	
	priority_queue< P, vector<P>, greater<P> > Q;
	Q.push( make_pair(0, S) );
	
	llint v, d;
	while(Q.size()){
		d = Q.top().first;
		v = Q.top().second;
		Q.pop();
		if(dist[v] < d) continue;
		for(int i = 0; i < G[v].size(); i++){
			if(dist[G[v][i].to] > d + G[v][i].cost){
				dist[G[v][i].to] = d + G[v][i].cost;
				Q.push( make_pair(dist[G[v][i].to], G[v][i].to) );
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q >> s;
	
	rep(i, 1, n) G[A+i].push_back(edge(B+A+i, 0)), G[B+A+i].push_back(edge(A+i, 0));
	rep(i, 1, (1<<17)-1){
		G[i].push_back(edge(i*2, 0)), G[i].push_back(edge(i*2+1, 0));
		G[B+i*2].push_back(edge(B+i, 0)), G[B+i*2+1].push_back(edge(B+i, 0));
	}
	
	ll t, u, v, l, r, w;
	rep(i, 1, Q){
		cin >> t;
		if(t == 1){
			cin >> u >> v >> w;
			G[A+u].push_back(edge(A+v, w));
		}
		if(t == 2){
			cin >> u >> l >> r >> w;
			query(l, r, u, w);
		}
		if(t == 3){
			cin >> u >> l >> r >> w;
			query2(l, r, u, w);
		}
	}
	
	dijkstra(G, A+s, dist);
	
	rep(i, 1, n){
		if(dist[A+i] > inf/2) cout << -1 << " ";
		else cout << dist[A+i] << " ";
	}
	cout << endl;
	
	
	return 0;
}