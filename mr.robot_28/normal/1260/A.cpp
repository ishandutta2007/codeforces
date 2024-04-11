#include <bits/stdc++.h>
using namespace std;


signed main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int c, sum;
		cin >> c >> sum;
		int d = sum / c;
		int d1 = sum / c + 1;
		int cnt1 = c - sum %c;
		int cnt2 = sum % c;
		cout << cnt1 * d * d + cnt2 * d1 * d1 << "\n";
	}
	return 0;
}