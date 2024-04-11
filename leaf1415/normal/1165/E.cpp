#include <iostream>
#include <algorithm>
#define llint long long
#define mod 998244353

using namespace std;

int n;
llint a[200005], b[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	
	for(llint i = 0; i < n; i++){
		a[i] *= (i+1)*(n-i);
	}
	sort(a, a+n);
	for(int i = 0; i < n; i++) a[i] %= mod;
	
	sort(b, b+n);
	reverse(b, b+n);
	
	llint ans = 0;
	for(int i = 0; i < n; i++) ans += a[i]*b[i]%mod, ans %= mod;
	
	cout << ans << endl;
	return 0;
}