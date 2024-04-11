#include <iostream>
#include <string>
#include <math.h>
#define llint long long

using namespace std;

llint n, k;
char c[2005][2005];
llint dif[2005][2005], sum[2005][2005];

void add(llint sx, llint sy, llint tx, llint ty)
{
	dif[sx][sy]++;
	dif[tx+1][sy]--;
	dif[sx][ty+1]--;
	dif[tx+1][ty+1]++;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int y = 1; y <= n; y++){
		for(int x = 1; x <= n; x++){
			cin >> c[x][y];
		}
	}
	
	llint ncnt = 0;
	for(int y = 1; y <= n; y++){
		llint l = -1, r;
		for(int x = 1; x <= n; x++){
			if(c[x][y] == 'B'){
				l = x;
				break;
			}
		}
		if(l == -1){
			ncnt++;
			continue;
		}
		for(int x = n; x >= 1; x--){
			if(c[x][y] == 'B'){
				r = x;
				break;
			}
		}
		if(r-l+1 > k) continue;
		//cout << max(1LL, r-k+1) << " " << max(1LL, y-k+1) << " " << l << " " << y << endl;
		add(max(1LL, r-k+1), max(1LL, y-k+1), l, y);
	}
	
	for(int x = 1; x <= n; x++){
		llint l = -1, r;
		for(int y = 1; y <= n; y++){
			if(c[x][y] == 'B'){
				l = y;
				break;
			}
		}
		if(l == -1){
			ncnt++;
			continue;
		}
		for(int y = n; y >= 1; y--){
			if(c[x][y] == 'B'){
				r = y;
				break;
			}
		}
		if(r-l+1 > k) continue;
		add(max(1LL, x-k+1), max(1LL, r-k+1), x, l);
	}
	
	llint ans = 0;
	for(int y = 1; y <= n-k+1; y++){
		for(int x = 1; x <= n-k+1; x++){
			sum[x][y] = sum[x-1][y]+sum[x][y-1]-sum[x-1][y-1]+dif[x][y];
			ans = max(ans, sum[x][y]);
		}
	}
	ans += ncnt;
	
	/*cout << ncnt << endl;
	for(int y = 1; y <= n-k+1; y++){
		for(int x = 1; x <= n-k+1; x++){
			cout << sum[x][y] << " ";
		}
		cout << endl;
	}*/
	
	cout << ans << endl;
	
	return 0;
}