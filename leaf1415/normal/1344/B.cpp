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

llint h, w;
char c[1005][1005];
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

void dfs(int x, int y)
{
	c[x][y] = '.';
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 1 || nx > w || ny < 1 || ny > h) continue;
		if(c[nx][ny] != '#') continue;
		dfs(nx, ny);
	}
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
	
	bool yflag = false;
	for(int y = 1; y <= h; y++){
		bool flag = false; llint cnt = 0;
		for(int x = 1; x <= w; x++){
			if(c[x][y] == '#'){
				if(!flag) cnt++;
				flag = true;
			}
			else flag = false;
		}
		if(cnt >= 2){
			cout << -1 << endl;
			return 0;
		}
		if(cnt == 0) yflag = true;
	}
	
	bool xflag = false;
	for(int x = 1; x <= w; x++){
		bool flag = false; llint cnt = 0;
		for(int y = 1; y <= h; y++){
			if(c[x][y] == '#'){
				if(!flag) cnt++;
				flag = true;
			}
			else flag = false;
		}
		if(cnt >= 2){
			cout << -1 << endl;
			return 0;
		}
		if(cnt == 0) xflag = true;
	}
	
	if((xflag && !yflag) || (!xflag && yflag)){
		cout << -1 << endl;
		return 0;
	}
	
	llint ans = 0;
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			if(c[x][y] == '#') ans++, dfs(x, y);
		}
	}
	cout << ans << endl;
	
	return 0;
}