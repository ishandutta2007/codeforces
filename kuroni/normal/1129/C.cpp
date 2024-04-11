#include <bits/stdc++.h>
using namespace std;

const int N = 3005, MOD = 1E9 + 7;

int n, ans = 0, a[N], dp[N][N];

struct STrie
{
    STrie *ch[2];

    STrie()
    {
        ch[0] = ch[1] = nullptr;
    }
} *rt = new STrie();

bool check(int pos, int len)
{
    if (len > pos)
        return false;
    if (len <= 3)
        return true;
    int msk = 0;
    for (int i = 0; i < len; i++)
        msk ^= (a[pos - i] << i);
    return msk != 3 && msk != 5 && msk != 14 && msk != 15;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        dp[i][i - 1] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        STrie *cur = rt;
        vector<int> ve;
        for (int j = 1; j <= 4; j++)
            if (check(i, j))
                ve.push_back(j);
        for (int j = i; j >= 1; j--)
        {
            for (int &k : ve)
                (dp[j][i] += dp[j][i - k]) %= MOD;
            if (cur->ch[a[j]] == nullptr)
            {
                cur->ch[a[j]] = new STrie();
                (ans += dp[j][i]) %= MOD;
            }
            cur = cur->ch[a[j]];
        }
        cout << ans << '\n';
    }
}