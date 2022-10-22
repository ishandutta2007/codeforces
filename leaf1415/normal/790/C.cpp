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


ll n;
string s;
ll a[80], num[3];
ll dp[80][80][80][3];
vector<ll> vec[3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	s = "#" + s;
	rep(i, 1, n){
		if(s[i] == 'V') a[i] = 0;
		else if(s[i] == 'K') a[i] = 1;
		else a[i] = 2;
		vec[a[i]].push_back(i);
	}
	rep(i, 0, 2) num[i] = sz(vec[i]);
	
	rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) rep(l, 0, 2) dp[i][j][k][l] = inf;
	dp[0][0][0][1] = 0;
	
	rep(i, 0, n-1){
		rep(j, 0, num[0]){
			rep(k, 0, num[1]){
				if(i < j+k) continue;
				ll c[3] = {j, k, i-(j+k)};
				if(c[2] > num[2]) continue;
				rep(l, 0, 2){
					rep(m, 0, 2){
						if(l == 0 && m == 1) continue;
						if(c[m] >= num[m]) continue;
						
						ll cost = 0;
						rep(p, 1, vec[m][c[m]]-1){
							ll x = a[p];
							if(c[x] > 0 && p <= vec[x][c[x]-1]) continue;
							cost++;
						}
						if(m == 0) chmin(dp[i+1][j+1][k][m], dp[i][j][k][l] + cost);
						if(m == 1) chmin(dp[i+1][j][k+1][m], dp[i][j][k][l] + cost);
						if(m == 2) chmin(dp[i+1][j][k][m], dp[i][j][k][l] + cost);
					}
				}
			}
		}
	}
	
	ll ans = inf;
	rep(i, 0, 2) chmin(ans, dp[n][num[0]][num[1]][i]);
	outl(ans);
	
	return 0;
}