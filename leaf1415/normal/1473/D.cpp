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
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

struct SegTree{
	int size;
	vector<llint> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	llint Ident(){  //identity element
		return inf;
	}
	llint ope(llint a, llint b){ //operator
		return min(a, b);
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = Ident();
	}
	
	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = ope(seg[i*2], seg[i*2+1]);
		}
	}

	llint query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return Ident();
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return ope(lval, rval);
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

struct SegTree2{
	int size;
	vector<llint> seg;
	
	SegTree2(){}
	SegTree2(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	llint Ident(){  //identity element
		return -inf;
	}
	llint ope(llint a, llint b){ //operator
		return max(a, b);
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = Ident();
	}
	
	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = ope(seg[i*2], seg[i*2+1]);
		}
	}

	llint query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return Ident();
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return ope(lval, rval);
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

ll T;
ll n, m;
ll sum[200005];
SegTree mseg(18);
SegTree2 Mseg(18);
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	mseg.init(), Mseg.init();
	
	cin >> T;
	while(T--){
		cin >> n >> m;
		cin >> s;
		s = "#" + s;
		
		rep(i, 1, n){
			sum[i] = sum[i-1];
			if(s[i] == '+') sum[i]++;
			else sum[i]--;
		}
		
		rep(i, 0, n) mseg.update(i, sum[i]);
		rep(i, 0, n) Mseg.update(i, sum[i]);
		
		ll l, r;
		rep(i, 1, m){
			cin >> l >> r;
			ll u = Mseg.query(0, l-1), d = mseg.query(0, l-1);
			ll b = sum[r]-sum[l-1];
			chmax(u, Mseg.query(r, n)-b), chmin(d, mseg.query(r, n)-b);
			cout << u - d + 1 << "\n";
		}
	}
	flush(cout);
	
	return 0;
}