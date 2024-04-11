#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

bool isp(int x)
{
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

void solve()
{
    string s;
    cin >> s;
    static int cnt[26];
    for (auto e : s)
        ++cnt[e - 'a'];
    int n = sz(s);
    string res(n + 1, ' ');
    char mostp = 'a';
    For(i, 26)
        if (cnt[i] > cnt[mostp - 'a'])
            mostp = 'a' + i;
    int ptr = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i != 1 && i * 2 <= n)
            continue;
        while (ptr < 26 && (cnt[ptr] == 0 || ptr == (mostp - 'a')))
            ++ptr;
        if (isp(i))
        {
            int cur = ptr < 26 ? ptr : (mostp - 'a');
            res[i] = 'a' + cur;
            --cnt[cur];
        }
    }
    for (int i = 1; i <= n; ++i)
        if (cnt[mostp - 'a'] > 0 && res[i] == ' ')
        {
            res[i] = mostp;
            --cnt[mostp - 'a'];
        }
    for (int i = 1; i <= n; ++i)
        if (res[i] == ' ')
        {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
    res.erase(res.begin());
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}