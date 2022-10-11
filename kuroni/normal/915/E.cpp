#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int Q = 3E5 + 5;

struct TQuery
{
    int l, r, t;
} a[Q];
struct TNode
{
    int val, lazy;
} tree[8 * Q];
int n, q;
vector<int> s;

int get(int u)
{
    return lower_bound(s.begin(), s.end(), u) - s.begin() + 1;
}

void down(int i, int l, int r, int m)
{
    if (tree[i].lazy == 1)
    {
        tree[2 * i].lazy = tree[2 * i + 1].lazy = 1;
        tree[2 * i].val = tree[2 * i + 1].val = 0;
    }
    else if (tree[i].lazy == 2)
    {
        tree[2 * i].lazy = tree[2 * i + 1].lazy = 2;
        tree[2 * i].val = s[m] - s[l - 1];
        tree[2 * i + 1].val = s[r] - s[m];
    }
    tree[i].lazy = 0;
}

void upd(int l, int r, int i, int L, int R, int v)
{
    if (l > R || r < L)
        return;
    else if (L <= l && r <= R)
    {
        tree[i].lazy = v;
        if (v == 1)
            tree[i].val = 0;
        else tree[i].val = s[r] - s[l - 1];
        return;
    }
    int m = (l + r) >> 1;
    down(i, l, r, m);
    upd(l, m, 2 * i, L, R, v);
    upd(m + 1, r, 2 * i + 1, L, R, v);
    tree[i].val = tree[2 * i].val + tree[2 * i + 1].val;
}

int main()
{
    scanf("%d%d", &n, &q);
    s.push_back(1);
    s.push_back(n + 1);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].t);
        s.push_back(a[i].l);
        s.push_back(++a[i].r);
    }
    sort(s.begin(), s.end());
    s.resize(unique(s.begin(), s.end()) - s.begin());
    n = s.size();
    upd(1, n - 1, 1, 1, n - 1, 2);
    for (int i = 1; i <= q; i++)
    {
        upd(1, n - 1, 1, get(a[i].l), get(a[i].r) - 1, a[i].t);
        printf("%d\n", tree[1].val);
    }
}