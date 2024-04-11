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
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;


// range-add, range-min query
 
struct LazySegTree{
	int size;
	vector<llint> seg, delay;
	
	LazySegTree(){}
	LazySegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	llint Ident(){ //identity element
		return 0;
	}
	llint ope(llint a, llint b){ //operator
		return (a + b);
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++){
			seg[i] = Ident();
			delay[i] = 0; //
		}
	}
	
	void eval(int l, int r, int k) //
	{
		if(delay[k]){
			seg[k] = 0;  //
			if(l < r){
				delay[k*2] += delay[k];
				delay[k*2+1] += delay[k];
			}
			delay[k] = 0;
		}
	}
	
	void update(int i, llint val)
	{
		int l = 0, r = (1<<size)-1, k = 1;
		
		eval(l, r, k);
		for(int j = size-1; j >= 0; j--){
			k <<= 1;
			if(i & (1<<j)){
				k++;
				l = (l+r)/2+1;
			}
			else r = (l+r)/2;
			eval(l, r, k);
		}
		
		seg[i+(1<<size)] = val;
		
		l = i, r = i, k = i+(1<<size);
		for(int j = 0; j < size; j++){
			k /= 2, l &= ~(1<<j), r |= 1<<j;
			eval(l, (l+r)/2, k*2), eval((l+r)/2+1, r, k*2+1);
			seg[k] = ope(seg[k*2], seg[k*2+1]);
		}
	}
	
	void add(int a, int b, int k, int l, int r, llint val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			delay[k] += val; //
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		seg[k] = ope(seg[k*2], seg[k*2+1]);
	}
	void add(int a, int b, llint val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}
 
	llint query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return Ident();
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return ope(lval, rval);
	}
	llint query(int a, int b)
	{
		if(a > b) return Ident();
		return query(a, b, 1, 0, (1<<size)-1);
	}
};


ll n, m;
ll l[200005], r[200005], rcnt[200005];
vector<ll> vec[200005];
LazySegTree sseg[2], nseg[2];
multiset<ll> S[2];
ll dif[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n >> m;
	rep(i, 1, n){
		cin >> l[i] >> r[i];
		dif[l[i]]++, dif[r[i]+1]--;
		l[i]--;
		vec[l[i]].push_back(r[i]);
		rcnt[r[i]]++;
	}
	
	rep(i, 0, 1){
		sseg[i] = LazySegTree(18), sseg[i].init();
		nseg[i] = LazySegTree(18), nseg[i].init();
	}
	rep(i, 0, m) sseg[i%2].update(i, i), nseg[i%2].update(i, 1);
	
	ll ans = 0;
	for(ll i = m; i >= 0; i--){
		for(auto r : vec[i]){
			sseg[i%2].add(i+1, r, 1), nseg[i%2].add(i+1, r, 1);
			if((r-i)%2 == 0){
				sseg[0].add(r+1, m, 1), sseg[1].add(r+1, m, 1);
				nseg[0].add(r+1, m, 1), nseg[1].add(r+1, m, 1);
			}
			S[r%2].erase(S[r%2].lower_bound(r));
		}
		
		ll lb = i, ub = m;
		rep(j, 0, 1) if(S[j].size()) chmax(lb, *S[j].rbegin());
		if(S[i%2].size()) chmin(ub, *S[i%2].begin());
		
		ans += sseg[i%2].query(lb+1, ub);
		ans += sseg[(i+1)%2].query(i+1, ub);
		
		ans -= i * nseg[i%2].query(lb+1, ub);
		ans -= i * nseg[(i+1)%2].query(i+1, ub);
		
		rep(j, 1, rcnt[i]) S[i%2].insert(i);
		
		//for(int j = 0; j <= m; j++) cout << max(sseg[0].query(j, j), sseg[1].query(j, j)) << " "; cout << endl;
		//cout << i << " " << lb << " " << ans << endl;
	}
	
	rep(i, 1, m) dif[i] += dif[i-1];
	dif[m+1] = 1;
	
	ll cnt = 0;
	rep(i, 1, m+1){
		if(dif[i]) ans -= (cnt+1)*cnt*(cnt+1)/2 - cnt*(cnt+1)*(2*cnt+1)/6, cnt = 0;
		else cnt++;
	}
	
	cout << ans << endl;
	
	return 0;
}