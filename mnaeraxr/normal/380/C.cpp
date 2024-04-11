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

#include <experimental/optional>
#define optional std::experimental::optional

namespace asl
{
    
    template <typename T, typename U = T>
    class SegmentTree
    {
        int size;
        std::function<void(T &, U &)> _update;
        std::function<T(T &, T &)> _merge;
        std::function<optional<U>(T &)> _get_lazy;

        void push(int p, int l, int r)
        {
            auto lazy = _get_lazy(ds[p]);

            if (lazy)
            {
                _update(ds[l], *lazy);
                _update(ds[r], *lazy);
            }
        }

        T query(int p, int b, int e, int x, int y)
        {
            if (x <= b && e <= y)
            {
                return ds[p];
            }
            else
            {
                int m = (b + e) >> 1, l = p + 1, r = p + ((m - b) << 1);

                push(p, l, r);

                if (x < m)
                {
                    auto le = query(l, b, m, x, y);

                    if (m < y)
                    {
                        auto ri = query(r, m, e, x, y);
                        return _merge(le, ri);
                    }
                    else
                    {
                        return le;
                    }
                }
                else
                {
                    return query(r, m, e, x, y);
                }
            }
        }

        void build(int p, int b, int e, std::function<T(int)> &builder)
        {
            if (b + 1 == e)
            {
                ds[p] = builder(b);
            }
            else
            {
                int m = (b + e) >> 1, l = p + 1, r = p + ((m - b) << 1);

                build(l, b, m, builder);
                build(r, m, e, builder);

                ds[p] = _merge(ds[l], ds[r]);
            }
        }

        void init(int size,
                  std::function<void(T &, U &)> update,
                  std::function<T(T &, T &)> merge,
                  std::function<optional<U>(T &)> get_lazy)
        {
            this->size = size;
            this->_update = update;
            this->_merge = merge;
            this->_get_lazy = get_lazy;
            this->ds = std::vector<T>(2 * size - 1);
        }

    public:
        std::vector<T> ds;

        SegmentTree(
            int size,
            std::function<void(T &, U &)> update,
            std::function<T(T &, T &)> merge = [](T &l, T &r) { return l + r; },
            std::function<optional<U>(T &)> get_lazy = [](T &value) { return optional<U>(); })
        {
            init(size, update, merge, get_lazy);
        }

        void build(std::function<T(int)> builder)
        {
            build(0, 0, size, builder);
        }

        T query(int x, int y)
        {
            return query(0, 0, size, x, y);
        }
    };
 
    class Empty
    {
    public:
        
    };

}

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

struct D
{
    int a, b, c;
};

void update(D &a, Empty &e)
{
}

D mymerge(D &l, D &r)
{

    int t = l.b + r.b;
    int m = min(l.c, r.a);

    return {l.a + r.a - m, t + m, r.c + l.c - m};
}

void solve()
{
    string s;
    cin >> s;

    SegmentTree<D, Empty> tree(s.size(), update, mymerge);

    tree.build([&](int i) -> D {
        if (s[i] == ')')
        {
            return {1, 0, 0};
        }
        else
        {
            return {0, 0, 1};
        }
    });

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << tree.query(l - 1, r).b * 2 << endl;
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