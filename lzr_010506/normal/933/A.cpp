#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
using namespace std;
const int P = 1e9 + 7;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
#define MOD 1000000007
const int N = 2010;
int n = 0;
int a[N], sum[N][3], f[N][N], f1[N][N];

int main()
{
    n = read();
    rep(i, 1, n) a[i] = read();
    rep(i, 1, n)
    {
        sum[i][1] = sum[i - 1][1];
        sum[i][2] = sum[i - 1][2];
        sum[i][a[i]] ++;
    }
    int ans = 0;
    rep(i, 1, n)
    {
        int now = 0, now2 = 0;
        rep(j, i, n)
        {
            if (a[j] == 2)
            {
                now2 ++;
                now = max(now, now2);
            }
            else now ++;
            f[i][j] = max(now, now2);
        }
    }
    rep(i, 1, n)
    {
        int now = 0, now2 = 0;
        rep(j, i, n)
        {
            if (a[j] == 1)
            {
                now ++;
                now2 = max(now, now2);
            }
            else now2 ++;
            f1[i][j] = max(now, now2);
        }
    }
    rep(i, 1, n)
    	rep(j, i, n)
    	{
            ans = max(ans, sum[j][1] + ((j == n) ? 0 : f1[j + 1][n]));
           	if(i == 1) ans = max(ans, sum[n][2] - sum[i - 1][2]);
           	else ans = max(ans, sum[n][2] - sum[i - 1][2] + f1[1][i - 1]);
            ans = max(ans, sum[n][2] - sum[j][2] + sum[i - 1][1] + f[i][j]);
        }

    cout << ans;
    return 0;
}