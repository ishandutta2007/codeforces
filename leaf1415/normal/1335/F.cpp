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
typedef pair<int, int> P;

int T;
int h, w;
char b[1000005], c[1000005];
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int p[1000005];
vector<int> G[1000005];
bool cycle[1000005];
int used[1000005], length[1000005];
vector<int> vec;

void dfs(int v, int d, int len)
{
	used[v] = 1;
	if(b[v] == '0') vec.push_back(d%len);
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i]]) continue;
		dfs(G[v][i], d+1, len);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> w;
		for(int y = 0; y < h; y++){
			for(int x = 0; x < w; x++){
				cin >> b[y*w+x];
			}
		}
		for(int y = 0; y < h; y++){
			for(int x = 0; x < w; x++){
				llint v = y*w+x;
				cin >> c[v];
				if(c[v] == 'R') c[v] = '0';
				if(c[v] == 'U') c[v] = '1';
				if(c[v] == 'L') c[v] = '2';
				if(c[v] == 'D') c[v] = '3';
			}
		}
		
		for(int y = 0; y < h; y++){
			for(int x = 0; x < w; x++){
				llint nx = x, ny = y, dir = c[y*w+x]-'0';
				nx += dx[dir], ny += dy[dir];
				p[y*w+x] = ny*w+nx;
			}
		}
		
		int ans = 0, ans2 = 0, id = 0;
		for(int i = 0; i < h*w; i++) cycle[i] = false, used[i] = 0, length[i] = 0;
		for(int i = 0; i < h*w; i++){
			if(used[i]) continue;
			id++;
			int v = i;
			do{
				used[v] = id;
				v = p[v];
			}while(!used[v]);
			
			if(used[v] < id) continue;
			
			int s = v, len = 0;
			do{
				cycle[v] = true;
				v = p[v];
				len++;
			}while(v != s);
			length[s] = len;
			
			ans += len;
		}
		
		for(int i = 0; i < h*w; i++) G[i].clear();
		for(int i = 0; i < h*w; i++) G[p[i]].push_back(i);
		
		//for(int i = 0; i < h*w; i++) cout << length[i] << " "; cout << endl;
		
		for(int i = 0; i < h*w; i++) used[i] = 0;
		for(int i = 0; i < h*w; i++){
			if(length[i] == 0) continue;
			vec.clear();
			dfs(i, 0, length[i]);
			sort(vec.begin(), vec.end());
			vec.erase(unique(vec.begin(), vec.end()), vec.end());
			ans2 += vec.size();
		}
		cout << ans << " " << ans2 << "\n";
	}
	flush(cout);
	
	return 0;
}