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

llint n;
llint a[1005], b[1005];
vector<llint> vec;
vector<llint> G[1005];
llint x[1005];
set<llint> S;

void dfs(int v)
{
	for(auto u : G[v]){
		cout << x[v] << " " << x[u] << endl;
		dfs(u);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n-1) cin >> a[i] >> b[i];
	
	rep(i, 1, n-1){
		if(a[i] > b[i]) swap(a[i], b[i]);
		if(b[i] < n || a[i] >= n){
			cout << "NO" << endl;
			return 0;
		}
		vec.push_back(a[i]);
	}
	sort(all(vec));
	
	rep(i, 0, n-2){
		if(vec[i] < i+1){
			cout << "NO" << endl;
			return 0;
		}
	}
	reverse(all(vec));
	
	rep(i, 1, n-1) S.insert(i);
	rep(i, 0, n-2) S.erase(vec[i]);
	
	llint id = 2;
	x[1] = n;
	rep(i, 0, n-2){
		llint p = 1;
		if(i > 0 && vec[i-1] == vec[i]) p = id-1;
		if(i == n-1 || vec[i+1] != vec[i]) x[id] = vec[i];
		else{
			x[id] = *S.rbegin();
			auto it = S.end(); it--;
			S.erase(it);
		}
		G[p].push_back(id++);
	}
	
	cout << "YES" << endl;
	dfs(1);
	
	return 0;
}