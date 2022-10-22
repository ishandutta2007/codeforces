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



ll h, w;
ll a[1505][1505], b[1505][1505];
vector<vector<ll> > atmp, btmp;
bool cut[1505], used[1505];
ll cnt[1505];
vector<ll> vec[1505];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	rep(y, 1, h) rep(x, 1, w) cin >> a[x][y];
	rep(y, 1, h) rep(x, 1, w) cin >> b[x][y];
	
	w++;
	rep(y, 1, h) a[w][y] = y, b[w][y] = y;
	
	atmp.resize(h);
	rep(i, 0, h-1) rep(x, 1, w) atmp[i].push_back(a[x][i+1]);
	btmp.resize(h);
	rep(i, 0, h-1) rep(x, 1, w) btmp[i].push_back(b[x][i+1]);
	sort(all(atmp)), sort(all(btmp));
	
	rep(i, 0, h-1){
		bool flag = true;
		rep(j, 0, w-2){
			if(atmp[i][j] != btmp[i][j]){
				flag = false;
				break;
			}
		}
		if(!flag){
			outl(-1);
			return 0;
		}
		b[w][btmp[i].back()] = atmp[i].back();
	}
	
	/*rep(y, 1, h){
		rep(x, 1, w) cout << a[x][y] << " "; cout << endl;
	}
	rep(y, 1, h){
		rep(x, 1, w) cout << b[x][y] << " "; cout << endl;
	}*/
	
	rep(x, 1, w){
		rep(y, 1, h-1){
			if(b[x][y] > b[x][y+1]) vec[y].push_back(x), cnt[x]++;
		}
	}
	
	vector<ll> ans;
	while(1){
		ll x = -1;
		rep(i, 1, w){
			if(used[i] || cnt[i]) continue;
			x = i;
			break;
		}
		if(x == -1) break;
		used[x] = true;
		
		if(x < w) ans.push_back(x);
		rep(y, 1, h-1){
			if(b[x][y] != b[x][y+1] && !cut[y]){
				cut[y] = true;
				for(auto p : vec[y]) cnt[p]--;
			}
		}
	}
	
	rep(i, 1, h-1) if(!cut[i]){
		outl(-1);
		return 0;
	}
	
	outl(sz(ans));
	reverse(all(ans));
	outl(ans);
	
	
	return 0;
}