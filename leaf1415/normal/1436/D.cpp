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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n;
vector<llint> G[200005];
llint sum;
llint a[200005];

llint dfs(int v, llint x)
{
	if(G[v].size() == 0){
		if(x < a[v]) return -1;
		return min(sum+5, x - a[v]);
	}
	llint ret = 0;
	for(int i = 0; i < G[v].size(); i++){
		llint res = dfs(G[v][i], x);
		if(res == -1) return -1;
		ret += res;
		ret = min(ret, sum+5);
	}
	if(ret < a[v]) return -1;
	return min(sum+5, ret - a[v]);
}

bool check(llint x)
{
	return (dfs(1, x) >= 0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	llint p;
	for(int i = 2; i <= n; i++){
		cin >> p;
		G[p].push_back(i);
	}
	
	llint mx = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], chmax(mx, a[i]), sum += a[i];
	if(mx == 0){
		cout << 0 << endl;
		return 0;
	}
	
	llint ub = sum+5, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	
	return 0;
}