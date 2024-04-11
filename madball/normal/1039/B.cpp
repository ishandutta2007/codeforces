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

bool ask(lint l, lint r)
{
    printf("%lld %lld\n", l + 1, r);
    fflush(stdout);
    static char res[4];
    scanf(" %s", res);
    if (res[0] == 'B')
        exit(0);
    if (res[0] == 'Y')
    {
        if (l + 1 == r)
            exit(0);
        return true;
    }
    return false;
}

void solve()
{
    lint n;
    int k;
    scanf("%lld %d", &n, &k);
    lint l = 0, r = n;
    mt19937_64 rng(42);
    while (true)
    {
        while (r - l >= 4 * k + 2)
        {
            lint m = (l + r) / 2;
            if (ask(l, m))
                r = m;
            else
                l = m;
            l = max(0ll, l - k);
            r = min(n, r + k);
        }
        lint x = rng() % (r - l) + l;
        ask(x, x + 1);
        l = max(0ll, l - k);
        r = min(n, r + k);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}