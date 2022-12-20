#include <stdio.h>
#include <bits/stdc++.h>

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

using namespace std;

const int N = 400;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;

void add(int &x, int y) { x += y; if (x >= MOD) x -= MOD; }

int f(int x)
{
	int res = 1;
	for (int i = 2; i * i <= x; i++)
	{
		int c = 0;
		while (x % i == 0)
		{
			c ^= 1;
			x /= i;
		}
		if (c == 1)
			res *= i;
	}
	if (x > 1)
		res *= x;
	return res;
}

int a[N];
int dp[N + 1][N][N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    //ll TL = 0.95 * CLOCKS_PER_SEC;
    //clock_t time = clock();
    int n;
    cin >> n;
    rep(i, 0, n)
    {
    	cin >> a[i];
    	a[i] = f(a[i]);
    }
    sort(a, a + n);
    dp[0][0][0] = 1;
    int last = 0;
    rep(i, 0, n)
    {
    	rep(j, 0, n)
    		rep(k, 0, n)
    		{
    			if (dp[i][j][k] == 0)
    				continue;
    			int c1 = (i - last) * 2 - k;
    			int c2 = j;
    			int c3 = (i + 1) - c1 - c2;
    			if (c1 > 0)
    				add(dp[i + 1][j][k + 1], (ll)dp[i][j][k] * c1 % MOD);
    			if (c2 > 0)
    				add(dp[i + 1][j - 1][k], (ll)dp[i][j][k] * c2 % MOD);
    			if (c3 > 0)
    				add(dp[i + 1][j][k], (ll)dp[i][j][k] * c3 % MOD);
    		}
    	if (i == n - 1 || a[i] != a[i + 1])
    	{
    		last = i + 1;
    		rep(j, 0, n)
    			rep(k, 0, n)
    				if (dp[i + 1][j][k] != 0 && k > 0)
    				{
    					add(dp[i + 1][j + k][0], dp[i + 1][j][k]);
    					dp[i + 1][j][k] = 0;
    				}
    	}
    }
    cout << dp[n][0][0] << "\n";
    return 0;
}