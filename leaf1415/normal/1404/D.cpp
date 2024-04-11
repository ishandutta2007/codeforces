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
#define inf 1e9
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[500005];
map<llint, llint> mp;
vector<P> G[500005];

bool cand[1000005];
bool used[1000005];

void dfs(int v, int p)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		llint to = G[v][i].first, id = G[v][i].second;
		if(id == p) continue;
		cand[id] = true;
		if(!used[to]) dfs(to, mp[id]);
		break;
	}
}

int dfs2(int v, int p)
{
	int ret = 1;
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		llint to = G[v][i].first, id = G[v][i].second;
		if(id == p) continue;
		if(!used[to]) ret += dfs2(to, mp[id]);
		return ret;
	}
}

void dfs3(int v, int p)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		llint to = G[v][i].first, id = G[v][i].second;
		if(id == p) continue;
		cand[id] = false;
		cand[mp[id]] = true;
		if(!used[to]) dfs3(to, mp[id]);
		break;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	llint res;
	if(n%2 == 0){
		cout << "First" << endl;
		for(int i = 1; i <= n; i++) cout << i << " ";
		for(int i = 1; i <= n; i++) cout << i << " "; cout << endl;
		cin >> res;
		return 0;
	}
	
	cout << "Second" << endl;
	llint x;
	for(int i = 1; i <= 2*n; i++){
		cin >> x;
		if(a[x] == 0) a[x] = i;
		else{
			G[i%n].push_back(P(a[x]%n, a[x]));
			G[a[x]%n].push_back(P(i%n, i));
			mp[i] = a[x], mp[a[x]] = i;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(!used[i]) dfs(i, -1);
	}
	llint sum = 0;
	for(int i = 1; i <= 2*n; i++) if(cand[i]) sum += i;
	
	
	if(sum % (2*n)){
		for(int i = 0; i < n; i++) used[i] = false;
		for(int i = 0; i < n; i++){
			if(!used[i] && dfs2(i, -1)%2){
				for(int j = 0; j < n; j++) used[j] = false;
				dfs3(i, -1);
				break;
			}
		}
	}
	
	for(int i = 1; i <= 2*n; i++) if(cand[i]) cout << i << " ";
	cout << endl;
	cin >> res;
	
	return 0;
}