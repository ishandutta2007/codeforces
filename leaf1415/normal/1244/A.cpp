#include <iostream>
#define llint long long

using namespace std;

llint t;
llint a, b, c, d, k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	for(int q = 0; q < t; q++){
		cin >> a >> b >> c >> d >> k;
		llint x = (a+c-1)/c, y = (b+d-1)/d;
		llint ans = x + y;
		if(ans > k) cout << -1 << "\n";
		else cout << x << " " << y << "\n";
	}
	flush(cout);
	
	return 0;
}