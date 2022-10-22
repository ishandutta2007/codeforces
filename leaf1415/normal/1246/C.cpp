#include <iostream>
#include <map>
#include <vector>
#define llint long long
#define mod 1000000007
#define inf 1e9

using namespace std;

llint h, w;
char c[2005][2005];
llint dp[2005][2005][2];
llint sum[2005][2005][2];
int lbd[2005][2005], ubd[2005][2005];

llint get(llint sx, llint sy, llint tx, llint ty, llint t)
{
	llint ret = sum[tx][ty][t] + sum[sx-1][sy-1][t]; ret %= mod;
	ret += mod - sum[sx-1][ty][t], ret %= mod;
	ret += mod - sum[tx][sy-1][t], ret %= mod;
	return ret;
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
	if(h == 1 && w == 1){
		cout << 1 << endl;
		return 0;
	}
	
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			lbd[x][y] = ubd[x][y] = inf;
		}
	}
	
	for(int y = 1; y <= h; y++){
		int cnt = 0;
		for(int x = w; x >= 1; x--){
			lbd[x+cnt][y] = min(lbd[x+cnt][y], x);
			if(c[x][y] == '.') cnt++;
		}
		int mn = inf;
		for(int x = w; x >= 1; x--){
			mn = min(mn, lbd[x][y]);
			lbd[x][y] = mn;
		}
	}
	
	for(int x = 1; x <= w; x++){
		int cnt = 0;
		for(int y = h; y >= 1; y--){
			ubd[x][y+cnt] = min(ubd[x][y+cnt], y);
			if(c[x][y] == '.') cnt++;
		}
		int mn = inf;
		for(int y = h; y >= 1; y--){
			mn = min(mn, ubd[x][y]);
			ubd[x][y] = mn;
		}
	}
	
	/*for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cout << lbd[x][y] << " ";
		}
		cout << endl;
	}
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cout << ubd[x][y] << " ";
		}
		cout << endl;
	}*/
	
	dp[1][1][0] = dp[1][1][1] = sum[1][1][0] = sum[1][1][1] = 1;
	for(int x = 1; x <= w; x++){
		for(int y = 1; y <= h; y++){
			for(int t = 0; t < 2; t++){
				if(t == 0 && lbd[x][y] < x) dp[x][y][t] = get(lbd[x][y], y, x-1, y, 1-t);
				if(t == 1 && ubd[x][y] < y) dp[x][y][t] = get(x, ubd[x][y], x, y-1, 1-t);
				sum[x][y][t] = sum[x-1][y][t] + sum[x][y-1][t] + dp[x][y][t], sum[x][y][t] %= mod;
				sum[x][y][t] += mod - sum[x-1][y-1][t], sum[x][y][t] %= mod;
			}
		}
	}
	llint ans = (dp[w][h][0] + dp[w][h][1]) % mod;
	cout << ans << endl;
	
	return 0;
}