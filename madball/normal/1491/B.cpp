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
    lint u, v;
    cin >> n >> u >> v;
    int mn = (int)1e9, mx = 0;
    int prv = -1;
    bool kek = false;
    For(i, n)
    {
        int a;
        cin >> a;
        if (i && abs(a - prv) >= 2)
        {
            kek = true;
        }
        prv = a;
        mn = min(mn, a);
        mx = max(mx, a);
    }
    if (kek)
    {
        cout << "0\n";
        return;
    }
    if (mn == mx)
        cout << v + min(v, u) << '\n';
    else
        cout << min(v, u) << '\n';
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