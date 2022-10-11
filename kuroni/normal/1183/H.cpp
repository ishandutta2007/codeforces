#include <bits/stdc++.h>
using namespace std;

const int N = 105, MX = 26;
const long long INF = 1E18 + 7;

int n;
long long ans = 0, k, f[N][MX], g[N];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> s;
    g[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int cur = s[i - 1] - 'a';
        for (int j = i; j >= 1; j--)
        {
            g[j] -= f[j][cur];
            f[j][cur] = g[j - 1];
            g[j] = min(g[j] + f[j][cur], INF);
        }
    }
    for (int i = n; i >= 0 && k > 0; i--)
    {
        ans += min(k, g[i]) * (n - i);
        k -= min(k, g[i]);
    }
    cout << (k > 0 ? -1 : ans);
}