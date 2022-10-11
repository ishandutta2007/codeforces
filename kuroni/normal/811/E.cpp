#include <iostream>
#include <cstdio>
using namespace std;

struct point
{
    int x, y;
};
struct save
{
    int val = 0, l, r, depth[15][2];
    point par[15][2];
} tree[400005];
int f[15][100005], n, m, q, i, j, l, r;
struct bridge
{
    point par[15][4];
    int depth[15][4];
} tmp;

bool operator == (const point &a, const point &b)
{
    return a.x == b.x && a.y == b.y;
}

point trace_1(save &a, int x, int y)
{
    if (x != a.par[x][y].x || y != a.par[x][y].y)
        a.par[x][y] = trace_1(a, a.par[x][y].x, a.par[x][y].y);
    return a.par[x][y];
}

bool unity_1(save &a, int x, int y, int z, int t)
{
    point root_a = trace_1(a, x, y), root_b = trace_1(a, z, t);
    if (root_a == root_b)
        return 0;
    if (a.depth[root_a.x][root_a.y] < a.depth[root_b.x][root_b.y])
        a.par[root_a.x][root_a.y] = root_b;
    else if (a.depth[root_a.x][root_a.y] > a.depth[root_b.x][root_b.y])
        a.par[root_b.x][root_b.y] = root_a;
    else
    {
        a.depth[root_b.x][root_b.y]++;
        a.par[root_b.x][root_b.y] = root_a;
    }
    return 1;
}

void init_1(save &a, int l)
{
    a.l = a.r = l; a.val = n;
    for (int i = 1; i <= n; i++)
    {
        a.par[i][0] = {i, 0};
        a.depth[i][0] = 0;
        if (f[i - 1][l] == f[i][l])
            a.val -= unity_1(a, i - 1, 0, i, 0);
    }
    for (int i = 1; i <= n; i++)
    {
        a.par[i][1] = a.par[i][0];
        a.depth[i][1] = a.depth[i][0] + 1;
    }
}

point trace_2(bridge &a, int x, int y)
{
    if (x != a.par[x][y].x || y != a.par[x][y].y)
        a.par[x][y] = trace_2(a, a.par[x][y].x, a.par[x][y].y);
    return a.par[x][y];
}

bool unity_2(bridge &a, int x, int y, int z, int t)
{
    point root_a = trace_2(a, x, y), root_b = trace_2(a, z, t);
    if (root_a == root_b)
        return 0;
    if (a.depth[root_a.x][root_a.y] < a.depth[root_b.x][root_b.y])
        a.par[root_a.x][root_a.y] = root_b;
    else if (a.depth[root_a.x][root_a.y] > a.depth[root_b.x][root_b.y])
        a.par[root_b.x][root_b.y] = root_a;
    else
    {
        a.depth[root_b.x][root_b.y]++;
        a.par[root_b.x][root_b.y] = root_a;
    }
    return 1;
}

void init_2(bridge &x, const save &a, const save &b)
{
    for (int i = 1; i <= n; i++)
    {
        x.par[i][0] = a.par[i][0];
        x.depth[i][0] = a.depth[i][0];

        x.par[i][1] = a.par[i][1];
        x.depth[i][1] = a.depth[i][1];

        x.par[i][2] = b.par[i][0];
        x.par[i][2].y += 2;
        x.depth[i][2] = b.depth[i][0];

        x.par[i][3] = b.par[i][1];
        x.par[i][3].y += 2;
        x.depth[i][3] = b.depth[i][1];
    }
}

save compress(save a, save b)
{
    init_2(tmp, a, b);
    save ans;
    ans.l = a.l; ans.r = b.r; ans.val = a.val + b.val;
    for (int i = 1; i <= n; i++)
    {
        if (f[i][a.r] == f[i][b.l])
        {
            ans.val -= unity_2(tmp, i, 1, i, 2);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans.par[i][0] = trace_2(tmp, i, 0);
        if (ans.par[i][0].y > 0 && ans.par[i][0].y < 3)
        {
            tmp.par[ans.par[i][0].x][ans.par[i][0].y] = {i, 0};
            tmp.par[i][0] = ans.par[i][0] = {i, 0};
        }
        if (ans.par[i][0].y == 3)
            ans.par[i][0].y = 1;
        ans.par[i][1] = trace_2(tmp, i, 3);
        if (ans.par[i][1].y > 0 && ans.par[i][1].y < 3)
        {
            tmp.par[ans.par[i][1].x][ans.par[i][1].y] = {i, 3};
            tmp.par[i][3] = ans.par[i][1] = {i, 3};
        }
        if (ans.par[i][1].y == 3)
            ans.par[i][1].y = 1;
    }
    return ans;
}

save build_tree(int l, int r, int ind)
{
    if (l == r)
        init_1(tree[ind], l);
    else tree[ind] = compress(build_tree(l, (l + r) / 2, 2 * ind), build_tree((l + r) / 2 + 1, r, 2 * ind + 1));
    return tree[ind];
}

save query(int l, int r, int L, int R, int ind)
{
    if (l <= L && R <= r)
        return tree[ind];
    else if (r <= (L + R) / 2)
        return query(l, r, L, (L + R) / 2, 2 * ind);
    else if (l >= (L + R) / 2 + 1)
        return query(l, r, (L + R) / 2 + 1, R, 2 * ind + 1);
    else return compress(query(l, r, L, (L + R) / 2, 2 * ind), query(l, r, (L + R) / 2 + 1, R, 2 * ind + 1));
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        scanf("%d", &f[i][j]);
    build_tree(1, m, 1);
    while (q--)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r, 1, m, 1).val);
    }
}