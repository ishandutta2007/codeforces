#include <iostream>
#define llint long long

using namespace std;

llint T, n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		llint ans = (n-1)/9 * 10;
		n -= (n-1)/9*9;
		ans += n;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}