#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;

const int max_n = 5111;
const long long inf = 1000000000111222LL;

int n;
ll money;
ll price[max_n];
ll price_d[max_n];
vector<int> v[max_n];

// dp[a][i][j]      j   i       ()   
vector<ll> dp[2][max_n];
vector<pair<int, ll>> dp2[max_n];

int sz[max_n];

int version = 1;
int dfs(int ver, bool can_use_d)
{
    if (v[ver].size() == 0) {
        dp[can_use_d][ver].PB(0);
        sz[ver] = 1;
        return 1;
    }

    vector<int> cnts;
    for (int i = 0; i < v[ver].size(); ++i) {
        cnts.PB(dfs(v[ver][i], can_use_d));
    }
    ++version;

    int sum = 0;
    if (!can_use_d) {
        for(int i = 0; i < v[ver].size(); ++i) {
            int to = v[ver][i];
            int cnt_cur = cnts[i];

            while (dp2[i].size() < sum + cnt_cur + 1) {
                dp2[i].PB(MP(0, inf));
            }
            for (int j = 0; j <= sum; ++j) {
                ll last = 0;
                if (j) {
                    if (dp2[i - 1][j].first == version) last = dp2[i - 1][j].second;
                    else continue;
                }

                for (int k = 0; k <= sz[to] - 1; ++k) {
                    if (dp2[i][j + k].first == version)
                        dp2[i][j + k].second = min(dp2[i][j + k].second, last + dp[0][to][k]);
                    else {
                        dp2[i][j + k].first = version;
                        dp2[i][j + k].second = last + dp[0][to][k];
                    }

                    //if (ver ==0 && i == 1 && j == 1) {
                        //cout << "AAA" << k << endl;
                    //}
                    if (dp2[i][j + k + 1].first == version)
                        dp2[i][j + k + 1].second = min(dp2[i][j + k + 1].second, last + dp[0][to][k] + price[to]);
                    else {
                        dp2[i][j + k + 1].first = version;
                        dp2[i][j + k + 1].second = last + dp[0][to][k] + price[to];
                    }
                }
            }
            sum += cnt_cur;
        }

        for (int i = 0; i <= sum; ++i) {
            //cout << dp2[0][0].second << endl;
            if (dp2[v[ver].size() - 1][i].first == version)
                dp[0][ver].PB(dp2[v[ver].size() - 1][i].second);
            else {
                dp[0][ver].PB(inf);
                //cout << "# " << dp2[1][5].second << endl;
                //cout << ver << ' ' << i << endl;
            }
            //cout << "# " << dp[0][0][0] << endl;
        }
    } else {
        for(int i = 0; i < v[ver].size(); ++i) {
            int to = v[ver][i];
            int cnt_cur = cnts[i];

            for (int j = 0; j <= sum; ++j) {
                ll last = 0;
                if (j) {
                    if (dp2[i - 1][j].first == version) last = dp2[i - 1][j].second;
                    else continue;
                }

                for (int k = 0; k <= sz[to] - 1; ++k) {
                    if (dp2[i][j + k].first == version)
                        dp2[i][j + k].second = min(dp2[i][j + k].second, last + dp[0][to][k]);
                    else {
                        dp2[i][j + k].first = version;
                        dp2[i][j + k].second = last + dp[0][to][k];
                    }

                    if (dp2[i][j + k + 1].first == version)
                        dp2[i][j + k + 1].second = min(dp2[i][j + k + 1].second, last + dp[1][to][k] + price_d[to]);
                    else {
                        dp2[i][j + k + 1].first = version;
                        dp2[i][j + k + 1].second = last + dp[1][to][k] + price_d[to];
                    }
                }
            }
            sum += cnt_cur;
        }
        for (int i = 0; i <= sum; ++i) {
            if (dp2[v[ver].size() - 1][i].first == version)
                dp[1][ver].PB(dp2[v[ver].size() - 1][i].second);
            else
                dp[1][ver].PB(inf);
        }
    }
    sz[ver] = sum + 1;
    return sum + 1;
}

int main()
{
    cin >> n >> money;
    int pred;
    cin >> price[0] >> price_d[0];
    price_d[0] = price[0] - price_d[0];
    for (int i = 1; i < n; ++i) {
        cin >>price[i] >> price_d[i] >> pred;
        --pred;
        v[pred].PB(i);
        price_d[i] = price[i] - price_d[i];
    }
    dfs(0, 0);
    dfs(0, 1);
    ll ans1 = -inf, ans2 = -inf;
    for (int i = 0; i <= n - 1; ++i) {
        if (dp[1][0][i] + price_d[0] <= money) ans1 = i + 1;
    }
    for (int i = 0; i <= n - 1; ++i) {
        //cout << dp[0][0][i] << ' ';
        if (dp[0][0][i] <= money) ans2 = i;
    }
    //cout << endl;
    cout << max(ans1, ans2);
}