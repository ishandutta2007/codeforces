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
    vector<lint> happy;
    for (int len = 1; len <= 9; ++len)
    {
        For(i, 1 << len)
        {
            lint cur = 0;
            For(j, len)
            {
                cur = cur * 10 + (4 + ((i >> (len - 1 - j)) % 2) * 3);
            }
            happy.push_back(cur);
        }
    }
    happy.push_back(4444444444ll);
    lint l, r;
    cin >> l >> r;
    lint prv = 0;
    lint res = 0;
    for (auto e : happy)
    {
        lint cur = e >= r ? r - l + 1 : e >= l ? e - l + 1 : 0;
        res += e * (cur - prv);
        prv = cur;
    }
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