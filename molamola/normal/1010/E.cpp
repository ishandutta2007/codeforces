#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;


#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 6,5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,_6,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define Debug1(a)           cout<<#a<<"="<<(a)<<"\n"
#define Debug2(a,b)         cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define Debug3(a,b,c)       cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define Debug4(a,b,c,d)     cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define Debug5(a,b,c,d,e)   cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define Debug6(a,b,c,d,e,f) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define Debug(...) macro_dispatcher(Debug, __VA_ARGS__)(__VA_ARGS__)
#define DA(a,n) cout<<#a<<"=["; printarray(a,n); cout<<"]\n"
#define DAR(a,n,s) cout<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cout<<"]\n"

#define TT1 template<class T>
#define TT1T2 template<class T1, class T2>
#define TT1T2T3 template<class T1, class T2, class T3>
template<class T, size_t N> ostream& operator << (ostream& os, const array<T, N>& v);
TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p){ return os <<"("<<p.first<<", "<< p.second<<")"; }
TT1 ostream& operator << (ostream& os, const vector<T>& v){       bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
template<class T, size_t N> ostream& operator << (ostream& os, const array<T, N>& v) {     bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const set<T1, T2>&v){    bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const multiset<T1,T2>&v){bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2T3 ostream& operator << (ostream& os, const map<T1,T2,T3>& v){ bool f = 1; os << "["; for (auto& ii : v) { if (!f)os << ", "; os << "(" << ii.first << " -> " << ii.second << ") "; f = 0; }return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const multimap<T1, T2>& v){ bool f = 1; os << "["; for (auto& ii : v) { if (!f)os << ", "; os << "(" << ii.first << " -> " << ii.second << ") "; f = 0; }return os << "]"; }
TT1T2 ostream& operator << (ostream& os, priority_queue<T1, T2> v) { bool f = 1; os << "["; while (!v.empty()) { auto x = v.top(); v.pop(); if (!f) os << ", "; f = 0; os << x; } return os << "]"; }
TT1T2 void printarray(const T1& a, T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }

int XL, YL, ZL;
int n, m, k;
pii sx, sy, sz;
t3 In[100010];

inline int seg_in(pii a, int b) { return a.Fi <= b && b <= a.Se; }
vector <t3> U[100010];	// (y, z, -1);
vector <t3> Q[100010];

vector <int> T[100010];
vector <int> vz[100010];
int L[100010];

void pre(int y, int z) {
	for(int i=y;i<=YL;i+=(i&-i)) {
		vz[i].pb(z);
	}
}

void update(int y, int z, int c) {
	for(int i=y;i<=YL;i+=(i&-i)) {
		int nz = (int)(lower_bound(all(vz[i]), z) - vz[i].begin() + 1);
		for(int j=nz;j<=L[i];j+=(j&-j)) T[i][j] += c;
	}
}

int read(int y, int z) {
	int res = 0;
	for(int i=y;i;i-=(i&-i)) {
		int nz = (int)(upper_bound(all(vz[i]), z) - vz[i].begin());
		for(int j=nz;j;j-=(j&-j)) res += T[i][j];
	}
	return res;
}

int ans[100010];	// open : -1, close = 1, un : 0

int main() {
	scanf("%d%d%d", &XL, &YL, &ZL);
	scanf("%d%d%d", &n, &m, &k);
	sx = sy = sz = pii(1e9, -1);
	for(int i=1;i<=n;i++) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		sx.Fi = min(sx.Fi, x);
		sx.Se = max(sx.Se, x);
		sy.Fi = min(sy.Fi, y);
		sy.Se = max(sy.Se, y);
		sz.Fi = min(sz.Fi, z);
		sz.Se = max(sz.Se, z);
	}
	for(int i=1;i<=m;i++) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		In[i] = t3(x, y, z);
		if(seg_in(sx, x) && seg_in(sy, y) && seg_in(sz, z)) {
			puts("INCORRECT");
			return 0;
		}
	}
	puts("CORRECT");
	for(int i=1;i<=m;i++) {
		int x, y, z;
		tie(x, y, z) = In[i];
		pii vx, vy, vz;
		if(x < sx.Fi) vx = pii(1, x);
		else if(seg_in(sx, x)) vx = pii(1, XL);
		else vx = pii(x, XL);
		if(y < sy.Fi) vy = pii(1, y);
		else if(seg_in(sy, y)) vy = pii(1, YL);
		else vy = pii(y, YL);
		if(z < sz.Fi) vz = pii(1, z);
		else if(seg_in(sz, z)) vz = pii(1, ZL);
		else vz = pii(z, ZL);
		for(int ax : {vx.Fi, vx.Se + 1}) {
			for(int ay : {vy.Fi, vy.Se + 1}) {
				for(int az : {vz.Fi, vz.Se + 1}) {
					int c = 1;
					if(ax != vx.Fi) c = -c;
					if(ay != vy.Fi) c = -c;
					if(az != vz.Fi) c = -c;
					U[ax].pb(t3(ay, az, c));
				}
			}
		}
	}
	
	for(int i=1;i<=k;i++) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		if(seg_in(sx, x) && seg_in(sy, y) && seg_in(sz, z)) {
			ans[i] = -1;
		}
		else Q[x].pb(t3(y, z, i));
	}
	
	for(int i=1;i<=XL;i++) {
		for(t3 e : U[i]) {
			int y, z, c;
			tie(y, z, c) = e;
			pre(y, z);
		}
	}
	for(int i=1;i<=YL;i++) {
		sort(all(vz[i]));
		vz[i].resize(unique(all(vz[i])) - vz[i].begin());
		L[i] = szz(vz[i]);
		T[i].resize(L[i] + 1);
	}
	
	for(int i=1;i<=XL;i++) {
		for(t3 e : U[i]) {
			int y, z, c;
			tie(y, z, c) = e;
			update(y, z, c);
		}
		
		for(t3 e : Q[i]) {
			int y, z, idx;
			tie(y, z, idx) = e;
			ans[idx] = read(y, z);
		}
	}
	
	for(int i=1;i<=k;i++) {
		if(ans[i] == -1) puts("OPEN");
		else if(ans[i] == 0) puts("UNKNOWN");
		else puts("CLOSED");
	}
	
	return 0;
}