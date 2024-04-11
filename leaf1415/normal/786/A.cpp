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
typedef int ll;
typedef pair<short, short> P;
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


ll n;
vector<ll> vec[2];
ll deg[7005][2];
ll ans[7005][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	ll k, x;
	rep(i, 0, 1){
		cin >> k;
		rep(j, 1, k) cin >> x, vec[i].push_back(x);
		rep(j, 0, n-1) deg[j][i] = k;
	}
	
	queue<P> Q;
	ans[0][0] = ans[0][1] = -1;
	Q.push(P(0, 0)), Q.push(P(0, 1));
	
	while(sz(Q)){
		ll v = Q.front().first, d = Q.front().second;
		Q.pop();
		
		if(ans[v][d] < 0){
			for(auto x : vec[d^1]){
				ll nv = (v + n - x) % n, nd = d^1;
				if(ans[nv][nd]) continue;
				ans[nv][nd] = 1;
				Q.push(P(nv, nd));
			}
		}
		else{
			for(auto x : vec[d^1]){
				ll nv = (v + n - x) % n, nd = d^1;
				if(ans[nv][nd]) continue;
				deg[nv][nd]--;
				if(deg[nv][nd] == 0){
					ans[nv][nd] = -1;
					Q.push(P(nv, nd));
				}
			}
		}
	}
	
	rep(i, 0, 1){
		rep(j, 1, n-1){
			if(ans[j][i] > 0) cout << "Win" << " ";
			if(ans[j][i] == 0) cout << "Loop" << " ";
			if(ans[j][i] < 0) cout << "Lose" << " ";
		}
		cout << endl;
	}
	
	return 0;
}