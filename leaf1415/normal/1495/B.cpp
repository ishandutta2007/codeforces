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
ll p[100005];
ll l[100005], r[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> p[i];
	
	ll cnt = 0;
	rep(i, 2, n){
		if(p[i-1] < p[i]) cnt++;
		else cnt = 0;
		l[i] = cnt;
	}
	cnt = 0;
	for(int i = n-1; i >= 1; i--){
		if(p[i+1] < p[i]) cnt++;
		else cnt = 0;
		r[i] = cnt;
	}
	
	ll mx = -1, pos;
	rep(i, 1, n){
		if(mx < l[i]) mx = l[i], pos = i;
		if(mx < r[i]) mx = r[i], pos = i;
	}
	
	//rep(i, 1, n) cout << l[i] << " "; cout << endl;
	//rep(i, 1, n) cout << r[i] << " "; cout << endl;
	//outl(mx, pos);
	
	rep(i, 1, n){
		if(pos != i && (l[i] == mx || r[i] == mx)){
			outl(0);
			return 0;
		}
	}
	if(l[pos] == 0 || r[pos] == 0){
		outl(0);
		return 0;
	}
	
	if(l[pos] == r[pos] && l[pos] % 2 == 0) outl(1);
	else outl(0);
	
	return 0;
}