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

struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){ to = a, cost = b;}
};

const ll mod = 1000000007;
//const ll mod = 998244353;

bool exceed(ll x, ll y, ll m){return x >= m / y + 1;}
void mark(){ cout << "*" << endl; }
void yes(){ cout << "Yes" << endl; }
void no(){ cout << "No" << endl; }
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}
ll modpow(ll a, ll n){
	if(n == 0) return 1;
	if(n % 2) return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	else return modpow((a*a)%mod, n/2) % mod;
}


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
ostream& operator << (ostream& os, const pair<T, U>& pair_var) {
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
template<typename T>
void outa(T a[], ll s, ll t)
{
	for(ll i = s; i <= t; i++){ cout << a[i]; if(i < t) cout << " ";}
	cout << endl;
}


ll n, m;
map<string, ll> mp;
P p[5005][1005];
P a[1005], b[1005];

P get(P A, P B, string ope)
{
	ll a = A.first, b = A.second, c = B.first, d = B.second;
	if(ope == "XOR") return P(a^c, b^d);
	if(ope == "AND") return P(a&c, (b&c) ^ (a&d) ^ (b&d));
	if(ope == "OR"){
		 P res = get(P(1^a, b), P(1^c, d), "AND");
		 res.first ^= 1;
		 return res;
	 }
}

void calc(ll to, P a[], P b[], string ope)
{
	rep(i, 0, m-1) p[to][i] = get(a[i], b[i], ope);
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	string s, ope;
	rep(i, 1, n){
		cin >> s;
		mp[s] = i;
		cin >> s >> s;
		if(s[0] == '0' || s[0] == '1'){
			rep(j, 0, m-1) p[i][j] = P(s[j]-'0', 0LL);
			continue;
		}
		if(s == "?") rep(j, 0, m-1) a[j] = P(0, 1);
		else{
			ll id = mp[s];
			rep(j, 0, m-1) a[j] = p[id][j];
		}
		cin >> ope;
		cin >> s;
		if(s == "?") rep(j, 0, m-1) b[j] = P(0, 1);
		else{
			ll id = mp[s];
			rep(j, 0, m-1) b[j] = p[id][j];
		}
		calc(i, a, b, ope);
	}

	string ans, ans2;
	rep(i, 0, m-1){
		ll cnt[2] = {};
		rep(j, 0, 1){
			rep(k, 1, n) cnt[j] += p[k][i].first ^ (p[k][i].second & j);
		}
		if(cnt[0] <= cnt[1]) ans += "0";
		else ans += "1";
		if(cnt[0] >= cnt[1]) ans2 += "0";
		else ans2 += "1";
	}
	outl(ans), outl(ans2);

	return 0;
}