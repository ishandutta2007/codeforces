#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
vector <int> A;
int binsearch(int l, int r, int a)
{
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		if(A[midd] <= a)
		{
			l = midd;
		}
		else
		{
			r = midd;
		}
	}
	return r - 1;
}
int main()
{
	int n, k;
	cin >> n >> k;
	A.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	vector <vector <int> > dp(n + 1, vector <int> (k + 1, 0));
	int max1 = 0;
	for(int j = 0; j < k; j++)
	{
		for(int i = 0; i < n; i++)
		{
			int y = binsearch(0, n, A[i] + 5);
			if(i != 0)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
			dp[y + 1][j + 1] = max(dp[y + 1][j + 1], dp[i][j] + y - i + 1);
			max1 = max(max1, dp[y + 1][j + 1]);
		}
	}
	cout << max1;
	return 0;
}