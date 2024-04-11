#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#define llint long long

using namespace std;

int n;
int tx[1005][1005], ty[1005][1005];
int tx2[1005][1005], ty2[1005][1005];
int ans[1005][1005];
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

void dfs(llint x, llint y, llint gx, llint gy)
{
	tx2[x][y] = gx, ty2[x][y] = gy;
	for(int i = 0; i < 4; i++){
		llint nx = x + dx[i], ny = y + dy[i];
		if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
		if(tx[nx][ny] != gx || ty[nx][ny] != gy) continue;
		if(tx2[nx][ny] != -1) continue;
		ans[nx][ny] = (i+2)%4;
		dfs(nx, ny, gx, gy);
	}
}

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	scanf("%d", &n);
	for(int y = 1; y <= n; y++){
		for(int x = 1; x <= n; x++){
			scanf("%d", &ty[x][y]);
			scanf("%d", &tx[x][y]);
		}
	}
	
	for(int y = 1; y <= n; y++){
		for(int x = 1; x <= n; x++){
			if(tx[x][y] == x && ty[x][y] == y){
				ans[x][y] = -1;
				continue;
			}
			if(tx[x][y] == -1){
				bool flag = false;
				for(int i = 0; i < 4; i++){
					llint nx = x + dx[i], ny = y + dy[i];
					if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
					if(tx[nx][ny] == tx[x][y] && ty[nx][ny] == ty[x][y]){
						ans[x][y] = i;
						flag = true;
						break;
					}
				}
				if(!flag){
					cout << "INVALID" << endl;
					return 0;
				}
			}
		}
	}
	
	for(int y = 1; y <= n; y++){
		for(int x = 1; x <= n; x++){
			tx2[x][y] = ty2[x][y] = -1;
		}
	}
	for(int y = 1; y <= n; y++){
		for(int x = 1; x <= n; x++){
			if(ans[x][y] == -1) dfs(x, y, x, y);
		}
	}
	
	for(int y = 1; y <= n; y++){
		for(int x = 1; x <= n; x++){
			if(tx[x][y] != tx2[x][y] || ty[x][y] != ty2[x][y]){
				cout << "INVALID" << endl;
				return 0;
			}
		}
	}
	
	string s = "RULD";
	cout << "VALID" << endl;
	for(int y = 1; y <= n; y++){
		for(int x = 1; x <= n; x++){
			if(ans[x][y] == -1) cout << "X";
			else cout << s[ans[x][y]];
		}
		cout << "\n";
	}
	flush(cout);
	
	return 0;
}