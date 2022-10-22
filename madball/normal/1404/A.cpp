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
    static char s[(int)3e5 + 10];
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    For(i, n - k)
        if (s[i + k] == '?')
            s[i + k] = s[i];
    for (int i = n - k - 1; i >= 0; --i)
        if (s[i] == '?')
            s[i] = s[i + k];
    int cnt[2] { 0, 0 };
    For(i, k)
        ++cnt[s[i] - '0'];
    For(i, k)
        if (s[i] == '?')
        {
            if (cnt[0] <= cnt[1])
            {
                s[i] = '0';
                ++cnt[0];
            }
            else
            {
                s[i] = '1';
                ++cnt[1];
            }
        }
    For(i, n - k)
        if (s[i + k] == '?')
            s[i + k] = s[i];
    bool succ = cnt[0] == cnt[1];
    For(i, n - k)
        if (s[i] != s[i + k])
            succ = false;
    if (succ)
        printf("YES\n");
    else
        printf("NO\n");
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
    scanf("%d", &t);
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}