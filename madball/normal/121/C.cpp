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

lint fact[16];

bool is_happy(int n)
{
    if (n == 0)
        return true;
    if (n % 10 != 4 && n % 10 != 7)
        return false;
    return is_happy(n / 10);
}

void solve()
{
    fact[0] = 1;
    For(i, 15)
        fact[i + 1] = fact[i] * (i + 1);
    int n, k;
    cin >> n >> k;
    if (n <= 14 && k > fact[n])
    {
        cout << "-1\n";
        return;
    }

    vector<int> suf;
    for (int i = max(n - 13, 1); i <= n; ++i)
        suf.push_back(i);

    int res = 0;
    for (int len = 1; len <= 9; ++len)
    {
        For(i, 1 << len)
        {
            lint cur = 0;
            For(j, len)
                cur = cur * 10 + (4 + ((i >> (len - 1 - j)) % 2) * 3);
            if (cur < suf[0])
                ++res;
        }
    }

    vector<int> suf2(sz(suf));
    for (int i = 0; i < sz(suf2); ++i)
    {
        for (int j = 0; j < sz(suf); ++j)
            if (k <= fact[sz(suf2) - i - 1])
            {
                suf2[i] = suf[j];
                suf.erase(suf.begin() + j);
                break;
            }
            else
                k -= fact[sz(suf2) - i - 1];
    }
    For(i, sz(suf2))
    {
        if (is_happy(suf2[sz(suf2) - 1 - i]) && is_happy(n - i))
            ++res;
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