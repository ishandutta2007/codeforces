#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[200005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, upper_bound(a, a+n, a[i]+5)-a-i);
	}
	cout << ans << endl;
	return 0;
}