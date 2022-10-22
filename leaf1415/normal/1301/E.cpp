#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <utility>
#define inf 1e9

using namespace std;
typedef pair<int, string> P;

int h, w, Q;
int a[505][505];
int sum[4][505][505];
bool flag[255][505][505];
int fsum[255][505][505];

int get(int i, int sx, int sy, int tx, int ty)
{
	return sum[i][tx][ty] - sum[i][sx-1][ty] - sum[i][tx][sy-1] + sum[i][sx-1][sy-1];
}
int fget(int i, int sx, int sy, int tx, int ty)
{
	return fsum[i][tx][ty] - fsum[i][sx-1][ty] - fsum[i][tx][sy-1] + fsum[i][sx-1][sy-1];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w >> Q;
	char c;
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cin >> c;
			if(c == 'R') a[x][y] = 0;
			if(c == 'G') a[x][y] = 1;
			if(c == 'Y') a[x][y] = 2;
			if(c == 'B') a[x][y] = 3;
		}
	}
	for(int i = 0; i < 4; i++){
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				sum[i][x][y] = sum[i][x-1][y] + sum[i][x][y-1] - sum[i][x-1][y-1];
				if(a[x][y] == i) sum[i][x][y]++;
			}
		}
	}
	
	for(int y = 1; y <= h-1; y++){
		for(int x = 1; x <= w-1; x++){
			if(a[x][y] != 0 || a[x+1][y] != 1 || a[x][y+1] != 2 || a[x+1][y+1] != 3){
				//cout << -1 << " ";
				continue;
			}
			
			int size = inf;
			for(int i = 1; ; i++){
				if(x-i+1 <= 0 || y-i+1 <= 0){
					size = min(size, i-1);
					break;
				}
				if(get(0, x-i+1, y-i+1, x, y) < i*i){
					size = min(size, i-1);
					break;
				}
			}
			for(int i = 1; ; i++){
				if(x+i > w || y-i+1 <= 0){
					size = min(size, i-1);
					break;
				}
				if(get(1, x+1, y-i+1, x+i, y) < i*i){
					size = min(size, i-1);
					break;
				}
			}
			for(int i = 1; ; i++){
				if(x-i+1 <= 0 || y+i > h){
					size = min(size, i-1);
					break;
				}
				if(get(2, x-i+1, y+1, x, y+i) < i*i){
					size = min(size, i-1);
					break;
				}
			}
			for(int i = 1; ; i++){
				if(x+i > w || y+i > h){
					size = min(size, i-1);
					break;
				}
				if(get(3, x+1, y+1, x+i, y+i) < i*i){
					size = min(size, i-1);
					break;
				}
			}
			for(int i = 1; i <= size; i++) flag[i][x][y] = true;
			
			//cout << size << " ";
		}
		//cout << endl;
	}
	
	for(int i = 1; i <= 250; i++){
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				fsum[i][x][y] = fsum[i][x-1][y] + fsum[i][x][y-1] - fsum[i][x-1][y-1];
				if(flag[i][x][y]) fsum[i][x][y]++;
			}
		}
	}
	
	int sx, sy, tx, ty;
	for(int q = 0; q < Q; q++){
		cin >> sy >> sx >> ty >> tx;
		if(sx == tx || sy == ty){
			cout << 0 << "\n";
			continue;
		}
		tx--, ty--;
		
		int ans = 0, cnt = 0;
		while(sx <= tx && sy <= ty){
			cnt++;
			//cout << cnt << " " << fget(cnt, sx, sy, tx, ty) << endl;
			if(fget(cnt, sx, sy, tx, ty) > 0) ans = cnt;
			sx++, tx--, sy++, ty--;
		}
		ans *= 2, ans *= ans;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}