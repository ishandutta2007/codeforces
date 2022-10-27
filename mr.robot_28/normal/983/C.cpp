#include<bits/stdc++.h>
using namespace std;
vector <int> index[5];
void go_to(int i, int mask, int cnt, int ind)
{
    if(cnt == 0)
    {
        index[ind].push_back(mask);
        return;
    }
    if(i == 9)
    {
        return;
    }
    go_to(i, mask + pow(5, i), cnt - 1, ind);
    go_to(i + 1, mask, cnt, ind);
}
int index2[2000000];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <pair <int, int> > x(n);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i].first >> x[i].second;
        x[i].first--;
        x[i].second--;
    }
    for(int cnt = 0; cnt <= 4; cnt++)
    {
        go_to(0, 0, cnt, cnt);
    }
    int dp[2][500][5][9];
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j <= 4; j++)
        {
            for(int k = 0; k < index[j].size(); k++)
            {
                for(int en = 0; en < 9; en++)
                {
                    dp[i][k][j][en] = 1e9;
                }
            }
        }
    }
    for(int i = 0; i <= 4; i++)
    {
        sort(index[i].begin(), index[i].end());
        for(int j = 0; j < index[i].size(); j++)
        {
            index2[index[i][j]] = j;
        }
    }
    int powers[10];
    powers[0] = 1;
    for(int i = 1; i <= 9; i++)
    {
        powers[i] = powers[i - 1] * 5;
    }
    dp[0][0][0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= 4; j++)
        {
            for(int k = 0; k < index[j].size(); k++)
            {
                for(int en = 0; en < 9; en++)
                {
                    dp[i & 1][k][j][en] = 1e9;
                }
            }
        }
        for(int j = 3; j >= 0; j--)
        {
            for(int k = 0; k < index[j].size(); k++)
            {
                for(int en = 0; en < 9; en++)
                {
                    int ind1 = index[j][k] + powers[x[i - 1].second];
                    ind1 = index2[ind1];
                    dp[i & 1][ind1][j + 1][x[i - 1].first] = min(dp[i & 1][ind1][j + 1][x[i - 1].first], dp[(i - 1) & 1][k][j][en] + abs(en - x[i - 1].first));
                }
            }
        }
        for(int j = 4; j > 0; j--)
        {
            for(int k = 0; k < index[j].size(); k++)
            {
                for(int en = 0; en < 9; en++)
                {
                    for(int to = 0; to < 9; to++)
                    {
                        int w1= index[j][k] / powers[to];
                        w1 %= 5;
                        if(w1 == 0)
                        {
                            continue;
                        }
                        int ind1 = index[j][k] - w1 * powers[to];
                        ind1 = index2[ind1];
                        dp[i & 1][ind1][j - w1][to] = min(dp[i & 1][ind1][j - w1][to], dp[i & 1][k][j][en] + abs(en - to));
                    }
                }
            }
        }
    }
    int ans = 1e9;
    for(int j = 0; j < 9; j++)
    {
        ans = min(ans, dp[n & 1][0][0][j]);
    }
    cout << ans + n * 2;
    return 0;
}