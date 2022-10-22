#include <iostream>
#include <deque>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint h, w;
llint sx, sy;
llint l, r;
char map[2005][2005];
llint dist[2005][2005];
llint dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

void bfs()
{
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			dist[x][y] = inf;
		}
	}
	dist[sx][sy] = 0;
	
	deque<P> deq;
	deq.push_back(make_pair(sx, sy));
	while(deq.size()){
		llint x = deq.front().first, y = deq.front().second;
		deq.pop_front();
		llint nx, ny;
		for(int d = 0; d < 4; d++){
			nx = x + dx[d], ny = y + dy[d];
			if(nx < 1 || nx > w || ny < 1 || ny > h) continue;
			if(map[nx][ny] == '*') continue;
			if(dist[nx][ny] < inf) continue;
			if(d % 2){
				dist[nx][ny] = dist[x][y];
				deq.push_front(make_pair(nx, ny));
			}
			else{
				dist[nx][ny] = dist[x][y] + 1;
				deq.push_back(make_pair(nx, ny));
			}
		}
	}
}

int main(void)
{
	cin >> h >> w;
	cin >> sy >> sx;
	cin >> l >> r;
	
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cin >> map[x][y];
		}
	}
	
	bfs();
	
	llint ans = 0;
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			if(x >= sx){
				llint d = dist[x][y] - (x - sx);
				llint dl = d/2, dr = (x - sx) + d/2;
				if(dl <= l && dr <= r) ans++;
			}
			else{
				llint d = dist[x][y] - (sx - x);
				llint dr = d/2, dl = (sx - x) + d/2;
				if(dl <= l && dr <= r) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}