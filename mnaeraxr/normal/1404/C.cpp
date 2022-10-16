#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>

#include <map>
#include <math.h>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <stdint.h>

namespace asl
{
    template <typename T>
    using vec = std::vector<T>;

    template <typename T>
    std::istream &operator>>(std::istream &is, std::vector<T> &vec)
    {
        for (auto &value : vec)
            is >> value;
        return is;
    }

    template <typename T>
    struct fenwick
    {
        int n;
        std::vector<T> f;
        fenwick(int n) : n(n), f(n + 1) {}

        T query(int p)
        {
            T ret = 0;
            for (++p; p > 0; p -= p & -p)
                ret += f[p];
            return ret;
        }

        void update(int p, T x)
        {
            for (++p; p <= n; p += p & -p)
                f[p] += x;
        }
    };

    template <typename T>
    using BIT = fenwick<T>;
} 

#include <experimental/optional>

#include <tuple>

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

struct segment_tree
{
    vec<int> ds, lz;

    segment_tree(int n)
    {
        ds = vec<int>(4 * n, 1e9);
        lz = vec<int>(4 * n);
    }

    void push(int p, int l, int r)
    {
        if (lz[p])
        {
            lz[l] += lz[p];
            ds[l] += lz[p];
            lz[r] += lz[p];
            ds[r] += lz[p];
            lz[p] = 0;
        }
    }

    void put(int p, int b, int e, int x, int v)
    {
        if (b + 1 == e)
        {
            ds[p] = v;
        }
        else
        {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            push(p, l, r);

            if (x < m)
                put(l, b, m, x, v);
            else
                put(r, m, e, x, v);

            ds[p] = min(ds[l], ds[r]);
        }
    }

    void update(int p, int b, int e, int x, int y)
    {
        if (x <= b && e <= y)
        {
            ds[p] -= 1;
            lz[p] -= 1;
        }
        else
        {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            push(p, l, r);

            if (x < m)
                update(l, b, m, x, y);
            if (m < y)
                update(r, m, e, x, y);

            ds[p] = min(ds[l], ds[r]);
        }
    }

    int top()
    {
        return ds[1];
    }

    int query(int p, int b, int e)
    {
        if (b + 1 == e)
        {
            return b;
        }
        else
        {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            push(p, l, r);

            if (ds[p] == ds[r])
                return query(r, m, e);
            else
                return query(l, b, m);
        }
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    vec<int> a(n);
    cin >> a;

    for (int i = 0; i < n; ++i)
        a[i] = i + 1 - a[i];

    vec<tuple<int, int, int>> que(q);

    segment_tree st(n);
    BIT<int> bit(n);

    for (int i = 0; i < q; ++i)
    {
        int x, y;
        cin >> x >> y;
        que[i] = {x, n - y - 1, i};
    }

    sort(que.begin(), que.end());
    reverse(que.begin(), que.end());

    vec<int> res(q);

    for (int i = n - 1, j = 0; i >= 0; --i)
    {
        if (a[i] > 0)
        {
            
            st.put(1, 0, n, i, a[i]);
        }
        else if (a[i] == 0)
        {
            
            bit.update(i, +1);
            
            st.update(1, 0, n, 0, n);

            while (st.top() == 0)
            {
                int u = st.query(1, 0, n);
                
                bit.update(u, +1);
                st.put(1, 0, n, u, 1e9);
                st.update(1, 0, n, u, n);
            }
        }

        while (j < q && get<0>(que[j]) == i)
        {
            int xx, yy, ixx;
            tie(xx, yy, ixx) = que[j];
            
            res[ixx] = bit.query(yy);
            ++j;
        }
    }

    for (auto x : res)
    {
        cout << x << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}