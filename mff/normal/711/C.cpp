#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int64> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 110;

int64 cur_color[maxn];
int64 cost[maxn][maxn];

int64 dp[maxn][maxn][maxn]; // tree | color | k
set<pii> memo[maxn][maxn];

void update(int64 t, int64 c, int64 k){
    memo[t][k].insert({-dp[t][c][k], c});
    while (memo[t][k].size() > 2){
        memo[t][k].erase(memo[t][k].begin());
    }
}

int64 ndp(int64 t, int64 c, int64 k){
    int64 ans = oo;

    for (auto p : memo[t][k])
        if (p.second != c)
            ans = min(ans, -p.first);

    return ans;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    int64 n, m, k;
    cin >> n >> m >> k;

    for (int64 i = 1; i <= n; ++i){
        cin >> cur_color[i];
    }

    for (int64 i = 1; i <= n; ++i){
        for (int64 j = 1; j <= m; ++j)
            cin >> cost[i][j];
    }

    memset(dp, oo, sizeof dp);

    for (int64 i = 1; i <= m; ++i)
        dp[0][i][1] = 0;

    for (int64 t = 1; t <= n; ++t){
        if (cur_color[t] == 0){
            for (int64 c = 1; c <= m; ++c){
                for (int64 kk = 1; kk <= k; ++kk){
                    dp[t][c][kk] = min(dp[t - 1][c][kk], ndp(t - 1, c, kk - 1)) + cost[t][c];
                    update(t, c, kk);
                    // cout << t << " " << c << " " << kk << " " << dp[t][c][kk] << endl;
                }
            }
        }
        else{
            int64 c = cur_color[t];
            for (int64 kk = 1; kk <= k; ++kk){
                dp[t][c][kk] = min(dp[t - 1][c][kk], ndp(t - 1, c, kk - 1));
                update(t, c, kk);
            }
        }
    }

    int64 ans = oo;

    for (int64 c = 1; c <= m; ++c)
        ans = min(ans, dp[n][c][k]);

    if (ans == oo) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}