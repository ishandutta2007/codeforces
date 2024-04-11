#include <bits/stdc++.h>

using namespace std;

struct pred
{
    int carry;
    int add;
    pred() {}
    pred(int _carry, int _add): carry(_carry), add(_add) {}
};

bool dp[20][5];
pred go[20][5];

vector<int> digits(long long n)
{
    vector<int> res;
    while (n)
    {
        res.push_back(n % 10);
        n /= 10;
    }
    return res;
}

string s[6];

void rec(int len, int c)
{
    if (len == 0)
        return;
    int add = go[len][c].add;
    int to = go[len][c].carry;
    for (int z0 = 0; z0 <= 6; z0++)
        for (int z4 = 0; z0 + z4 <= 6; z4++)
        {
            int z7 = 6 - z0 - z4;
            if (z7 * 7 + z4 * 4 != add)
                continue;
            for (int i = 0; i < z0; i++)
                s[i] += '0';
            for (int i = z0; i < z0 + z4; i++)
                s[i] += '4';
            for (int i = z0 + z4; i < z0 + z4 + z7; i++)
                s[i] += '7';
        }
    rec(len - 1, to);
}

void solve()
{
    long long n;
    cin >> n;
    for (int i = 0; i < 20; i++)
        for (int c = 0; c < 5; c++)
            dp[i][c] = false;
    dp[0][0] = true;
    vector<int> d = digits(n);
    for (int len = 0; len < d.size(); len++)
        for (int c = 0; c < 5; c++)
        {
            if (!dp[len][c])
                continue;
            for (int z0 = 0; z0 <= 6; z0++)
                for (int z4 = 0; z0 + z4 <= 6; z4++)
                {
                    int z7 = 6 - z0 - z4;
                    int add = z4 * 4 + z7 * 7 + c;
                    int rem = add % 10;
                    int carry = add / 10;
                    if (rem != d[len])
                        continue;
                    dp[len + 1][carry] = true;
                    go[len + 1][carry] = pred(c, add - c);
                }
        }
    if (!dp[d.size()][0])
    {
        cout << -1 << "\n";
        return;
    }
    for (int i = 0; i < 6; i++)
        s[i].resize(0);
    rec(d.size(), 0);
    for (int i = 0; i < 6; i++)
        while (s[i].length() > 1 && s[i][0] == '0')
            s[i].erase(0, 1);
    for (int i = 0; i < 6; i++)
        cout << s[i] << " ";
    cout << "\n";
}


int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}