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
#define mod 1000000007

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


llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

int n, Q;
int a[200005];
map<int, int> mp[200005];
multiset<int> S[200005];
int prime[200005];

void factor(int x, map<int, int> &mp)
{
	mp.clear();
	while(prime[x]){
		mp[prime[x]]++;
		x /= prime[x];
	}
	if(x > 1) mp[x]++;
}

ll get(ll i)
{
	if(sz(S[i]) < n) return 1;
	return modpow(i, *S[i].begin());
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	rep(i, 2, 200000){
		if(prime[i]) continue;
		for(int j = 2*i; j <= 200000; j+=i) prime[j] = i;
	}
	
	cin >> n >> Q;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 1, n){
		factor(a[i], mp[i]);
		for(auto p : mp[i]) S[p.first].insert(p.second);
	}
	
	ll ans = 1;
	rep(i, 1, 200000) ans *= get(i), ans %= mod;
	
	int pos, x;
	rep(q, 1, Q){
		cin >> pos >> x;
		map<int, int> tmp;
		factor(x, tmp);
		
		for(auto z : tmp){
			ll p = z.first, e = z.second;
			ans *= modpow(get(p), mod-2), ans %= mod;
			if(S[p].count(mp[pos][p])) S[p].erase(S[p].lower_bound(mp[pos][p]));
			mp[pos][p] += e;
			S[p].insert(mp[pos][p]);
			ans *= get(p), ans %= mod;
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}