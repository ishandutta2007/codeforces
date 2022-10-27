#include <bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m , k;
		cin >> n >> m >> k;
		int a = min(m, n / k);
		int z = (m - a + k - 2) / (k - 1);
		cout << a - z << "\n";
	}
    return 0;
}