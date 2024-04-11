#include <bits/stdc++.h>
using namespace std;
#define int long long
int min(int a, int b)
{
	if(a < b)
	{
		return a;
	}
	return b;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int res = 0;
	vector <bool> used(1000);
	for(int i = 0; i <= min(n, 8); i++)
	{
		for(int j = 0; j <= min(8, n - i); j++)
		{
			if(used[(i * 4 + j * 9) % 49])
			{
				continue;
			}
			used[(i * 4 + j * 9) % 49] = true;
			res += (n - i - j + 1);
		}
	}
	cout << res;
	return 0; 
}