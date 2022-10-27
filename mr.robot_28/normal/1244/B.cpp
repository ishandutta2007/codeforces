#include <bits/stdc++.h>

using namespace std;

signed main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int imin = -1, jmin = -1;
		for(int j = 0; j < n; ++j)
		{
			if(imin == -1 && s[j] == '1')
			{
				imin =j;
			}
			if(s[j] == '1')
			{
				jmin = j;
			}
		}
		if(imin == -1)
		{
			cout << n << "\n";
		}
		else
		{
			cout << max(max(n, 2 * (jmin + 1)), 2 * (n - imin)) << "\n";
		}
	}
	return 0;
}