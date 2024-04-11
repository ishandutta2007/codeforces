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


ll T;
ll H, M;
string s;
ll a[] = {3, 4, 6, 7, 9};
map<ll, ll> mp;

ll get(char c)
{
	return c - '0';
}

bool check(ll h, ll m)
{
	rep(i, 0, 4) if(h%10 == a[i] || h/10 == a[i]) return false;
	rep(i, 0, 4) if(m%10 == a[i] || m/10 == a[i]) return false;
	
	if(mp[m%10] * 10 + mp[m/10] >= H) return false;
	if(mp[h%10] * 10 + mp[h/10] >= M) return false;
	
	return true;
}

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	mp[0] = 0, mp[1] = 1, mp[2] = 5, mp[5] = 2, mp[8] = 8;
	
	cin >> T;
	while(T--){
		cin >> H >> M;
		cin >> s;
		int h = get(s[0])*10 + get(s[1]), m = get(s[3])*10 + get(s[4]);
		
		while(!check(h, m)){
			m++;
			if(m >= M) h++, m = 0;
			if(h >= H) h = 0;
		}
		printf("%02d:%02d\n", h, m);
	}
	
	return 0;
}