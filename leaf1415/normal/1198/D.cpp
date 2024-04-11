#include <iostream>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 10000000

using namespace std;
typedef pair<llint, llint> P;


llint n;
char c[55][55];
llint sum[55][55];
llint memo[55][55][55][55];

bool get(llint sx, llint sy, llint tx, llint ty)
{
	return sum[tx][ty]-sum[sx-1][ty]-sum[tx][sy-1]+sum[sx-1][sy-1] > 0;
}

int dfs(llint sx, llint sy, llint tx, llint ty)
{
	if(sx > tx || sy > ty) return 0;
	if(memo[sx][sy][tx][ty] != -1) return memo[sx][sy][tx][ty];
	
	bool flag = true;
	int l = inf, r = -inf, s = min(tx-sx+1, ty-sy+1);
	for(int x = sx; x <= tx; x++){
		if(get(x, sy, x, ty)) l = min(l, x), r = max(r, x);
	}
	if(l == inf) return memo[sx][sy][tx][ty] = 0;
	if(r-l+1 > s) flag = false;
	
	l = inf, r = -inf;
	for(int y = sy; y <= ty; y++){
		if(get(sx, y, tx, y)) l = min(l, y), r = max(r, y);
	}
	if(l == inf) return memo[sx][sy][tx][ty] = 0;
	if(r-l+1 > s) flag = false;
	
	int ret = inf;
	if(flag) ret = s;
	for(int x = sx; x <= tx; x++){
		if(!get(x, sy, x, ty)) ret = min(ret, dfs(sx, sy, x-1, ty) + dfs(x+1, sy, tx, ty));
	}
	for(int y = sy; y <= ty; y++){
		if(!get(sx, y, tx, y)) ret = min(ret, dfs(sx, sy, tx, y-1) + dfs(sx, y+1, tx, ty));
	}
	return memo[sx][sy][tx][ty] = ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int y = 1; y <= n; y++){
		for(int x = 1; x <= n; x++){
			cin >> c[x][y];
		}
	}
	for(int x = 1; x <= n; x++){
		for(int y = 1; y <= n; y++){
			sum[x][y] = sum[x-1][y]+sum[x][y-1]-sum[x-1][y-1];
			if(c[x][y] == '#') sum[x][y]++;
		}
	}
	
	for(int x = 1; x <= n; x++){
		for(int y = 1; y <= n; y++){
			for(int x2 = 1; x2 <= n; x2++){
				for(int y2 = 1; y2 <= n; y2++){
					memo[x][y][x2][y2] = -1;
				}
			}
		}
	}
	cout << dfs(1, 1, n, n) << endl;
	
	return 0;
}