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

const int MOD = 998244353;
int mul(int a, int b)
{
    return ((lint)a * b) % MOD;
}

int slow(const vector<int>& ar, int k)
{
    int n = sz(ar);
    vector<int> br(n);
    For(i, n)
        br[i] = i;
    int res = 0;
    do
    {
        static vector<int> cr;
        cr.resize(n);
        copy(all(br), cr.begin());
        For(_, k) For(i, n - 1)
            if (cr[i] > cr[i + 1])
                swap(cr[i], cr[i + 1]);
        bool succ = true;
        For(i, n)
        {
            if (ar[i] == -1)
                continue;
            int cur = 0;
            For(j, i)
                cur += cr[j] > cr[i];
            if (cur != ar[i])
            {
                succ = false;
                break;
            }
        }
        res += succ;
    } while (next_permutation(all(br)));
    return res;
}

void solve()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> ar(n);
    For(i, n)
        scanf("%d", &ar[i]);
#ifdef LOCAL
    printf("%d ", slow(ar, k));
#endif
    int res = 1;
    For(i, n)
        if (ar[i] > i)
            res = 0;
    for (int i = n - k; i < n; ++i)
        if (ar[i] > 0)
            res = 0;
    for (int i = -k; i < n - k; ++i)
    {
        int l, r;
        if (i < 0)
        {
            l = 0, r = i + k;
        }
        else
        {
            if (ar[i] == -1)
                l = 0, r = i;
            else
                l = ar[i], r = ar[i];
            if (l)
                l += k;
            r += k;
        }
        res = mul(res, r - l + 1);
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