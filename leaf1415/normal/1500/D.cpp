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
#include <unordered_map>
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


ll n, q;
ll a[1505][1505];
vector<P> vec[1505][2];
ll dx[] = {1, 1, 0}, dy[] = {0, 1, 1};
ll dif[1505];

ll val[3000005];
vector<ll> tmp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	rep(y, 1, n) rep(x, 1, n) cin >> a[x][y];
	q++;
	
	rep(i, 1, n*n) val[i] = 1e9;
	
	for(int y = n; y >= 1; y--){
		for(int x = n; x >= 1; x--){
			
			tmp.clear();
			chmin(val[a[x][y]], 0LL), tmp.push_back(a[x][y]);
			rep(i, 0, 2){
				ll nx = x + dx[i], ny = y + dy[i];
				//outl(nx, ny);
				if(nx > n || ny > n) continue;
				for(auto p : vec[nx][ny&1]){
					//outl(x, y, i, p);
					chmin(val[p.second], p.first+1), tmp.push_back(p.second);
				}
			}
			sort(all(tmp));
			tmp.erase(unique(all(tmp)), tmp.end());
			
			vec[x][y&1].clear();
			for(auto p : tmp) vec[x][y&1].push_back(P(val[p], p)), val[p] = 1e9;
			sort(all(vec[x][y&1]));
			if(sz(vec[x][y&1]) > q) vec[x][y&1].resize(q);
			
			/*vec.clear();
			for(auto p : mp[x][y]) vec.push_back(P(p.second, p.first));
			sort(all(vec));*/
			
			ll l = min(n-x, n-y);
			if(sz(vec[x][y&1]) >= q) chmin(l, vec[x][y&1][q-1].first-1);
			l++;
			dif[1]++, dif[l+1]--;
		}
	}
	
	/*outl(mp[1][1]);
	outl(mp[1][2]);
	outl(mp[2][1]);
	outl(mp[2][2]);
	outl(mp[3][3]);
	outl(mp[4][4]);*/
	
	rep(i, 1, n) dif[i] += dif[i-1];
	rep(i, 1, n) outl(dif[i]);
	
	return 0;
}