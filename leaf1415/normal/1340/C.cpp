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

int n, m;
int d[10005];
int g, r;
int dist[10005][1005];

void bfs()
{
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < g; j++){
			dist[i][j] = 1e9;
		}
	}
	dist[1][0] = 0;
	
	deque<P> deq;
	deq.push_back(P(1, 0));
	
	while(deq.size()){
		int p = deq.front().first, t = deq.front().second;
		//cout << p << " " << t << endl;
		deq.pop_front();
		for(int i = -1; i <= 1; i+=2){
			if(p+i <= 0 || p+i > m) continue;
			int np = p+i, nt = t + abs(d[np]-d[p]);
			if(nt > g) continue;
			
			int cost = 0;
			if(nt == g) cost = 1, nt = 0;
			if(dist[np][nt] <= dist[p][t] + cost) continue;
			dist[np][nt] = dist[p][t] + cost;
			
			//cout << "->" << " " << np << " " << nt << " " << dist[np][nt] << endl;
			
			if(cost == 0) deq.push_front(P(np, nt));
			else deq.push_back(P(np, nt));
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++) cin >> d[i];
	sort(d+1, d+m+1);
	cin >> g >> r;
	
	bfs();
	
	/*for(int i = 1; i <= m; i++){
		for(int j = 0; j < g; j++){
			if(dist[i][j] > 1e9/2) cout << "x ";
			else cout << dist[i][j] << " ";
		}
		cout << endl;
	}*/
	
	llint ans = inf;
	for(int i = 1; i <= m; i++){
		if(dist[i][0] > 1e9/2) continue;
		if(d[m]-d[i] > g) continue;
		ans = min(ans, (llint)dist[i][0]*(r+g) + d[m]-d[i]);
	}
	if(ans > inf/2) ans = -1;
	cout << ans << endl;
	
	return 0;
}