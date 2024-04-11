#include <iostream>
#define llint long long

using namespace std;

llint n, d, e;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> d >> e;
	e *= 5;
	
	llint ans = n;
	for(llint i = 0; i*d <= n; i++){
		llint rem = (n-i*d);
		ans = min(ans, rem - rem/e*e);
	}
	cout << ans << endl;
	
	return 0;
}