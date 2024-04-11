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

const int MOD = (int)1e9 + 7;
int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
int mul(int a, int b)
{
    return ((lint)a * b) % MOD;
}
int pw(int a, int b)
{
    return b == 0 ? 1 : b % 2 ? mul(a, pw(a, b - 1)) : pw(mul(a, a), b / 2);
}

int fact[2000001];
int ifact[2000001];
int ar[2000001];

int c(int n, int k)
{
    if (k < 0 || k > n)
        throw;
    return mul(fact[n], mul(ifact[k], ifact[n - k]));
}
void solve()
{
    fact[0] = 1;
    For(i, 2000000)
        fact[i + 1] = mul(fact[i], i + 1);
    ifact[2000000] = pw(fact[2000000], MOD - 2);
    For(i, 2000000)
        ifact[1999999 - i] = mul(ifact[2000000 - i], 2000000 - i);
    ar[1] = 1;
    For(i, 1999999)
        ar[i + 2] = add(ar[i + 1], ar[i + 1]);
    For(i, 2000000)
        ar[i + 1] = mul(ar[i + 1], i + 1);
    int t;
    scanf("%d", &t);
    For(i, t)
    {
        int m, n, k;
        scanf("%d %d %d", &n, &m, &k);
        int res = 0;
        if (n == m)
        {
            printf("%d\n", mul(n, k));
            continue;
        }
        if (m * 2 < n)
            For(j, m + 1)
                res = add(res, mul(ar[j], c(n - 1 - j, m - j)));
        else
            For(j, m + 1)
                res = add(res, mul(ar[j], c(n - 1 - j, n - m - 1)));
        printf("%d\n", mul(mul(res, k), pw(500000004, n - 1)));
    }
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