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

const int MAXN = 262144;

struct Tree
{
    int val[MAXN * 2];
    char pushed[MAXN * 2];
    int size;
    Tree() {}
    void init(int n)
    {
        size = 1;
        while (size < n)
            size <<= 1;
        memset(val, 0, sizeof(int) * size * 2);
        memset(pushed, 0, sizeof(char) * size * 2);
    }
    void push(int v, int l, int r)
    {
        if (pushed[v])
        {
            val[v] = pushed[v] == 1 ? r - l : 0;
            if (v < size)
                pushed[v * 2] = pushed[v * 2 + 1] = pushed[v];
            pushed[v] = 0;
        }
    }
    int get(int v, int l, int r, int segl, int segr)
    {
        if (segr <= l || r <= segl)
            return 0;
        push(v, l, r);
        if (segl <= l && r <= segr)
            return val[v];
        return get(v * 2, l, (l + r) / 2, segl, segr) + get(v * 2 + 1, (l + r) / 2, r, segl, segr);
    }
    int get(int l, int r)
    {
        return get(1, 0, size, l, r);
    }
    void put(int v, int l, int r, int segl, int segr, char va)
    {
        if (segr <= l || r <= segl)
            return;
        if (segl <= l && r <= segr)
        {
            pushed[v] = va;
            return;
        }
        push(v, l, r);
        put(v * 2, l, (l + r) / 2, segl, segr, va);
        push(v * 2, l, (l + r) / 2);
        put(v * 2 + 1, (l + r) / 2, r, segl, segr, va);
        push(v * 2 + 1, (l + r) / 2, r);
        val[v] = val[v * 2] + val[v * 2 + 1];
    }
    void put(int l, int r, char va)
    {
        put(1, 0, size, l, r, va * 2 - 1);
    }
} tree;

void solve()
{
    int n, q;
    scanf("%d %d", &n, &q);
    static char s[MAXN];
    static char t[MAXN];
    scanf(" %s %s", s, t);
    tree.init(n);
    For(i, n)
        tree.put(i, i + 1, t[i] - '0');
    static pair<int, int> qu[MAXN];
    For(i, q)
        scanf("%d %d", &qu[i].first, &qu[i].second);
    reverse(qu, qu + q);
    For(i, q)
    {
        int l, r;
        tie(l, r) = qu[i];
        --l;
        int s = tree.get(l, r);
        if (s * 2 < r - l)
            tree.put(l, r, 0);
        else if (s * 2 > r - l)
            tree.put(l, r, 1);
        else
        {
            printf("NO\n");
            return;
        }
    }
    For(i, n)
        if (tree.get(i, i + 1) != s[i] - '0')
        {
            printf("NO\n");
            return;
        }
    printf("YES\n");
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