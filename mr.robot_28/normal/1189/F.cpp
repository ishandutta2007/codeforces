#include<bits/stdc++.h>
using namespace std;
const int CONST = 998244353;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int ans = 0;
	sort(A.begin(), A.end());
		vector <vector <int> > dpcnt(n, vector <int> (k + 1));
		vector <vector <int> > prefcnt(n, vector <int> (k + 1));
	for(int x = 1; x * (k - 1) <= A[n - 1]; x++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j <= k; j++)
			{
				prefcnt[i][j] = dpcnt[i][j] = 0;
			}
		}
		for(int i = 0; i < n; i++)
		{
			dpcnt[i][1] = 1;
			if(i != 0)
			{
				prefcnt[i][1] = prefcnt[i - 1][1];
			}
			prefcnt[i][1] += dpcnt[i][1];
		}
		int j = 0;
		for(int i = 0; i < n; i++)
		{
			while(j < i && A[i] - A[j] >= x)
			{
				j++;
			}
			j--;
			if(j != -1)
			{
				for(int d = 1; d < k; d++)
				{
					dpcnt[i][d + 1] += prefcnt[j][d];
					prefcnt[i][d + 1] = prefcnt[i - 1][d + 1] + dpcnt[i][d + 1];
					if(prefcnt[i][d + 1] >= CONST)
					{
						prefcnt[i][d + 1] -= CONST;
					}
					if(dpcnt[i][d + 1] >= CONST)
					{
						dpcnt[i][d + 1] -= CONST;
					}
				}
			}
			else
			{
				j++;
			}
		}
		for(int i = 0; i < n; i++)
		{
			ans += dpcnt[i][k];
			if(ans >= CONST)
			{
				ans -= CONST;
			}
		}
	}
	cout << ans;
	return 0;
}