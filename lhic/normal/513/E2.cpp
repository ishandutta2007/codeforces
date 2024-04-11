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

const int INF = 1000000000;

const int MAXK = 210;
const int MAXN = 31000;

int mx[MAXK][MAXN];
int mn[MAXK][MAXN];
int dp[MAXK][MAXN];

int a[MAXN];

int n, k;

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	for (int i = 0; i < n; ++i)
	{
		dp[1][i] = 0;
		int now = a[i];
		mx[1][i] = a[i];
		mn[1][i] = -a[i];
		for (int j = i - 1; j >= 0; --j)
		{
			now += a[j];
			mx[1][i] = max(mx[1][i], now);
			mn[1][i] = max(mn[1][i], -now);
		}
	}

	for (int i = 2; i <= k; ++i)
	{
		int nm = mn[i - 1][i - 2];
		int xm = mx[i - 1][i - 2];
		int aspl1 = nm;
		int aspl2 = xm;
		int asmn1 = nm;
		int asmn2 = xm;
		for (int j = i - 1; j < n; ++j)
		{
			nm += a[j];
			xm -= a[j];
			aspl1 += 2 * a[j];
			asmn2 -= 2 * a[j];

			mx[i][j] = max(aspl1, aspl2);
			mn[i][j] = max(asmn1, asmn2);
			dp[i][j] = max(nm, xm);
			/*int now = 0;
			mx[i][j] = -INF;
			mn[i][j] = -INF;
			dp[i][j] = 0;*/
			/*for (int t = j; t > i - 2; --t)
			{
				now += a[t];
				int ans = max(mx[i - 1][t - 1] - now, mn[i - 1][t - 1] + now);
				mx[i][j] = max(mx[i][j], ans + now);
				mn[i][j] = max(mn[i][j], ans - now);
				dp[i][j] = max(dp[i][j], ans);
			}*/
			nm = max(nm, mn[i - 1][j]);
			xm = max(xm, mx[i - 1][j]);
			aspl1 = max(aspl1, mn[i - 1][j]);
			aspl2 = max(aspl2, mx[i - 1][j]);
			asmn1 = max(asmn1, mn[i - 1][j]);
			asmn2 = max(asmn2, mx[i - 1][j]);
		}
	}

	int ans = 0;

	for (int i = 0; i < n; ++i)
		ans = max(ans, dp[k][i]);

	cout << ans;

	return 0;
}