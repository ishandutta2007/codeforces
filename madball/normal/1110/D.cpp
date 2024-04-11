#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

#ifdef LOCAL
#pragma comment(linker, "/STACK:16777216")
#endif

const int MAXN = (int)1e6 + 3;
const int INF = (int)1e9 + 7;

int dp[MAXN][3][5];
int ar[MAXN];

void relax(int& a, int b)
{
	a = max(a, b);
}

void solve()
{
	int n, m;
	scanf("%d %d", &n, &m);
	For(i, n)
	{
		int a = i + 1;
		cin >> a;
		--a;
		++ar[a];
	}
	memset(dp, 128, sizeof(dp));
	dp[0][0][0] = 0;
	For(pos, m) For(left1, 3) For(left2, 5)
	{
		int cur = dp[pos][left1][left2];
		if (cur < -INF)
			continue;
		For(leave, 7)
		{
			if (leave > ar[pos])
				break;
			int three = (ar[pos] - leave) / 3;
			int left3 = min(leave, ar[pos] - three * 3);
			int row = min(left1, min(left2, left3));
			relax(dp[pos + 1][min(left2 - row, 2)][min(left3 - row, 4)], cur + three + row);
		}
	}
	int res = -INF;
	For(i, 3) For(j, 5)
		res = max(res, dp[m][i][j]);
	cout << res << '\n';
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}