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

int T;
int h, g;
int a[1<<21], b[1<<21];
vector<int> vec[1<<21];
bool used[1<<21];
vector<int> avec, uvec;

void dfs(int v, int d)
{
	vec[v].clear();
	if(d < h){
		dfs(v*2, d+1);
		dfs(v*2+1, d+1);
		
		int l = 0, r = 0;
		vector<int> &lvec = vec[v*2], &rvec = vec[v*2+1];
		while(l < lvec.size() || r < rvec.size()){
			if(l >= lvec.size()) vec[v].push_back(rvec[r++]);
			else if(r >= rvec.size()) vec[v].push_back(lvec[l++]);
			else if(lvec[l] < rvec[r]) vec[v].push_back(lvec[l++]);
			else vec[v].push_back(rvec[r++]);
		}
	}
	vec[v].insert(lower_bound(vec[v].begin(), vec[v].end(), a[v]), a[v]);
	
	//cout << a[v] << " : ";
	//for(int i = 0; i < vec[v].size(); i++) cout << vec[v][i] << " "; cout << endl;
	
	if(d <= g){
		llint m = max(b[v*2], b[v*2+1]);
		auto it = lower_bound(vec[v].begin(), vec[v].end(), m);
		b[v] = *it;
		used[*it] = true;
		uvec.push_back(*it);
		it++;
		vec[v].erase(vec[v].begin(), it);
	}
	//cout << b[v] << endl;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> g;
		int H = 1<<h;
		for(int i = 1; i < H; i++) cin >> a[i];
		
		for(int i = 1; i < H; i++) b[i] = 0;
		dfs(1, 1);
		
		llint ans = 0;
		avec.clear();
		for(int i = H-1; i >= 1; i--){
			if(used[a[i]]) ans += a[i];
			else avec.push_back(i);
		}
		for(int i = 0; i < uvec.size(); i++) used[uvec[i]] = false;
		uvec.clear();
		
		cout << ans << endl;
		for(int i = 0; i < avec.size(); i++) cout << avec[i] << " "; cout << endl;
	}
	
	return 0;
}