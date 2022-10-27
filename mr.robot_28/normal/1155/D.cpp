#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define int long long
vector <int> A;
vector <vector <int> > dp;
int rec(int x, int y, int k)
{
	if(x == A.size())
	{
		return 0;
	}
	if(dp[x][y] != -1)
	{
		return dp[x][y];
	}
	dp[x][y] = 0;
	if(y == 0)
	{
		dp[x][y] = max(dp[x][y], A[x] + rec(x + 1, 0, k));
		dp[x][y] = max(dp[x][y], k * A[x] + rec(x + 1, 1, k));
	}
	else if(y == 1)
	{
		dp[x][y] = max(dp[x][y], k * A[x] + rec(x + 1, 1, k));
		dp[x][y] = max(dp[x][y], A[x] + rec(x + 1, 2, k));
	}
	else
	{
		dp[x][y] = max(dp[x][y], A[x] + rec(x + 1, 2, k));
	}
	return dp[x][y];
}
main()
{
	int n, k;
	cin >> n >> k;
	A.resize(n);
	dp.resize(n, vector <int> (3, -1));
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int max1 = -1e18;
	for(int i = 0; i < n; i++)
	{
		max1 = max(max1, rec(i, 0, k));
	}
	cout << max1;
    return 0;
}