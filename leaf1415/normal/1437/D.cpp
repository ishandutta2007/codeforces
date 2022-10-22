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

llint T;
llint n;
llint a[200005];
vector<llint> G[200005];

llint dfs(int v)
{
	llint ret = 0;
	for(int i = 0; i < G[v].size(); i++){
		ret = max(ret, 1+dfs(G[v][i]));
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i], G[i].clear();
		
		queue<llint> Q, R;
		Q.push(1);
		for(int i = 2; i <= n; i++) R.push(a[i]);
		
		llint pre, v;
		while(Q.size()){
			pre = 0;
			v = Q.front();
			Q.pop();
			while(R.size() && R.front() > pre){
				G[v].push_back(R.front());
				Q.push(R.front());
				pre = R.front();
				R.pop();
			}
		}
		cout << dfs(1) << endl;
	}
	
	return 0;
}