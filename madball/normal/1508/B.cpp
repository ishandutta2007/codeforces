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
#include <intrin.h>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

void solve()
{
    int n;
    lint k;
    scanf("%d %lld", &n, &k);
    if (n <= 61 && k > (1ll << (n - 1)))
    {
        printf("-1\n");
        return;
    }
    --k;
    static int ar[100500];
    For(i, n)
        ar[i] = i + 1;
    int prv = 0;
    For(i, n)
    {
        if ((k & 1) == 0)
        {
            reverse(ar + n - i - 1, ar + n - prv);
            prv = i + 1;
        }
        k >>= 1;
    }
    For(i, n)
        printf("%d%c", ar[i], (i + 1 == n ? '\n' : ' '));

    /*vector<int> perm(n);
    For(i, n)
        perm[i] = i;
    do
    {
        bool succ = true;
        For(i, n - 1)
            if (perm[i + 1] + 1 < perm[i])
            {
                succ = false;
                break;
            }
        if (succ)
            For(i, n)
                printf("%d%c", perm[i], (i + 1 == n ? '\n' : ' '));
    } while (next_permutation(all(perm)));*/
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
    scanf("%d", &t);
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}