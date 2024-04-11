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



ll h, w, n;
ll u[100005], l[100005], r[100005], s[100005];

struct SegTree{
	int size;
	vector<stack<ll>> seg;

	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}

	ll query(int i, llint y)
	{
		i += (1 << size);
		ll ret = 0;
		while(i >= 1){
			while(sz(seg[i]) && u[seg[i].top()] + s[seg[i].top()] < y) seg[i].pop();
			if(sz(seg[i])){
				ll id = seg[i].top();
				if(u[id]+s[id] >= y && u[ret] < u[id]) ret = id;
			}
			i /= 2;
		}
		return ret;
	}

	void push(int a, int b, int k, int l, int r, ll id)
	{
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			seg[k].push(id);
			return;
		}
		push(a, b, k*2, l, (l+r)/2, id);
		push(a, b, k*2+1, (l+r)/2+1, r, id);
	}
	void push(int a, int b, ll id)
	{
		push(a, b, 1, 0, (1<<size)-1, id);
	}
};


SegTree seg(17);
vector<P> vec;
map<P, ll> mp;

ll calc(ll p, ll y)
{
	ll res = seg.query(p, y), ret = 0;
	if(res == 0) return 1;
	ret = mp[P(l[res]-1, u[res])] + mp[P(r[res]+1, u[res])];
	if(l[res] == 1) ret += mp[P(r[res]+1, u[res])];
	if(r[res] == w) ret += mp[P(l[res]-1, u[res])];
	return ret % mod;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w >> n;
	rep(i, 1, n){
		cin >> u[i] >> l[i] >> r[i] >> s[i];
		vec.push_back(P(u[i], i));
	}
	sort(all(vec));

	l[0] = 1, r[0] = w, s[0] = inf;

	seg.push(1, w, 0);

	for(auto p : vec){
		ll id = p.second;
		if(l[id] > 1){
			mp[P(l[id]-1, u[id])] = calc(l[id]-1, u[id]);
			seg.push(l[id], r[id], id);
		}
		if(r[id] < w){
			mp[P(r[id]+1, u[id])] = calc(r[id]+1, u[id]);
			seg.push(l[id], r[id], id);
		}
	}

	ll ans = 0;
	rep(i, 1, w){
		ll res = seg.query(i, h+1);
		ans += calc(i, h+1), ans %= mod;
	}
	outl(ans);

	return 0;
}