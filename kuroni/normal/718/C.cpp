#include <iostream>
#include <cstdio>
using namespace std;

const int mod = 1e9 + 7;
int i, n, m, a[100005], t, l, r, x;

class fib_mat
{
public:

    long long f[3][3];

    fib_mat operator + (const fib_mat &b)
    {
        fib_mat ans;
        ans.f[0][0] = (f[0][0] + b.f[0][0]) % mod;
        ans.f[0][1] = (f[0][1] + b.f[0][1]) % mod;
        ans.f[1][0] = (f[1][0] + b.f[1][0]) % mod;
        ans.f[1][1] = (f[1][1] + b.f[1][1]) % mod;
        return ans;
    }

    fib_mat operator * (const fib_mat &b)
    {
        fib_mat ans;
        ans.f[0][0] = (f[0][0] * b.f[0][0] + f[0][1] * b.f[1][0]) % mod;
        ans.f[0][1] = (f[0][0] * b.f[0][1] + f[0][1] * b.f[1][1]) % mod;
        ans.f[1][0] = (f[1][0] * b.f[0][0] + f[1][1] * b.f[1][0]) % mod;
        ans.f[1][1] = (f[1][0] * b.f[0][1] + f[1][1] * b.f[1][1]) % mod;
        return ans;
    }

    fib_mat operator ^ (const int &b)
    {
        if (b == 1)
            return *this;
        fib_mat ans = (*this) ^ (b / 2);
        ans = ans * ans;
        if (b & 1)
            ans = ans * (*this);
        return ans;
    }

} base, low_base, tmp;

struct node
{
    fib_mat val, lazy;
} tree[400005];

void down(int ind)
{
    tree[2 * ind].val = tree[2 * ind].val * tree[ind].lazy;
    tree[2 * ind].lazy = tree[2 * ind].lazy * tree[ind].lazy;

    tree[2 * ind + 1].val = tree[2 * ind + 1].val * tree[ind].lazy;
    tree[2 * ind + 1].lazy = tree[2 * ind + 1].lazy * tree[ind].lazy;

    tree[ind].lazy = low_base;
}

void build(int l, int r, int ind)
{
    tree[ind].lazy = low_base;
    if (l == r)
    {
        if (a[l] == 0)
            tree[ind].val = low_base;
        else tree[ind].val = base ^ a[l];
        return;
    }
    build(l, (l + r) / 2, 2 * ind);
    build((l + r) / 2 + 1, r, 2 * ind + 1);
    tree[ind].val = tree[2 * ind].val + tree[2 * ind + 1].val;
}

void upd(int l, int r, int ind, int L, int R)
{
    if (l > R || r < L)
        return;
    if (L <= l && r <= R)
    {
        tree[ind].val = tree[ind].val * tmp;
        tree[ind].lazy = tree[ind].lazy * tmp;
        return;
    }
    down(ind);
    upd(l, (l + r) / 2, 2 * ind, L, R);
    upd((l + r) / 2 + 1, r, 2 * ind + 1, L, R);
    tree[ind].val = tree[2 * ind].val + tree[2 * ind + 1].val;
}

long long query(int l, int r, int ind, int L, int R)
{
    if (l > R || r < L)
        return 0;
    if (L <= l && r <= R)
        return tree[ind].val.f[0][0];
    down(ind);
    return (query(l, (l + r) / 2, 2 * ind, L, R) + query((l + r) / 2 + 1, r, 2 * ind + 1, L, R)) % mod;
}

int main()
{
    base.f[0][0] = base.f[0][1] = base.f[1][0] = 1; base.f[1][1] = 0;
    low_base.f[0][0] = low_base.f[1][1] = 1; low_base.f[0][1] = low_base.f[1][0] = 0;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        --a[i];
    }
    build(1, n, 1);
    while (m--)
    {
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1)
        {
            scanf("%d", &x);
            tmp = base ^ x;
            upd(1, n, 1, l, r);
        }
        else printf("%I64d\n", query(1, n, 1, l, r));
    }
}