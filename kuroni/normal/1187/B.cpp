#include <iostream>
#include <cstdio>
using namespace std;

const int N = 200005;

int n, q, pos[26][N], cnt[26];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        int cur = s[i - 1] - 'a';
        pos[cur][++cnt[cur]] = i;
    }
    cin >> q;
    while (q--)
    {
        cin >> s;
        fill(cnt, cnt + 26, 0);
        int ans = 0;
        for (char &c : s)
            ans = max(ans, pos[c - 'a'][++cnt[c - 'a']]);
        cout << ans << '\n';
    }
}