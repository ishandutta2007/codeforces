#include <iostream>
#define llint long long

using namespace std;

int h, w;
char c[505][505];
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

void calc(int cx, int cy)
{
	for(int i = 0; i < 4; i++){
		int x = cx, y = cy;
		while(1){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || nx > w || ny < 1 || ny > h) break;
			if(c[nx][ny] == '.') break;
			c[nx][ny] = '.';
			x = nx, y = ny;
		}
	}
	c[cx][cy] = '.';
}

bool check()
{
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			if(c[x][y] == '*') return false;
		}
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cin >> c[x][y];
		}
	}
	
	for(int y = 2; y < h; y++){
		for(int x = 2; x < w; x++){
			if(c[x][y] == '*' && c[x+1][y] == '*' && c[x][y+1] == '*' &&
			c[x-1][y] == '*' && c[x][y-1] == '*'){
				calc(x, y);
				if(check())	cout << "YES" << endl;
				else cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}