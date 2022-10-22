#include <iostream>

using namespace std;

int H, W, k;
char map[2005][2005];

int main(void)
{
	cin >> H >> W >> k;
	for(int y = 0; y < H; y++){
		for(int x = 0; x < W; x++){
			cin >> map[x][y];
		}
	}
	
	int ans = 0, cnt;
	if(k == 1){
		for(int x = 0; x < W; x++){
			for(int y = 0; y < H; y++){
				if(map[x][y] == '.') ans++;
			}
		}
		cout << ans << endl;
		return 0;
	}
	
	for(int y = 0; y < H; y++){
		cnt = 0;
		for(int x = 0; x < W; x++){
			if(map[x][y] == '.') cnt++;
			else cnt = 0;
			if(cnt >= k) ans++;
		}
	}
	for(int x = 0; x < W; x++){
		cnt = 0;
		for(int y = 0; y < H; y++){
			if(map[x][y] == '.') cnt++;
			else cnt = 0;
			if(cnt >= k) ans++;
		}
	}
	
	cout << ans << endl;
	return 0;
}