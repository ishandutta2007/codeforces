#include <iostream>

using namespace std;

int n;
int a[400005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) a[n+i] = a[i];
	
	int cnt = 0, ans = 0;
	for(int i = 1; i <= 2*n; i++){
		if(a[i]) cnt++;
		else cnt = 0;
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	
	return 0;
}