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

const int MOD = 998244353;
int ar[100500];
int br[100500];
int psum[100500];

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

void solve()
{
    int n;
    scanf("%d", &n);
    For(i, n)
        scanf("%d", &ar[i]);
#ifdef LOCAL
    int s_res = 0;
    For(j, n + 1)
        For(i, j)
        {
            int cur = 0;
            int prv = ar[j - 1];
            for (int k = j - 2; k >= i; --k)
            {
                int dv = 1;
                while ((ar[k] + dv - 1) / dv > prv)
                    ++dv;
                cur = add(cur, dv - 1);
                prv = ar[k] / dv;
            }
            s_res = add(s_res, cur);
        }
    printf("%d ", s_res);
#endif
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        br[i] = 1;
        int prv = ar[i];
        for (int j = i - 1; j >= 0; --j)
        {
            int k = (ar[j] + prv - 1) / prv;
            psum[j] = add(j ? psum[j - 1] : 0, mul(k - 1, j + 1));
            if (k == br[j] || j == 0)
            {
                br[j] = k;
                res = add(res, psum[j]);
                for (++j; j <= i; ++j)
                    psum[j] = add(psum[j - 1], mul(br[j] - 1, j + 1));
                break;
            }
            br[j] = k;
            prv = ar[j] / br[j];
            res = add(res, mul(br[j] - 1, j + 1));
        }
    }
    printf("%d\n", res);
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