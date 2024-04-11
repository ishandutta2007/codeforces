#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#define int long long
	int q;
	cin >> q;
	while(q--)
	{
		int n;
		cin >> n;
		vector <int> A(n), B(n);
		vector <vector <int> > dp(n, vector <int> (3, 1e18));
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
			cin >> B[i];
		}
		for(int i = 0; i < n; i++)
		{
			if(i == 0)
			{
				for(int j = 0; j < 3; j++)
				{
					dp[i][j] = j * B[i];
				}
			}
			else
			{
				for(int j = 0; j < 3; j++)
				{
					for(int j1 = 0; j1 < 3; j1++)
					{
						if(A[i - 1] + j1 != A[i] + j)
						{
							dp[i][j] = min(dp[i][j], dp[i - 1][j1] + j * B[i]);
						}
					}
				}
			}
		}
		cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << "\n";
	}
	return 0;
}