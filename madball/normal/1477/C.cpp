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

inline lint di(const pair<lint, lint>& a, const pair<lint, lint> &b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void solve()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, pair<lint, lint>>> ar(n);
    For(i, n)
    {
        scanf("%lld %lld", &ar[i].second.first, &ar[i].second.second);
        ar[i].first = i + 1;
    }
    printf("%d", 1);
    pair<lint, lint> cur = ar[0].second;
    ar.erase(ar.begin());
    For(_, n - 1)
    {
        int nxt_i = 0;
        for (int i = 1; i < sz(ar); ++i)
            if (di(ar[i].second, cur) > di(ar[nxt_i].second, cur))
                nxt_i = i;
        printf(" %d", ar[nxt_i].first);
        cur = ar[nxt_i].second;
        ar.erase(ar.begin() + nxt_i);
    }
    printf("\n");
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