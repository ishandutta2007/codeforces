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

const int MAXN = 1 << 17;

struct Tree
{
    int cnt0[MAXN * 2];
    int cnt1[MAXN * 2];
    int n;
    Tree() {}
    void init(int n_)
    {
        n = n_;
        for (int i = 0; i < n; ++i)
            cnt0[n + i] = 1;
        for (int i = n - 1; i; --i)
            cnt0[i] = cnt0[i * 2] + cnt0[i * 2 + 1];
    }
    void change(int i)
    {
        i += n;
        swap(cnt0[i], cnt1[i]);
        for (i >>= 1; i; i >>= 1)
            cnt0[i] = cnt0[i * 2] + cnt0[i * 2 + 1], cnt1[i] = cnt1[i * 2] + cnt1[i * 2 + 1];
    }
} tree;

void solve()
{
    int n, q;
    scanf("%d %d", &n, &q);
    tree.init(n);
    for (int i = 0; i < n; ++i)
    {
        int a;
        scanf("%d", &a);
        if (a)
            tree.change(i);
    }
    For(qi, q)
    {
        int t, i;
        scanf("%d %d", &t, &i);
        if (t == 1)
        {
            tree.change(i - 1);
        }
        else
        {
            printf("%d\n", (int)(tree.cnt1[1] >= i));
        }
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