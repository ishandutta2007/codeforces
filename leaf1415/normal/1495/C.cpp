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

ll T;
ll h, w;
char c[505][505];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
	
		cin >> h >> w;
		rep(y, 1, h) rep(x, 1, w) cin >> c[x][y];
		
		rep(y, 1, h) rep(x, 1, w) if(y % 3 == 1) c[x][y] = 'X';
		rep(y, 4, h){
			if(y % 3 != 1) continue;
			bool flag = false;
			rep(x, 1, w){
				if(c[x][y-2] == 'X'){
					c[x][y-1] = 'X', flag = true;
					break;
				}
				if(c[x][y-1] == 'X'){
					c[x][y-2] = 'X', flag = true;
					break;
				}
			}
			if(!flag) c[1][y-1] = c[1][y-2] = 'X';
		}
		
		if(h % 3 == 0){
			rep(x, 1, w) if(c[x][h] == 'X') c[x][h-1] = 'X';
		}
		
		rep(y, 1, h){
			rep(x, 1, w) cout << c[x][y];
			cout << "\n";
		}
	}
	flush(cout);
	
	return 0;
}