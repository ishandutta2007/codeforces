#include <iostream>

using namespace std;

int a, b, c, d;
int h = 50, w = 50;
int map[55][55];

void draw(int sx, int sy, int k, int v)
{
	for(int y = sy; y < sy+25; y += 2){
		for(int x = sx; x < sx+25; x += 2){
			if(k == 0) return;
			map[x][y] = v;
			k--;
		}
	}
}

int main(void)
{
	cin >> a >> b >> c >> d;
	
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			map[x][y] = y / 25 * 2 + x / 25;
		}
	}
	
	a--, b--, c--, d--;
	draw(0, 0, d, 3);
	draw(25, 0, c, 2);
	draw(0, 25, b, 1);
	draw(25, 25, a, 0);
	
	cout << h << " " << w << endl;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			if(map[x][y] == 0) cout << "A";
			if(map[x][y] == 1) cout << "B";
			if(map[x][y] == 2) cout << "C";
			if(map[x][y] == 3) cout << "D";
		}
		cout << endl;
	}
	
	return 0;
}