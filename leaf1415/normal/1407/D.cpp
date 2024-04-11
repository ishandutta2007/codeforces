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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
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
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint n;
llint h[300005];
vector<llint> comp;
llint dp[300005];
SegTree lseg(19), hseg(19);
set<llint> lset, hset;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> h[i];
		comp.push_back(h[i]);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int i = 1; i <= n; i++) h[i] = lower_bound(comp.begin(), comp.end(), h[i]) - comp.begin();
	
	lseg.init(), hseg.init();
	dp[1] = 0, lseg.update(h[1], 0), lset.insert(h[1]), lset.insert(300005);
	hseg.update(h[1], 0), hset.insert(h[1]), hset.insert(-1);
	for(int i = 2; i <= n; i++){
		
		//for(int j = 0; j <= 5; j++)  cout << lseg.query(j, j) << " "; cout << endl;
		
		auto it = lset.lower_bound(h[i]);
		dp[i] = lseg.query(0, *it) + 1;
		while(*lset.begin() <= h[i]){
			lseg.update(*lset.begin(), inf);
			lset.erase(lset.begin());
		}
		lset.insert(h[i]);
		
		it = hset.upper_bound(h[i]); it--;
		dp[i] = min(dp[i], hseg.query(max(0LL, *it), 300005) + 1);
		while(*hset.rbegin() >= h[i]){
			hseg.update(*hset.rbegin(), inf);
			auto it = hset.end(); it--;
			hset.erase(it);
		}
		hset.insert(h[i]);
		lseg.update(h[i], dp[i]);
		hseg.update(h[i], dp[i]);
	}
	//for(int i = 1; i <= n; i++) cout << dp[i] << " "; cout << endl;
	cout << dp[n] << endl;
	
	return 0;
}