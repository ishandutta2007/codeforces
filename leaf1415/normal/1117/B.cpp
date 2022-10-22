#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint n, m, k;
llint a[200005];

int main(void)
{
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	reverse(a, a+n);
	
	llint sum = k*a[0] + a[1];
	llint ans = m / (k+1) * sum + m % (k+1) * a[0];
	cout << ans << endl;
	return 0;
}