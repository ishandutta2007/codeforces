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

const int MAXN = (int)5e5 + 5;
const lint MINF = -(lint)1e18;
lint ar[MAXN];
lint psum[MAXN];
//lint dp[MAXN];
pair<lint, int> by_psum[MAXN];
int in_by_psum[MAXN];

struct Fenvick
{
    lint ar[MAXN];
    int n;
    Fenvick() {}
    void init(int n_)
    {
        n = n_;
        fill(ar, ar + n, MINF);
    }
    void put(int i, lint val)
    {
        for (; i < n; i += (i + 1) & -(i + 1))
            ar[i] = max(ar[i], val);
    }
    lint get(int i)
    {
        lint res = MINF;
        for (; i >= 0; i -= (i + 1) & -(i + 1))
            res = max(res, ar[i]);
        return res;
    }
} tree[3];

void update_tree(int treei, lint threshold, lint val, int n)
{
    auto it = lower_bound(by_psum, by_psum + n, make_pair(threshold, 0));
    tree[treei].put((int)(it - by_psum), val);
}

void solve()
{
    lint cur_psum = 0;
    int n;
    scanf("%d", &n);
    tree[0].init(n);
    tree[1].init(n);
    tree[2].init(n);
    For(i, n)
    {
        scanf("%lld", &ar[i]);
        cur_psum += ar[i];
        psum[i] = cur_psum;
        by_psum[i] = { cur_psum, i };
    }
    sort(by_psum, by_psum + n);
    For(i, n)
        in_by_psum[by_psum[i].second] = i;
    update_tree(0, 1, 1, n);
    update_tree(1, 0, 0, n);
    update_tree(2, MINF, -1, n);

    For(i, n)
    {
        lint cur_val = max(max(
            tree[0].get(in_by_psum[i]) + i,
            tree[1].get(in_by_psum[i])),
            tree[2].get(in_by_psum[i]) - i);
        update_tree(0, psum[i] + 1, cur_val - i, n);
        update_tree(1, psum[i], cur_val, n);
        update_tree(2, MINF, cur_val + i, n);
        if (i + 1 == n)
            printf("%lld\n", cur_val);
#ifdef LOCAL
        else
            printf("%lld ", cur_val);
#endif
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
    int t;
    scanf("%d", &t);
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}