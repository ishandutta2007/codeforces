#include <iostream>
#include <cstdio>

using namespace std;

const int N = 4 * 100 * 1000 + 10;
const int MOD = 95542721;
const int PER = 48;
int value[N][PER];
int add[N];
int a[N];

int left_child(int index)
{
    return 2 * index + 1;
}

int right_child(int index)
{
    return 2 * index + 2;
}

void build_tree(int index, int l, int r)
{
    add[index] = 0;
    if (l == r)
    {
        long long curr = a[l] % MOD;
        for (int power = 0; power < PER; ++power)
        {
            value[index][power] = curr;
            curr = curr * curr % MOD * curr % MOD;
        }
    }
    else
    {
        int mid = (l + r) / 2;
        build_tree(left_child(index), l, mid);
        build_tree(right_child(index), mid + 1, r);
        for (int power = 0; power < PER; power++)
        {
            value[index][power] = (value[left_child(index)][power] + value[right_child(index)][power]) % MOD;
        }
    }
}

int get_sum(int index, int l, int r, int node_l, int node_r, int curr_add)
{
    curr_add += add[index];
    curr_add %= PER;
    if (l == node_l && r == node_r)
    {
        return value[index][curr_add];
    }
    int sum_l = 0;
    int sum_r = 0;
    int mid = (node_l + node_r) / 2;
    if (l <= mid)
    {
        sum_l = get_sum(left_child(index), l, min(r, mid), node_l, mid, curr_add);
    }
    if (r > mid)
    {
        sum_r = get_sum(right_child(index), max(l, mid + 1), r, mid + 1, node_r, curr_add);
    }
    return (sum_l + sum_r) % MOD;
}

void update(int index, int l, int r, int node_l, int node_r)
{
    if (l == node_l && r == node_r)
    {
        add[index]++;
        add[index] %= PER;
    }
    else
    {
        int mid = (node_l + node_r) / 2;
        if (l <= mid)
        {
            update(left_child(index), l, min(r, mid), node_l, mid);
        }
        if (r > mid)
        {
            update(right_child(index), max(l, mid + 1), r, mid + 1, node_r);
        }
        for (int power = 0; power < PER; power++)
        {
            value[index][power] = (get_sum(left_child(index), 0, 0, 0, 0, power) + get_sum(right_child(index), 0, 0, 0, 0, power)) % MOD;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    build_tree(0, 0, n - 1);

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        int type, l, r;
        scanf("%d%d%d", &type, &l, &r);

        l--;
        r--;
        if (type == 1)
        {
            printf("%d\n", get_sum(0, l, r, 0, n - 1, 0));
        }
        else
        {
            update(0, l, r, 0, n - 1);
        }
    }
}