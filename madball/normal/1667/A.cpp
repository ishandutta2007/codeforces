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
    cin >> n;
    vector<lint> ar(n);
    For(i, n)
        cin >> ar[i];
    lint res = (lint)1e18;
    vector<lint> br(n);
    For(i, n)
    {
        fill(all(br), 0);
        lint cur = 0;
        for (int j = i + 1; j < n; ++j)
        {
            // ar[j] * x > br[j - 1]
            // ar[j] * (x - 1) <= br[j - 1]
            // x - 1 = br[j - 1] / ar[j]
            lint x = br[j - 1] / ar[j] + 1;
            cur += x;
            br[j] = ar[j] * x;
        }
        for (int j = i - 1; j >= 0; --j)
        {
            lint x = br[j + 1] / ar[j] + 1;
            cur += x;
            br[j] = ar[j] * x;
        }
        res = min(res, cur);
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