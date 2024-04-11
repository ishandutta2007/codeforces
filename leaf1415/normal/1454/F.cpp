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
#define inf 1e9+7

using namespace std;

typedef int llint;
typedef int ll;
typedef pair<llint, llint> P;

struct SegTree{
	int size;
	vector<llint> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = inf;
	}
	
	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = min(seg[i*2], seg[i*2+1]);
		}
	}

	llint query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return inf;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return min(lval, rval);
	}
	llint query(int a, int b)
	{
		if(a > b) return inf;
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

ll T;
ll n;
int a[200005], mx[200005];
SegTree seg(18);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	seg.init();
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) seg.update(i, a[i]);
		seg.update(n+1, inf);
		
		mx[n+1] = -inf;
		for(int i = n; i >= 1; i--){
			mx[i] = max(mx[i+1], a[i]);
		}
		
		ll pmx = 0;
		rep(i, 1, n-2){
			chmax(pmx, a[i]);
			int ub = n-i, lb = 1, mid;
			while(ub-lb>1){
				mid = (ub+lb)/2;
				if(seg.query(i+1, i+mid) >= pmx) lb = mid;
				else ub = mid;
			}
			if(seg.query(i+1, i+lb) != pmx) continue;
			if(seg.query(i+1, i+lb) == mx[i+lb+1] && mx[i+lb+1] == pmx){
				cout << "YES" << endl;
				cout << i << " " << lb << " " << n-(i+lb) << endl;
				goto end;
			}
			if(lb >= 2){
				lb--;
				if(seg.query(i+1, i+lb) == mx[i+lb+1] && mx[i+lb+1] == pmx){
					cout << "YES" << endl;
					cout << i << " " << lb << " " << n-(i+lb) << endl;
					goto end;
				}
			}
			
		}
		cout << "NO" << endl;
		end:;
	}
	
	return 0;
}