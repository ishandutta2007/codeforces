#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 42;

int n;
string s;
int nxt[Maxn][2];
ll tmp[Maxn];
ll dp[Maxn];
ll res;

void moveSpecific(int l, int r)
{
    for (int t = l; t <= r; t++) {
        fill(tmp, tmp + Maxn, 0ll);
        for (int i = 0; i < s.length(); i++) if (dp[i]) {
            int nj = nxt[i][s[t] - '0'];
            tmp[nj] += dp[i];
        }
        for (int i = 0; i < s.length(); i++)
            dp[i] = tmp[i];
    }
}

void moveAny(int c)
{
    for (int t = 0; t < c; t++) {
        fill(tmp, tmp + Maxn, 0ll);
        for (int i = 0; i < s.length(); i++) if (dp[i]) {
            tmp[nxt[i][0]] += dp[i];
            tmp[nxt[i][1]] += dp[i];
        }
        for (int i = 0; i < s.length(); i++)
            dp[i] = tmp[i];
    }
}

int main()
{
    scanf("%d", &n);
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        for (int j = 0; j < 2; j++) {
            string cur = s.substr(0, i) + string(1, '0' + j);
            nxt[i][j] = cur.length();
            while (nxt[i][j] > 0 && s.substr(0, nxt[i][j]) != cur.substr(int(cur.length()) - nxt[i][j]))
                nxt[i][j]--;
        }
    for (int i = 0; i + s.length() <= n; i++) {
        fill(dp, dp + Maxn, 0ll);
        dp[0] = 1;
        moveAny(i);
        moveSpecific(0, int(s.length()) - 2);
        ll add = 0;
        for (int j = 0; j < s.length(); j++)
            add += dp[j];
        res += add * (1ll << (ll(n) - ll(i) - ll(s.length())));
    }
    for (int st = 1; st < s.length(); st++) {
        int en = int(s.length()) - st;
        fill(dp, dp + Maxn, 0ll);
        dp[0] = 1;
        moveSpecific(int(s.length()) - st, int(s.length()) - 1);
        moveAny(n - st - en);
        moveSpecific(0, int(s.length()) - 2);
        for (int j = 0; j < s.length(); j++)
            res += dp[j];
    }
    cout << res << endl;
    return 0;
}