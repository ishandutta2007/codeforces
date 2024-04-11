#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int h, w;
char map[55][55];
string s;
int sx, sy;
int perm[4];
const int vx[] = {1, 0, -1, 0}, vy[] = {0, -1, 0, 1};

int main(void)
{
	cin >> h >> w;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			cin >> map[x][y];
			if(map[x][y] == 'S'){
				sx = x, sy = y;
				map[x][y] = '.';
			}
		}
	}
	cin >> s;
	
	int ans = 0;
	for(int i = 0; i < 4; i++) perm[i] = i;
	do{
		int cx = sx, cy = sy;
		for(int i = 0; i < s.size(); i++){
			cx += vx[perm[s[i] - '0']];
			cy += vy[perm[s[i] - '0']];
			if(cx < 0 || cx >= w || cy < 0 || cy >= h) break;
			if(map[cx][cy] == '#') break;
			if(map[cx][cy] == 'E'){
				ans++;
				break;
			}
		}
	}while(next_permutation(perm, perm+4));
	
	cout << ans << endl;
	return 0;
}