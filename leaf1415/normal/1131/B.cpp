#include <iostream>
#define llint long long

using namespace std;

llint n;
llint a[10005], b[10005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	
	llint ans = 1, x = 0, y = 0;
	for(int i = 1; i <= n; i++){
		llint nx = a[i], ny = b[i];
		if(x == nx && y == ny) continue;
		if(x == nx){
			if(y < x && ny >= x) ans++;
			y = ny;
			continue;
		}
		if(y == ny){
			if(x < y && nx >= y) ans++;
			x = nx;
			continue;
		}
		if(max(x, y) > min(nx, ny)){
			x = nx, y = ny;
			continue;
		}
		llint mx = max(x, y);
		if(x != y) ans++;
		x = y = mx;
		ans += min(nx, ny) - x;
		x = nx, y = ny;
	}
	cout << ans << endl;
	
	return 0;
}