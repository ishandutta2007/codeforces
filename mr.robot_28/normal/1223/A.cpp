#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int n;
		cin >> n;
		if(n < 4)
		{
			cout << 4 - n << "\n";
		}
		else
		{
			cout << n % 2 << "\n";
		}
	}
	return 0;
}