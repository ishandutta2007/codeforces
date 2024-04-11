#include <bits/stdc++.h>
 
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		int size1 = (n - m) / (m + 1);
		int size2 = n / (m + 1);
		int cnt2 = (n - m) % (m + 1);
		int cnt1 = m + 1 - cnt2;
		cout << n * (n + 1) / 2 - cnt1 * (size1 + 1) * size1 / 2 - cnt2 * (size2 + 1) * size2 / 2 << "\n";
	}
    return 0;
}