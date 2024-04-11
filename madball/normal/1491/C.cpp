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

int ar[5050];
int par[5050];

void solve()
{
    int n;
    cin >> n;
    For(i, n)
    {
        cin >> ar[i];
        par[i] = i + 1;
    }
    lint res = -1;
    int kek = 0;
    while (true)
    {
        ++res;
        if ((res & 4095) == 0)
        {
            for (int i = n - 2; i >= 0; --i)
                if (ar[i] == 1 && ar[i + 1] == 1)
                    par[i] = par[i + 1];
        }
        bool wut = true;
        int cur = kek;
        while (cur < n)
        {
            if (wut)
                kek = cur;
            int nxt = cur + ar[cur];
            if (wut && ar[cur] > n)
            {
                res += ar[cur] - n;
                ar[cur] -= ar[cur] - n;
            }
            if (ar[cur] != 1)
            {
                wut = false;
                --ar[cur];
            }
            else
                nxt = par[cur];
            cur = nxt;
        }
        if (wut)
            break;
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
    int t;
    cin >> t;
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}