#include <iostream>

using namespace std;

int h, w;
char map[1005][1005];
bool ink[1005][1005];

int main(void)
{
	cin >> h >> w;
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cin >> map[x][y];
		}
	}
	
	for(int y = 2; y <= h-1; y++){
		for(int x = 2; x <= w-1; x++){
			bool flag = true;
			for(int dx = -1; dx <= 1; dx++){
				for(int dy = -1; dy <= 1; dy++){
					if(dx == 0 && dy == 0) continue;
					if(map[x+dx][y+dy] == '.') flag = false;
				}
			}
			if(!flag) continue;
			for(int dx = -1; dx <= 1; dx++){
				for(int dy = -1; dy <= 1; dy++){
					if(dx == 0 && dy == 0) continue;
					ink[x+dx][y+dy] = true;
				}
			}
		}
	}
	
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			if(map[x][y] == '#' && !ink[x][y] ||
			map[x][y] == '.' && ink[x][y]){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}