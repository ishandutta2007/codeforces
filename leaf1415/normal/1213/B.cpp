#include <iostream>
#define llint long long

using namespace std;

llint T;
llint n;
llint a[150005];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		llint ans = 0, mn = 1e9;
		for(int i = n; i >= 1; i--){
			if(mn < a[i]) ans++;
			mn = min(mn, a[i]);
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}