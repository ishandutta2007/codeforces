#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
llint a[300005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	
	llint ans = 0;
	for(int i = 0; i < n/2; i++){
		llint x = a[i]+a[n-1-i];
		ans += x*x;
	}
	cout << ans << endl;
	
	return 0;
}