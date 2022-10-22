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

const int MAXN = (int)4e5 + 10;

inline int f(int x)
{
    return x & (-x);
}

struct Fenvick
{
    int ar[MAXN];
    Fenvick() {}
    void add(int i, int val)
    {
        for (; i < MAXN; i += f(i + 1))
            ar[i] += val;
    }
    int get(int i)
    {
        int res = 0;
        for (; i >= 0; i -= f(i + 1))
            res += ar[i];
        return res;
    }
} tree;

struct Card
{
    int orig_a, orig_b;
    int x, y;
    bool has_less, has_more;
    Card() {}
    Card(int a_, int b_) : orig_a(a_), orig_b(b_), x(min(a_, b_)), y(max(a_, b_)), has_less(false), has_more(false) {}
    bool operator < (const Card& other) const
    {
        return x < other.x;
    }
} ar[MAXN];

#ifdef LOCAL
#define STRESS
#define STRESS_GEN
mt19937 rng(42);
#endif

void solve()
{
    int n;
#ifdef STRESS_GEN
    n = 12;
    vector<int> perm(n * 2);
    For(i, n * 2)
    {
        int j = rng() % (i + 1);
        perm[i] = perm[j];
        perm[j] = i;
    }
    For(i, n)
        ar[i] = { perm[i * 2] + 1, perm[i * 2 + 1] + 1 };
#else
    scanf("%d", &n);
    For(i, n)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        ar[i] = { a, b };
    }
#endif
    sort(ar, ar + n);
    memset(tree.ar, 0, sizeof(tree.ar));
    For(i, n)
    {
        if (tree.get(ar[i].y))
            ar[i].has_less = true;
        tree.add(ar[i].y, 1);
    }
    memset(tree.ar, 0, sizeof(tree.ar));
    for (int i = n - 1; i >= 0; --i)
    {
        if (tree.get(MAXN - ar[i].y))
            ar[i].has_more = true;
        tree.add(MAXN - ar[i].y, 1);
    }

    int res = 0;
    For(i, n)
        if (ar[i].has_less && ar[i].has_more)
            res = -1;
    if (res == 0)
    {
        vector<int> low_ones, high_ones;
        For(i, n)
            if (ar[i].has_more)
                low_ones.push_back(i);
            else if (ar[i].has_less)
                high_ones.push_back(i);
        vector<pair<int, int>> seg(sz(high_ones));
        For(i, sz(high_ones))
        {
            while (seg[i].second < sz(low_ones) && ar[low_ones[seg[i].second]].x < ar[high_ones[i]].x)
                ++seg[i].second;
            while (seg[i].first < sz(low_ones) && ar[low_ones[seg[i].first]].y > ar[high_ones[i]].y)
                ++seg[i].first;
            if (i + 1 != sz(seg))
                seg[i + 1] = seg[i];
        }
        for (int l = 0, r = 1; l < sz(high_ones); l = r++)
        {
            while (r < sz(high_ones) && seg[r - 1].second > seg[r].first)
                ++r;
            int curl = seg[l].first, curr = seg[r - 1].second;
            int add1 = 0, add2 = 0;
            for (int i = l; i < r; ++i)
            {
                if (ar[high_ones[i]].x == ar[high_ones[i]].orig_a)
                    ++add1;
                else
                    ++add2;
            }
            for (int i = curl; i < curr; ++i)
            {
                if (ar[low_ones[i]].x == ar[low_ones[i]].orig_a)
                    ++add2;
                else
                    ++add1;
            }
            if (add1 < add2)
            {
                res += add1;
                for (int i = l; i < r; ++i)
                    swap(ar[high_ones[i]].x, ar[high_ones[i]].y);
            }
            else
            {
                res += add2;
                for (int i = curl; i < curr; ++i)
                    swap(ar[low_ones[i]].x, ar[low_ones[i]].y);
            }
        }
    }

    sort(ar, ar + n);
    For(i, n - 1)
        if (ar[i].y < ar[i + 1].y)
            res = -1;
        
#ifdef STRESS
    vector<pair<int, int>> s_ar(n);
    int s_res = n + 1;
    For(mask, (1 << n))
    {
        For(i, n)
            s_ar[i] = (mask & (1 << i)) ? make_pair(ar[i].orig_a, ar[i].orig_b) : make_pair(ar[i].orig_b, ar[i].orig_a);
        sort(all(s_ar));
        bool succ = true;
        For(i, n - 1)
            succ &= s_ar[i].second > s_ar[i + 1].second;
        if (succ)
        {
            int cnt = 0;
            For(i, n)
                cnt += (mask >> i) & 1;
            s_res = min(s_res, cnt);
        }
    }
    if (s_res == n + 1)
        s_res = -1;
    printf("%d ", s_res);
    if (s_res != res)
    {
#ifdef STRESS_GEN
        printf("FUCK %d\n", res);
        printf("%d\n", n);
        For(i, n)
        {
            printf("%d %d\n", perm[i * 2] + 1, perm[i * 2 + 1] + 1);
        }
        exit(0);
#endif
    }
#endif
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
#ifdef STRESS_GEN
    For(i, 10000)
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}