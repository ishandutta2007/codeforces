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
#include <bitset>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

void solve()
{
    int n;
    scanf("%d", &n);
    int x = (n * 2 + 1) / 3;
    vector<pair<int, int>> ans;
    if (x % 2 == 0)
    {
        ans.emplace_back(x - 1, x - 1);
        --x;
    }
    For(i, x)
        ans.emplace_back(i, (x / 2 - i + x) % x);
    printf("%d\n", sz(ans));
    For(i, sz(ans))
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
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