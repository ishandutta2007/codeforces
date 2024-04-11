#include <iostream>
#include <queue>
#include <utility>
#define inf 1e9+7

using namespace std;
typedef pair<int, int> P;
typedef pair< pair<int, P>, P > Move;

int h, w, p;
int s[1005];
char map[1005][1005];
int pos[1005][1005];
int ans[10];
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

Move move(int t, int p, int m, int x, int y){
	return make_pair(make_pair(t, make_pair(p, m)), make_pair(x, y));
}

void bfs()
{
	priority_queue<Move, vector<Move>, greater<Move> > Q;
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			if(map[x][y] >= '1' && map[x][y] <= '9'){
				pos[x][y] = map[x][y]-'0';
				Q.push(move(1, map[x][y]-'0', 1, x, y));
			}
		}
	}
	
	while(Q.size()){
		Move mv = Q.top();
		int t = mv.first.first, p = mv.first.second.first, m = mv.first.second.second;
		int x = mv.second.first, y = mv.second.second;
		//cout << t << " " << p << " " << m << " " << x << " " << y << endl;
		Q.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx <= 0 || nx > w || ny <= 0 || ny > h) continue;
			if(map[nx][ny] != '.') continue;
			if(pos[nx][ny]) continue;
			if(m >= s[p]) Q.push(move(t+1, p, 1, nx, ny));
			else Q.push(move(t, p, m+1, nx, ny));
			pos[nx][ny] = p;
		}
	}
}

int main(void)
{
	cin >> h >> w >> p;
	for(int i = 1; i <= p; i++) cin >> s[i];
	
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cin >> map[x][y];
		}
	}
	
	bfs();
	
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			if(pos[x][y] != 0) ans[pos[x][y]]++;
		}
	}
	for(int i = 1; i <= p; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}