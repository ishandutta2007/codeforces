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
ll n, k;
string s;
ll cnt[26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> k >> s;
		assert(sz(s) == n);
		if(n % k){
			outl(-1);
			continue;
		}
		
		rep(i, 0, 25) cnt[i] = 0;
		
		P ans = P(inf, inf);
		rep(i, 0, n-1){
			ll c = s[i]-'a';
			rep(j, c+1, 25){
				cnt[j]++;
				ll sum = 0;
				rep(l, 0, 25) sum += (k-cnt[l]%k) % k;
				if(sum + i+1 <= n) chmin(ans, P(-i, j));
				cnt[j]--;
			}
			cnt[c]++;
		}
		
		bool flag = true;
		rep(i, 0, 25) if(cnt[i]%k) flag = false;
		if(flag){
			outl(s);
			continue;
		}
		
		if(ans > P(inf/2, inf/2)){
			outl(-1);
			continue;
		}
		
		string t = s.substr(0, -ans.first);
		t += ans.second + 'a';
		
		string u;
		rep(i, 0, 25) cnt[i] = 0;
		for(auto c : t) cnt[c-'a']++;
		rep(i, 0, 25) rep(j, 1, (k-cnt[i]%k)%k) u += i + 'a';
		
		while(sz(t) + sz(u) < n) u += 'a';
		sort(all(u));
		t += u;
		
		rep(i, 0, 25) cnt[i] = 0;
		for(auto c : t) cnt[c-'a']++;
		rep(i, 0, 25) assert(cnt[i]%k == 0);
		
		outl(t);
	}
	
	return 0;
}