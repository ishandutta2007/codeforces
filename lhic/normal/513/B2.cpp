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

int n;
ll m;


ll dp[100];

int a[100];

int main()
{
	cin >> n >> m;
	dp[1] = 1;
	dp[0] = 1;
	for (int i = 2; i <= n; ++i)
		dp[i] = dp[i - 1] * 2;

	int l = 0;
	int r = n - 1;
	for (int i = 0; i < n; ++i)
	{
		if (dp[r - l] >= m)
		{
			a[l] = i + 1;
			++l;
		}
		else
		{
			m -= dp[r - l];
			a[r] = i + 1;
			--r;
		}
	}
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";

	return 0;
}