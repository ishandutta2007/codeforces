#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<int> s;
vector<int> t;
vector<int> d;
vector<int> w;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;

    vector<vector<long long>> dp(100001, vector<long long>(201, 0));

    cin >> n >> k >> m;

    s.resize(m);
    t.resize(m);
    d.resize(m);
    w.resize(m);

    for (int i = 0; i < m; i++)
        {
        cin >> s[i] >> t[i] >> d[i] >> w[i];
        --s[i];
        --t[i];
        d[i];
        }

    multiset<pair<int, int>> pursh;

    vector<vector<pair<int, int>>> events(100002);

    for (int i = 0; i < m; i++)
        {
        events[s[i]  ].push_back({ w[i], d[i]});
        events[t[i]+1].push_back({-w[i], d[i]});
        }

    vector<pair<int, int>> best(100001);
    for (int i = 0; i < 100001; i++)
        {
        for (int j = 0; j < events[i].size(); j++)
            {
            auto next = events[i][j];

            //cout << "pr: " << next.first << " " << next.second << endl;
            if (next.first > 0) pursh.insert(next);
            else pursh.erase(pursh.find({-next.first, next.second}));
            }

        if (pursh.empty())
            {
            best[i] = {0, i+1};
            }
        else
            {
            auto mv = --(pursh.end());
            best[i] = *mv;
            }
        }

    /*for (int i = 0; i < 10; i++)
        {
        cout << best[i].first << " " << best[i].second << endl;
        }  */

    for (int i = 100000-1; i >= 0; --i)
        {
        for (int j = 0; j <= 200; j++)
            {
            dp[i][j] = dp[best[i].second][j] + ((long long)best[i].first);

            if (j > 0)
                {
                dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
                }
            }
        }





    cout << dp[0][k];

    return 0;
    }