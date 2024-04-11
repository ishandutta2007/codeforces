#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;


llint n;
llint a[200005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < 2*n; i++) cin >> a[i];
	sort(a, a+2*n);
	
	llint ans = (a[n-1]-a[0])*(a[2*n-1]-a[n]);
	for(int i = 1; i < n; i++){
		ans = min(ans, (a[2*n-1]-a[0])*(a[i+n-1]-a[i]));
	}
	cout << ans << endl;
	return 0;	
}