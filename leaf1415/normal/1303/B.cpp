#include <iostream>
#include <string>
#define llint long long
#define inf 1e18

using namespace std;

llint T;
llint n, g, b;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> g >> b;
		llint rem = n/2;
		
		llint ans = 0;
		if(rem/b*(g+b) >= n){
			cout << n << "\n";
			continue;
		}
		ans += rem/b*(g+b);
		n -= rem/b*(g+b);
		rem %= b;
		
		//cout << ans << " " << rem << endl;
		
		if(n <= g + rem){
			cout << ans + n << "\n";
			continue;
		}
		ans += g + b;
		n -= g + rem;
		
		if(n%g == 0) ans += (n/g-1)*(g+b)+g;
		else ans += n/g*(g+b) + n%g;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}