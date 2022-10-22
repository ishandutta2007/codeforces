#include <iostream>

using namespace std;

int n;
int qx, qy;
int sx, sy, tx, ty;
bool map[1005][1005];
bool used[1005][1005];

bool dfs(int x, int y)
{
	used[x][y] = true;
	if(x == tx && y == ty) return true;
	
	int nx, ny;
	for(int dx = -1; dx <= 1; dx++){
		for(int dy = -1; dy <= 1; dy++){
			if(dx == 0 && dy == 0) continue;
			nx = x + dx, ny = y + dy;
			if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if(map[nx][ny] || used[nx][ny]) continue;
			if(dfs(nx, ny)) return true;
		}
	}
	return false;
}

int main(void)
{
	cin >> n;
	cin >> qx >> qy;
	cin >> sx >> sy >> tx >> ty;
	
	for(int x = 1; x <= n; x++){
		for(int y = 1; y <= n; y++){
			if(x == qx || y == qy || x+y == qx+qy || x-y == qx-qy) map[x][y] = true;
		}
	}
	
	if(dfs(sx, sy)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}