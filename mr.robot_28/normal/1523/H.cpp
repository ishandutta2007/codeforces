#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()

using namespace std;
const int mod = 1e9 + 7;
const int N = 2e4 + 10;
const int LOG = 17;
const int K = 31;
int dp[LOG][K][N];
int lg[N];
int a[N];
int sparse[K][LOG][N];
int get_max(int l, int r, int k)
{
    int t = lg[r - l + 1];
    return max(sparse[k][t][l], sparse[k][t][r - (1 << t) + 1]);
}
int cur_dp[N][K];
int ans[N];
int l[N], r[N], k[N];
int new_dp[K];

signed main()
{
   // ifstream cin("rt.txt.txt");
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int n, q;
    cin >> n >> q;
    lg[1] = 0;
    for(int i = 2; i < N; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < K; j++)
        {
            dp[0][j][i] = min(i + a[i] + j, n - 1);
        }
    }
    for(int i = 0; i + 1 < LOG; i++)
    {
        for(int x = 0; x < K; x++)
        {
            for(int y = 0; y < n; y++)
            {
                sparse[x][0][y] = dp[i][x][y];
            }
            for(int z = 0 ;z + 1 < LOG; z++)
            {
                for(int y = 0; y + (1 << (z + 1)) <= n; y++)
                {
                    sparse[x][z + 1][y] = max(sparse[x][z][y], sparse[x][z][y + (1 << z)]);
                }
            }
        }
        for(int k1 = 0; k1 < K; k1++)
        {
            for(int k2 = 0; k2 + k1 < K; k2++)
            {
                for(int x = 0; x < n; x++)
                {
                    dp[i + 1][k1 + k2][x] = max(dp[i + 1][k1 + k2][x], get_max(x, dp[i][k1][x], k2));
                }
            }
        }
    }
    fill(ans, ans + q, 0);
    for(int i = 0; i < q; i++)
    {
        cin >> l[i] >> r[i] >> k[i];
        l[i]--;
        r[i]--;
        if(l[i] == r[i])
        {
            ans[i] = -1;
            continue;
        }
        for(int z = 0; z <= k[i]; z++)
        {
            cur_dp[i][z] = l[i];
        }
    }
   // cout << dp[4][2][2] << "\n";
    for(int i = LOG - 1; i >= 0; i--)
    {
        for(int x = 0; x < K; x++)
        {
            for(int y = 0; y < n; y++)
            {
                sparse[x][0][y] = dp[i][x][y];
            }
            for(int z = 0; z + 1 < LOG; z++)
            {
                for(int y = 0; y + (1 << (z + 1)) <= n; y++)
                {
                    sparse[x][z + 1][y] = max(sparse[x][z][y], sparse[x][z][y + (1 << z)]);
                }
            }
        }
        for(int id = 0; id < q; id++)
        {
            if(ans[id] == -1)
            {
                continue;
            }
            memset(new_dp, 0, sizeof(new_dp));
            for(int was = 0; was <= k[id]; was++)
            {
                for(int will = 0; will + was <= k[id]; will++)
                {
                    new_dp[was + will] = max(new_dp[was + will], get_max(l[id], cur_dp[id][was], will));
                }
            }
            if(new_dp[k[id]] < r[id])
            {
                ans[id] += (1 << i);
                memcpy(cur_dp[id], new_dp, sizeof(new_dp));
            }
        }
      /*  cout << i << "\n";
        for(int j = 0; j <= k[7]; j++)
        {
            cout << cur_dp[7][j] << " ";
        }
        cout << "\n";
    */}
    for(int i = 0; i < q; i++)
    {
        cout << ans[i] + 1 << "\n";
    }
    return 0;
}