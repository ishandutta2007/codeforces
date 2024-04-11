#include <iostream>
#define llint long long

using namespace std;

llint T;
llint a, b, c;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> a >> b >> c;
		llint ans = 0;
		for(int i = 0; i <= min(a, b/2); i++){
			llint tmp = i*3 + min(b-2*i, c/2)*3;
			ans = max(ans, tmp);
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}