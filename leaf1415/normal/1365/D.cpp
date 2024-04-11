#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint h, w;
char c[55][55];
llint dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
bool used[55][55];

void dfs(int x, int y)
{
	used[x][y] = true;
	for(int i = 0; i < 4; i++){
		llint nx = x + dx[i], ny = y + dy[i];
		if(nx < 1 || nx > w || ny < 1 || ny > h) continue;
		if(c[nx][ny] == '#') continue;
		if(used[nx][ny]) continue;
		dfs(nx, ny);
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> w;
		
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				cin >> c[x][y];
			}
		}
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				if(c[x][y] != 'B') continue;
				for(int i = 0; i < 4; i++){
					llint nx = x + dx[i], ny = y + dy[i];
					if(nx < 1 || nx > w || ny < 1 || ny > h) continue;
					if(c[nx][ny] == 'G'){
						cout << "No" << endl;
						goto end;
					}
					if(c[nx][ny] == '.') c[nx][ny] = '#';
				}
			}
		}
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				used[x][y] = false;
			}
		}
		if(c[w][h] != '#') dfs(w, h);
		
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				if(c[x][y] == 'G' && !used[x][y]){
					cout << "No" << endl;
					goto end;
				}
			}
		}
		cout << "Yes" << endl;
		
		end:;
	}
	
	return 0;
}