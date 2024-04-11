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

void solve()
{
    int n;
    string s[3]{ "", "", "" };
    cin >> n >> s[0] >> s[1] >> s[2];
    int cnt[3][2] = { {0, 0}, {0, 0}, {0, 0} };
    For(i, 3) For(j, n * 2)
        ++cnt[i][s[i][j] - '0'];

    int i1 = 0, i2 = 0, c = '0';
    if (cnt[0][0] >= n && cnt[1][0] >= n)
        i1 = 0, i2 = 1, c = '0';
    if (cnt[0][0] >= n && cnt[2][0] >= n)
        i1 = 0, i2 = 2, c = '0';
    if (cnt[1][0] >= n && cnt[2][0] >= n)
        i1 = 1, i2 = 2, c = '0';

    if (cnt[0][1] >= n && cnt[1][1] >= n)
        i1 = 0, i2 = 1, c = '1';
    if (cnt[0][1] >= n && cnt[2][1] >= n)
        i1 = 0, i2 = 2, c = '1';
    if (cnt[1][1] >= n && cnt[2][1] >= n)
        i1 = 1, i2 = 2, c = '1';

    static int add[2][200002];
    For(i, n * 2 + 1)
        add[0][i] = add[1][i] = 0;
    int ptr1 = 0, ptr2 = 0;
    For(i, n * 2)
    {
        if (s[i1][i] == c)
            ++ptr1;
        else
            ++add[0][ptr1];
        if (s[i2][i] == c)
            ++ptr2;
        else
            ++add[0][ptr2];
    }
    int m = max(cnt[i1][c - '0'], cnt[i2][c - '0']);
    string res;
    For(i, m + 1)
    {
        if (i)
            res.push_back(c);
        res.insert(res.end(), max(add[0][i], add[1][i]), c ^ 1);
    }
    res.insert(res.end(), n * 3 - sz(res), c);
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
    int t;
    cin >> t;
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}