#include <iostream>
#define llint long long

using namespace std;

llint n;
llint a[200005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint ans = 0, mn = 2e9;
	for(int i = n; i >= 1; i--){
		llint x = max(0LL, min(mn, a[i]));
		ans += x;
		mn = x-1;
	}
	cout << ans << endl;
	
	return 0;
}