#include <iostream>

using namespace std;

int n;
int a[10005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int ans = 0, mx = 0;
	for(int i = 1; i <= n; i++){
		mx = max(mx, a[i]);
		if(mx <= i) ans++, mx = 0;
	}
	if(mx) ans++;
	cout << ans << endl;
	
	return 0;
}