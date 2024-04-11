//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>
#include <complex>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
//#define L __int128
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define a first
#define b second
#define fi first
#define sc second
//#define rng(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
#define pcnt(x) __builtin_popcountll(x)

#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif
 
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
 
template<class t> using vc=vector<t>;
 
template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.fi<<","<<p.sc<<"}";
}
 
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
 
 //https://codeforces.com/blog/entry/62393
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
	//don't make x negative!
	size_t operator()(pair<int,int> x)const{
		return operator()(uint64_t(x.first)<<32|x.second);
	}
};
//unordered_set -> dtype, null_type
//unordered_map -> dtype(key), dtype(value)
using namespace __gnu_pbds;
template<class t,class u>
using hash_table=gp_hash_table<t,u,custom_hash>;

template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 998244353;
//const ll mod = 1000000007;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
#define _sz 1
ll F[_sz],R[_sz];
void make(){
	F[0] = 1;
	for(int i=1;i<_sz;i++) F[i] = F[i-1]*i%mod;
	R[_sz-1] = modpow(F[_sz-1], mod-2);
	for(int i=_sz-2;i>=0;i--) R[i] = R[i+1] * (i+1) % mod;
}
ll C(int a,int b){
	if(b < 0 || a < b) return 0;
	return F[a]*R[b]%mod*R[a-b]%mod;
}
//o(ans?"Yes":"No");


template<typename F, typename T>
struct segtree{
	int sz;
	vector<T>seg;
	const F f;
	const T e;
	segtree(int n, const F f, const T e): f(f), e(e) {
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, e);
	}
	void init(int n){
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, e);
	}
	//mrg...apply f or not
	void update(int a, T p, bool mrg){
		a += sz-1;
		if(mrg) seg[a] = f(seg[a], p);
		else seg[a] = p;
		while(a){
			a = (a-1)/2;
			seg[a] = f(seg[a*2+1], seg[a*2+2]);
		}
	}
	void make(vector<T>a){
		rep(i, a.size()) seg[i+sz-1] = a[i];
		for(int i=sz-2;i>=0;i--) seg[i] = f(seg[i*2+1], seg[i*2+2]);
	}
	T query(int a, int b){
		a += sz-1, b += sz-1;
		T L = e, R = e;
		while(a <= b){
			if((a&1) == 0) { L = f(L, seg[a++]); }
			if((b&1) == 1) { R = f(seg[b--], R); }
			if(a > b) break;
			a = (a-1) >> 1;
			b = (b-1) >> 1;
		}
		return f(L, R);
	}
	int find_left(int a, int b, int k, int l, int r, T v){
		if(r < a || b < l) return INF;
		if(a <= l && r <= b){
			if(f(seg[k], v) == seg[k]){
				while(k < sz-1){
					if(f(seg[k*2+1], v) == seg[k*2+1]) k = k*2+1;
					else k = k*2+2;
				}
				return k - (sz-1);
			}
			return INF;
		}
		int ret = find_left(a, b, k*2+1, l, (l+r)/2, v);
		if(ret != INF) return ret;
		return find_left(a, b, k*2+2, 1+(l+r)/2, r, v);
	}
	//NOT VERIFIED
	int find_right(int a, int b, int k, int l, int r, T v){
		if(r < a || b < l) return -INF;
		if(a <= l && r <= b){
			if(f(seg[k], v) == seg[k]){
				while(k < sz-1){
					if(f(seg[k*2+2], v) == seg[k*2+2]) k = k*2+2;
					else k = k*2+1;
				}
				return k - (sz-1);
			}
			return -INF;
		}
		int ret = find_right(a, b, k*2+2, 1+(l+r)/2, r, v);
		if(ret != -INF) return ret;
		return find_right(a, b, k*2+1, l, (l+r)/2, v);
	}
	//[a, b]f(*, v)=** INF
	int find_left(int a, int b, T v){
		return find_left(a, b, 0, 0, sz-1, v);
	}
	//NOT VERIFIED
	//[a, b]f(*, v)=** -INF
	int find_right(int a, int b, T v){
		return find_right(a, b, 0, 0, sz-1, v);
	}
	
};
//
//f, e
auto f = [](P a, P b){ return max(a, b); };
P e = mp(-INF, -INF);
auto f2 = [](P a, P b){ return min(a, b); };
P e2 = mp(INF, INF);

void solve(){
	int n,a,b;cin>>n>>a>>b;
	a--; b--;
	
	segtree<decltype(f), decltype(e)>le(n, f, e);
	segtree<decltype(f2), decltype(e2)>ri(n, f2, e2);
	
	vc<int>p(n);
	rep(i, n){
		cin >> p[i];
		le.update(i, mp(i+p[i],i), false);
		ri.update(i, mp(i-p[i],i), false);
	}
	
	vc<int>dist(n, INF);
	dist[a] = 0;
	queue<int>que; que.push(a);
	
	
	while(!que.empty()){
		int pos = que.front(); que.pop();
		while(true){
			int LL = max(0LL, pos-p[pos]);
			int RR = pos-1;
			if(LL > RR) break;
			auto lq = le.query(LL, RR);
			if(lq.a < pos) break;
			int b = lq.b;
			le.update(b, e, false);
			if(dist[b] > dist[pos]+1){
				dist[b] = dist[pos] + 1;
				que.push(b);
			//	cout<<pos<<" "<<b<<" "<<"1 "<<endl;
			}
		}
		while(true){
			int LL = pos+1;
			int RR = min(n-1, pos+p[pos]);
			if(LL > RR) break;
			auto rq = ri.query(LL, RR);
			if(rq.a > pos) break;
			int b = rq.b;
			ri.update(b, e2, false);
			if(dist[b] > dist[pos]+1){
				dist[b] = dist[pos] + 1;
				que.push(b);
			//	cout<<pos<<" "<<b<<" "<<"2 "<<endl;
			}
		}
	}
	
	o(dist[b]);

}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}