#include <iostream>
#define llint long long
#define inf 1e18

using namespace std;

llint n;
llint x[300005], y[300005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	
	llint xmin = inf, xmax = -inf, ymin = inf, ymax = -inf;
	for(int i = 1; i <= n; i++){
		xmin = min(xmin, x[i]);
		xmax = max(xmax, x[i]);
		ymin = min(ymin, y[i]);
		ymax = max(ymax, y[i]);
	}
	if(n == 3){
		cout << (xmax-xmin + ymax-ymin)*2 << endl;
		return 0;
	}
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, (xmax-x[i] + ymax-y[i])*2);
		ans = max(ans, (x[i]-xmin + ymax-y[i])*2);
		ans = max(ans, (x[i]-xmin + y[i]-ymin)*2);
		ans = max(ans, (xmax-x[i] + y[i]-ymin)*2);
	}
	cout << ans << " ";
	
	for(int i = 4; i <= n; i++){
		cout << (xmax-xmin + ymax-ymin)*2 << " ";
	}
	cout << endl;
	return 0;
}