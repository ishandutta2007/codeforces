#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, k, nxt[N][2], pre[N][2];
string s;

bool check(int pos, int to, int mv)
{
    int fi, se;
    if (to == mv)
    {
        fi = min(nxt[1][mv], pos);
        se = max(pre[n][mv], pos + k - 1);
    }
    else
    {
        fi = (nxt[1][mv] >= pos ? nxt[pos + k][mv] : nxt[1][mv]);
        se = (pre[n][mv] <= pos + k - 1 ? pre[pos - 1][mv] : pre[n][mv]);
    }
    return se - fi + 1 <= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> s;
    nxt[n + 1][0] = nxt[n + 1][1] = n + 1;
    for (int i = 1; i <= n; i++)
    {
        pre[i][0] = pre[i - 1][0];
        pre[i][1] = pre[i - 1][1];
        pre[i][s[i - 1] - '0'] = i;
    }
    for (int i = n; i >= 1; i--)
    {
        nxt[i][0] = nxt[i + 1][0];
        nxt[i][1] = nxt[i + 1][1];
        nxt[i][s[i - 1] - '0'] = i;
    }
    bool chk = true;
    for (int i = 1; i <= n - k + 1; i++)
    {
        if (nxt[i + k][0] == n + 1 && pre[i - 1][0] == 0)
            return cout << "tokitsukaze", 0;
        if (nxt[i + k][1] == n + 1 && pre[i - 1][1] == 0)
            return cout << "tokitsukaze", 0;
        chk &= (check(i, 0, 0) || check(i, 0, 1));
        chk &= (check(i, 1, 0) || check(i, 1, 1));
    }
    cout << (chk ? "quailty" : "once again");
}