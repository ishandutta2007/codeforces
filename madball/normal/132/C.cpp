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

bool dp[101][201][52][2];

void solve()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    dp[0][100][0][0] = true;
    For(pos, sz(s)) For(x, 201) For(c, 51) For(dir, 2) if (dp[pos][x][c][dir])
    {
        dp[pos + 1][x + dir * 2 - 1][c + (s[pos] == 'T')][dir] = true;
        dp[pos + 1][x][c + (s[pos] == 'F')][1 - dir] = true;
    }
    int res = 0;
    For(x, 201) for (int c = k; c >= 0; c -= 2) For(dir, 2)
        if (dp[sz(s)][x][c][dir])
            res = max(res, abs(x - 100));
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