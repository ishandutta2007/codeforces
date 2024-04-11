#include <iostream>
#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pii pair<int, int>
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;

const int N = 200005;

int n, q, t, l, r, u, v, a[N], b[N];
tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> bit[N];

void add(int u, int v)
{
    for (int i = u; i <= n; i += i & -i)
        bit[i].insert(mp(v, u));
}

void rem(int u, int v)
{
    for (int i = u; i <= n; i += i & -i)
        bit[i].erase(mp(v, u));
}

int que(int u, int v)
{
    int ret = 0;
    for (int i = u; i > 0; i -= i & -i)
        ret += bit[i].order_of_key(mp(v + 1, 0));
    return ret;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &u);
        a[u] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", b + i);
        b[i] = a[b[i]];
        add(i, b[i]);
    }
    while (q--)
    {
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1)
        {
            scanf("%d%d", &u, &v);
            printf("%d\n", que(v, r) - que(v, l - 1) - que(u - 1, r) + que(u - 1, l - 1));
        }
        else
        {
            rem(l, b[l]);
            rem(r, b[r]);
            swap(b[l], b[r]);
            add(l, b[l]);
            add(r, b[r]);
        }
    }
}