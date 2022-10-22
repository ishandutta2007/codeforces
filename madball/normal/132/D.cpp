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

char s[1000500];
vector<int> res;

void solve()
{
    scanf("%s", s);
    int n = strlen(s);
    s[n] = '0';
    reverse(s, s + n);
    reverse(s, s + n + 1);
    for (int i = n; i >= 0; --i)
    {
        if (i && s[i] == '1' && s[i - 1] == '1')
        {
            res.push_back(-i);
            int j;
            for (j = i; s[j] == '1'; --j)
                s[j] = '0';
            s[j] = '1';
        }
        if (s[i] == '1')
            res.push_back(i);
    }
    printf("%d\n", sz(res));
    for (auto e : res)
        if (e < 0)
            printf("-2^%d\n", n + e);
        else
            printf("+2^%d\n", n - e);
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