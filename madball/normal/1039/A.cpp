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

const int MAXN = (int)2e5 + 10;

lint ar[MAXN];
int perm[MAXN];
lint br[MAXN];
int fuck[MAXN];
int fuckfuck[MAXN];

void solve()
{
    int n;
    lint t;
    cin >> n >> t;
    For(i, n)
        cin >> ar[i];
    For(i, n)
    {
        cin >> perm[i];
        --perm[i];
        if (i && perm[i] < perm[i - 1])
        {
            cout << "No\n";
            return;
        }
    }
    if (perm[n - 1] != n - 1)
    {
        cout << "No\n";
        return;
    }
    For(i, n)
    {
        ++fuck[i];
        --fuck[perm[i]];
    }
    For(i, n - 1)
        fuck[i + 1] += fuck[i];
    For(i, n)
        br[i] = ar[i + (bool)fuck[i]] + t;
    For(i, n - 1)
        br[i + 1] = max(br[i + 1], br[i] + 1);
    For(i, n)
        fuckfuck[i] = lower_bound(br, br + n, ar[i] + t) - br;
    int fuckfuckfuck = n - 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (fuckfuckfuck > perm[i])
        {
            cout << "No\n";
            return;
        }
        if (fuckfuckfuck < perm[i])
            throw;
        if (fuckfuck[i] == i)
            fuckfuckfuck = i - 1;
    }
    cout << "Yes\n";
    For(i, n)
        cout << br[i] << ' ';
    cout << '\n';
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