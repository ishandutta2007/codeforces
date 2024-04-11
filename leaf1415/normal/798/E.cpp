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
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<P, llint> T;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

struct SegTree{
	int size;
	vector<P> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	P Ident(){  //identity element
		return P(-inf, -inf);
	}
	P ope(P a, P b){ //operator
		return max(a, b);
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = Ident();
	}
	
	void update(int i, P val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = ope(seg[i*2], seg[i*2+1]);
		}
	}

	P query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return Ident();
		if(a <= l && r <= b) return seg[k];
		P lval = query(a, b, k*2, l, (l+r)/2);
		P rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return ope(lval, rval);
	}
	P query(int a, int b)
	{
		if(a > b) return Ident();
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

ll n;
ll a[500005], b[500005];
SegTree seg(19);
bool used[500005];
ll ans[500005];
vector<ll> topo;

void dfs(int v)
{
	used[v] = true;
	seg.update(v, P(-inf, -inf));
	
	if(a[v] <= n && !used[a[v]]) dfs(a[v]);
	while(1){
		P res = seg.query(1, b[v]-1);
		if(res.first <= v) break;
		dfs(res.second);
	}
	topo.push_back(v);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n){
		cin >> a[i];
		if(a[i] == -1) a[i] = n+1;
	}
	rep(i, 1, n) b[a[i]] = i;
	rep(i, 1, n) if(b[i] == 0) b[i] = n+1;
	
	seg.init();
	rep(i, 1, n) seg.update(i, P(a[i], i));
	
	rep(i, 1, n) if(!used[i]) dfs(i);
	reverse(all(topo));
	reps(i, topo) ans[topo[i]] = i+1;
	
	rep(i, 1, n) cout << ans[i] << " "; cout << endl;
	
	return 0;
}