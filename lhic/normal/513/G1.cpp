#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;


int n, k;

ld dp[2][210][40][40];

int a[40];

int get(int x, int l, int r)
{
	if (x < l)
		return x;
	if (x > r)
		return x;
	return l + r - x;
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				continue;
			if (a[i] < a[j])
				dp[0][0][i][j] = 1;
			else
				dp[1][0][i][j] = 1;
		}

	int cnt = (n * (n - 1)) / 2 + n;

	for (int qq = 1; qq <= k; ++qq)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				if (i == j)
					continue;
				for (int i1 = 0; i1 < n; ++i1)
					for (int j1 = i1; j1 < n; ++j1)
					{
						dp[0][qq][get(i, i1, j1)][get(j, i1, j1)] += dp[0][qq - 1][i][j] / cnt;
						dp[1][qq][get(i, i1, j1)][get(j, i1, j1)] += dp[1][qq - 1][i][j] / cnt;
					}
			}
	}
	
	ld ans = 0;

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			ans += dp[1][k][i][j];
		}

	cout.setf(ios::fixed);
	cout.precision(20);

	cout << ans;

	
	return 0;
}