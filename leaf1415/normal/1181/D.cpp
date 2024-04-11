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

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	llint query(int i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

llint n, m, Q;
llint a[500005], cnt[500005];
llint dist[500005], sum[500005];
llint k[500005];
llint ans[500005];
vector<llint> vec[500005];
vector<P> qvec[500005];
BIT bit(500005);

llint get(llint x)
{
	llint ub = 500000, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(bit.query(mid) >= x) ub = mid;
		else lb = mid;
	}
	return ub;
}

llint calc(llint x)
{
	llint ret = m*x;
	llint p = lower_bound(dist+1, dist+m+1, x) - dist;
	ret -= sum[p-1];
	ret -= (m-p+1)*x;
	ret += n;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> Q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cnt[a[i]]++;
	
	for(int i = 1; i <= m; i++) vec[cnt[i]].push_back(i);
	
	for(int i = 1; i <= m; i++) dist[i] = cnt[i];
	sort(dist+1, dist+m+1);
	for(int i = 1; i <= m; i++) sum[i] = sum[i-1] + dist[i];
	
	for(int i = 1; i <= Q; i++){
		cin >> k[i];
		llint ub = 2e18 / m, lb = 0, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(calc(mid) >= k[i]) ub = mid;
			else lb = mid;
		}
		if(ub > 500000) ans[i] = (k[i]-1)%m+1;
		else qvec[ub].push_back(P(k[i], i));
	}
	
	for(int i = 0; i <= 500000; i++){
		for(int j = 0; j < qvec[i].size(); j++){
			llint rem = qvec[i][j].first - calc(i-1), id = qvec[i][j].second;
			ans[id] = get(rem);
		}
		for(int j = 0; j < vec[i].size(); j++) bit.add(vec[i][j], 1);
	}
	
	for(int i = 1; i <= Q; i++) cout << ans[i] << "\n";
	flush(cout);
	
	return 0;
}