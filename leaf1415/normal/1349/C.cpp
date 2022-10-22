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
#define inf 1.5e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint h, w, Q;
char c[1005][1005];
bool iso[1005][1005];
llint dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
llint dist[1005][1005];
char color[1005][1005];

void bfs()
{
	queue<P> Q;
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			if(iso[x][y]) dist[x][y] = inf;
			else{
				Q.push(P(x, y));
				color[x][y] = c[x][y];
			}
		}
	}
	
	llint x, y;
	while(Q.size()){
		x = Q.front().first, y = Q.front().second;
		Q.pop();
		for(int i = 0; i < 4; i++){
			llint nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || nx > w || ny < 1 || ny > h) continue;
			if(dist[nx][ny] < inf) continue;
			dist[nx][ny] = dist[x][y] + 1;
			color[nx][ny] = color[x][y];
			Q.push(P(nx, ny));
		}
	}
	
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w >> Q;
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cin >> c[x][y];
		}
	}
	
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			for(int i = 0; i < 4; i++){
				llint nx = x + dx[i], ny = y + dy[i];
				if(nx < 1 || nx > w || ny < 1 || ny > h) continue;
				if(c[x][y] == c[nx][ny]) iso[x][y] = true;
			}
			iso[x][y] = !iso[x][y];
		}
	}
	
	bfs();
	
	/*for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cout << iso[x][y];
		}
		cout << endl;
	}*/
	
	llint x, y, p;
	for(int q = 0; q < Q; q++){
		cin >> y >> x >> p;
		//cout << color[x][y] << " " << p << endl;
		if(dist[x][y] > p) cout << c[x][y] << "\n";
		else cout << (char)((color[x][y]-'0'+p)%2+'0') << "\n";
	}
	flush(cout);
	
	return 0;
}