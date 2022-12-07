#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>

using namespace std;

#define endl '\n'

struct segment_tree_max
{
    vector<int> data;

    segment_tree_max(int n)
    {
        data = vector<int>(4 * n);
    }

    void update(int p, int b, int e, int x, int v)
    {
        if (b + 1 == e)
        {
            data[p] = v;
        }
        else
        {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            if (x < m)
                update(l, b, m, x, v);
            else
                update(r, m, e, x, v);

            data[p] = max(data[l], data[r]);
        }
    }

    int big(int p, int b, int e, int x, int y)
    {
        if (x <= b && e <= y)
        {
            return data[p];
        }
        else
        {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            int u = 0;

            if (x < m)
                u = max(u, big(l, b, m, x, y));
            if (m < y)
                u = max(u, big(r, m, e, x, y));
            return u;
        }
    }
};

struct segment_tree_min_sum
{
    vector<int> st, lz;

    segment_tree_min_sum(int n)
    {
        st = vector<int>(4 * n);
        lz = vector<int>(4 * n);
    }

    void push(int p, int l, int r)
    {
        if (lz[p])
        {
            lz[l] += lz[p];
            st[l] += lz[p];
            st[r] += lz[p];
            lz[r] += lz[p];
            lz[p] = 0;
        }
    }

    void update(int p, int b, int e, int x, int y, int d)
    {
        if (x <= b && e <= y)
        {
            lz[p] += d;
            st[p] += d;
        }
        else
        {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            push(p, l, r);

            if (x < m)
                update(l, b, m, x, y, d);
            if (m < y)
                update(r, m, e, x, y, d);

            st[p] = min(st[l], st[r]);
        }
    }

    int find_min(int p, int b, int e)
    {
        if (b + 1 == e)
        {
            return b;
        }
        else
        {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            push(p, l, r);

            if (st[l] < 0)
                return find_min(l, b, m);
            else
                return find_min(r, m, e);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    segment_tree_max stm(n);
    segment_tree_min_sum stms(n);

    vector<int> p(n), q(n), r(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
        p[i]--;
        stm.update(1, 0, n, i, p[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        r[p[i]] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> q[i];
        q[i]--;
    }

    vector<bool> taken(n);
    int pnt = n - 1;

    for (int i = 0; i < n; ++i)
    {
        while (taken[pnt])
            pnt--;

        cout << pnt + 1 << " ";

        stms.update(1, 0, n, q[i], n, -1);

        int cur_bomb = stms.find_min(1, 0, n);

        int value = stm.big(1, 0, n, 0, cur_bomb + 1);

        int value_pos = r[value];

        taken[value] = true;

        stms.update(1, 0, n, value_pos, n, +1);

        stm.update(1, 0, n, value_pos, -1);
    }

    cout << endl;

    return 0;
}