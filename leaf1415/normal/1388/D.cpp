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

llint n;
llint a[200005], b[200005];
vector<llint> G[200005];
vector<llint> vec, vec2;
bool used[200005];

llint ans = 0;
llint dfs(int v)
{
	llint ret = a[v];
	for(int i = 0; i < G[v].size(); i++){
		ret += dfs(G[v][i]);
	}
	ans += ret;
	if(ret > 0) vec.push_back(v);
	else vec2.push_back(v);
	return max(ret, 0LL);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++){
		if(b[i] != -1){
			G[b[i]].push_back(i);
			used[i] = true;
		}
	}
	for(int i = 1; i <= n; i++){
		if(!used[i]) dfs(i);
	}
	cout << ans << endl;
	
	for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
	reverse(vec2.begin(), vec2.end());
	for(int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
	cout << endl;
	
	return 0;
}