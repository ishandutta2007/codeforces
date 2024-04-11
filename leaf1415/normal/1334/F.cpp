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
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = 0;
	}
	
	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = (seg[i*2] + seg[i*2+1]);
		}
	}

	llint query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return 0;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return (lval + rval);
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint n, m;
llint a[500005], b[500005];
llint p[500005], s[500005];
vector<llint> vec[500005], evec;
llint dp[500005];
SegTree seg(19);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> p[i];
	cin >> m;
	for(int i = 1; i <= m; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++) vec[a[i]].push_back(i);
	vec[0].push_back(0);
	
	seg.init();
	for(int i = 1; i <= n; i++) seg.update(i, p[i]);
	
	for(int i = 1; i <= n; i++) dp[i] = inf;
	for(int i = 1; i <= m; i++){
		llint u = b[i-1], v = b[i];
		evec.clear();
		for(int j = 0; j < vec[u].size(); j++) evec.push_back(vec[u][j]);
		for(int j = 0; j < vec[v].size(); j++) evec.push_back(vec[v][j]);
		sort(evec.begin(), evec.end());
		
		llint mn = inf, pre = -1;
		for(int j = 0; j < evec.size(); j++){
			llint pos = evec[j];
			if(pos != -1) mn += seg.query(pre, pos-1);
			if(a[pos] == v) dp[pos] = mn;
			else mn = min(mn, dp[pos] - p[pos]);
			pre = pos;
		}
		for(int j = u+1; j <= v; j++){
			for(int k = 0; k < vec[j].size(); k++){
				if(p[vec[j][k]] > 0) seg.update(vec[j][k], 0), p[vec[j][k]] = 0;
			}
		}
	}
	
	llint ans = inf, x = b[m];
	for(int i = 0; i < vec[x].size(); i++){
		ans = min(ans, dp[vec[x][i]] + seg.query(vec[x][i]+1, n));
	}
	if(ans > inf/2) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		cout << ans << endl;
	}
	
	return 0;
}