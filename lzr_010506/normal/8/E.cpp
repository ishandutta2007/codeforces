#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define mod 1000000007
#define sz(x) (int)(x).size()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

ll n,k,a[55],dp[55][2][2];
ll dfs(int pos, int x1,     int x2)
{
    if(pos < n - pos + 1) return 1ll;
    if(dp[pos][x1][x2] >= 0) return dp[pos][x1][x2];
    ll ans = 0;
    rep(i, 0, 1)
    	if(i == a[pos] || a[pos] == -1)
    		rep(j, 0, 1)
    			if(j == a[n - pos + 1] || a[n - pos + 1] == -1)
       				if((!x1 || i <= j) && (pos != n - pos + 1 || i == j))
                        if((!x2 || i <= !j)) ans += dfs(pos - 1,x1 & (i == j),x2 & (i != j));
    dp[pos][x1][x2] = ans;
    return ans;
}
int main()
{
    memset(a, -1, sizeof(a));
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    a[n] = 0;
    k ++;
    if(dfs(n, 1, 1) < k)
	{
	    puts("-1");
		return 0;
	}
    cout << 0;
    rrep(i, n - 1, 1)
    {
    	memset(dp, -1, sizeof(dp));
        a[i] = 0;
        ll temp = dfs(n, 1, 1);
        if(temp < k)
        {
            k -= temp;
            a[i] = 1;
            cout << 1;
        }
        else cout << 0;
    }
    return 0;
}