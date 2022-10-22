#include <iostream>
#define llint long long

using namespace std;

llint n;
llint a[100005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint mx = 0;
	for(int i = 1; i <= n; i++) mx = max(mx, a[i]);
	
	llint ans = 0, cnt = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == mx) cnt++, ans = max(ans, cnt);
		else cnt = 0;
	}
	ans = max(ans, cnt);
	
	cout << ans << endl;
	
	return 0;
}