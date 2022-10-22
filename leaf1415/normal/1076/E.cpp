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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
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

llint n, Q;
vector<llint> G[300005];
vector<P> vec[300005];
llint ans[300005];
BIT bit(300005);

void dfs(int v, int p, int dep)
{
	for(auto p : vec[v]){
		llint d = p.first, x = p.second;
		bit.add(dep, x);
		bit.add(min(300001LL, dep+d+1), -x);
	}
	
	ans[v] = bit.query(dep);
	for(auto u : G[v]){
		if(u == p) continue;
		dfs(u, v, dep+1);
	}
	
	for(auto p : vec[v]){
		llint d = p.first, x = p.second;
		bit.add(dep, -x);
		bit.add(min(300001LL, dep+d+1), x);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint x, y;
	rep(i, 1, n-1){
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	cin >> Q;
	llint v, d;
	rep(i, 1, Q){
		cin >> v >> d >> x;
		vec[v].push_back(P(d, x));
	}
	
	dfs(1, -1, 1);
	
	rep(i, 1, n) cout << ans[i] << " "; cout << endl;
	
	return 0;
}