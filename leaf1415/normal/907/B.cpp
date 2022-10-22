#include <iostream>

using namespace std;

char map[9][9];
int px, py;

int main(void)
{
	for(int y = 0; y < 9; y++){
		for(int x = 0; x < 9; x++){
			cin >> map[x][y];
		}
	}
	cin >> py >> px;
	px--, py--;
	
	int fx = px % 3, fy = py % 3;
	bool flag = false;
	
	int nx, ny;
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
			nx = fx*3+x, ny = fy*3+y;
			if(map[nx][ny] == '.'){
				flag = true;
				map[nx][ny] = '!';
			}
		}
	}
	
	if(!flag){
		for(int x = 0; x < 9; x++){
			for(int y = 0; y < 9; y++){
				if(map[x][y] == '.'){
					map[x][y] = '!';
				}
			}
		}
	}
	
	for(int y = 0; y < 9; y++){
		for(int x = 0; x < 9; x++){
			cout << map[x][y];
			if(x % 3 == 2 && x != 8) cout << " ";
		}
		cout << endl;
		if(y % 3 == 2 && y != 8) cout << endl;
	}
	return 0;
}