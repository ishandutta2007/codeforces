#include <iostream>
#include <string>
#include <vector>
#define llint long long

using namespace std;

llint n;
llint sx, sy;
llint x[200005], y[200005];
const llint dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

llint calc(llint d)
{
	llint ret = 0;
	for(int i = 1; i <= n; i++){
		if(d == 0 && x[i] > sx) ret++;
		if(d == 1 && y[i] < sy) ret++;
		if(d == 2 && x[i] < sx) ret++;
		if(d == 3 && y[i] > sy) ret++;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> sx >> sy;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	
	llint ans = -1, ansx, ansy;
	for(int i = 0; i < 4; i++){
		llint nx = sx + dx[i], ny = sy + dy[i];
		llint res = calc(i);
		if(res > ans){
			ansx = nx, ansy = ny;
			ans = res;
		}
	}
	cout << ans << endl;
	cout << ansx << " " << ansy << endl;
	
	return 0;
}