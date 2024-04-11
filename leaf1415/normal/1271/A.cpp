#include <iostream>
#define llint long long

using namespace std;

llint a, b, c, d, e, f;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c >> d >> e >> f;
	llint m = min(a, d), ans = 0;
	for(int i = 0; i <= m; i++){
		llint n = min(b, min(c, d-i));
		if(n < 0) continue;
		ans = max(ans, i*e + n*f);
	}
	cout << ans << endl;
	
	return 0;
}