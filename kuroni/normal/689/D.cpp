#include <iostream>
#include <stdio.h>

using namespace std;

int min_tree[1000000], max_tree[1000000], a[200005], b[200005], x = 0, y = 1, i, n, save_max, save_min;
long long ans = 0;

inline int max(const int &a, const int &b)
{
    if (a < b)
        return b;
    else return a;
}

inline int min(const int &a, const int &b)
{
    if (a < b)
        return a;
    else return b;
}

void build_tree_max(const int &l, const int &r, const int &ind)
{
    if (l == r)
        max_tree[ind] = a[l];
    else
    {
        build_tree_max(l, (l + r) / 2, 2 * ind);
        build_tree_max((l + r) / 2 + 1, r, 2 * ind + 1);
        max_tree[ind] = max(max_tree[2 * ind], max_tree[2 * ind + 1]);
    }
}

void build_tree_min(const int &l, const int &r, const int &ind)
{
    if (l == r)
        min_tree[ind] = b[l];
    else
    {
        build_tree_min(l, (l + r) / 2, 2 * ind);
        build_tree_min((l + r) / 2 + 1, r, 2 * ind + 1);
        min_tree[ind] = min(min_tree[2 * ind], min_tree[2 * ind + 1]);
    }
}

int get_max(const int &l, const int &r, const int &x, const int &y, const int &ind)
{
    if (l >= x && r <= y)
        return max_tree[ind];
    else if (l > y || r < x)
        return -2000000000;
    else return max(get_max(l, (l + r) / 2, x, y, 2 * ind), get_max((l + r) / 2 + 1, r, x, y, 2 * ind + 1));
}

int get_min(const int &l, const int &r, const int &x, const int &y, const int &ind)
{
    if (l >= x && r <= y)
        return min_tree[ind];
    else if (l > y || r < x)
        return 2000000000;
    else return min(get_min(l, (l + r) / 2, x, y, 2 * ind), get_min((l + r) / 2 + 1, r, x, y, 2 * ind + 1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
        cin >> b[i];
    build_tree_max(1, n, 1);
    build_tree_min(1, n, 1);
    for (i = 1; i <= n; i++)
    {
        save_max = get_max(1, n, i, y, 1);
        save_min = get_min(1, n, i, y, 1);
        while (y <= n && save_max <= save_min)
        {
            y++;
            save_max = max(save_max, a[y]);
            save_min = min(save_min, b[y]);
        }
        save_max = get_max(1, n, i, x + 1, 1);
        save_min = get_min(1, n, i, x + 1, 1);
        while (x < n && save_max < save_min)
        {
            x++;
            save_max = max(save_max, a[x + 1]);
            save_min = min(save_min, b[x + 1]);
        }
        ans += y - x - 1;
    }
    cout << ans;
}