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

const int MAXN = (int)2e6 + 6;
int ar[MAXN];
int br[MAXN];
int cr[MAXN];

vector<int> doit(int n, int m)
{
    fill(br, br + n * m * 2 + 1, 0);
    fill(cr, cr + n * m * 2 + 1, 0);
    For(i, n * m * 2 + 1)
        br[i] = ar[i] + (i ? br[i - 1] : 0);

    for (int i = m; i <= n * m * 2; ++i)
        cr[i] = br[i] != br[i - m];
    vector<int> res(cr, cr + n * m * 2 + 1);
    for (int i = m; i < sz(res); ++i)
        res[i] += res[i - m];
    return res;
}

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    fill(ar, ar + n * m * 2 + 1, 0);
    vector<int> first_in_col(m, n);
    For(i, n * m)
    {
        char c;
        scanf(" %c", &c);
        ar[n * m + i] = c - '0';
        if (c == '1')
            first_in_col[i % m] = min(first_in_col[i % m], i / m);
    }
    vector<int> res1 = doit(n, m);
    vector<int> res2(res1.size(), 0);
    for (int i = 0; i < m; ++i)
        for (int j = first_in_col[i]; j < n; ++j)
            ++res2[n * m + i + j * m];
    For(i, sz(res2) - 1)
        res2[i + 1] += res2[i];
    for (int i = n * m; i < n * m * 2; ++i)
        printf("%d ", res1[i] + res2[i] - res2[i - m]);
    printf("\n");
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