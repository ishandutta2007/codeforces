#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#define llint long long

using namespace std;

llint n, k;
llint a[300005], s[300005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = n; i >= 1; i--) s[i] = s[i+1] + a[i];
	sort(s+2, s+n+1);
	reverse(s+2, s+n+1);
	
	llint ans = s[1];
	for(int i = 0; i < k-1; i++) ans += s[2+i];
	cout << ans << endl;
	
	return 0;
}