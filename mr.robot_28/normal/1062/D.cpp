#include <bits/stdc++.h>
using namespace std;
signed main() {
	#define int long long
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 2; i <= n; i++)
	{
		ans += i * ( n / i - 1) * 4;
	}
	cout << ans;
    return 0;
}