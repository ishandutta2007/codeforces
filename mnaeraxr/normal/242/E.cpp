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

} 

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

        void update(int p, int b, int e, int x, int y, U &upd)
        {
            if (x <= b && e <= y)
            {
                _update(ds[p], upd);
            }
            else
            {
                int m = (b + e) >> 1, l = p + 1, r = p + ((m - b) << 1);

                push(p, l, r);

                if (x < m)
                    update(l, b, m, x, y, upd);

                if (m < y)
                    update(r, m, e, x, y, upd);

                ds[p] = _merge(ds[l], ds[r]);
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
            std::vector<T> values,
            std::function<void(T &, U &)> update,
            std::function<T(T &, T &)> merge = [](T &l, T &r) { return l + r; },
            std::function<optional<U>(T &)> get_lazy = [](T &value) { return optional<U>(); })
        {
            init(values.size(), update, merge, get_lazy);
            build([&](int i) {
                return values[i];
            });
        }

        void build(std::function<T(int)> builder)
        {
            build(0, 0, size, builder);
        }

        void update(int x, U upd)
        {
            update(0, 0, size, x, x + 1, upd);
        }

        void update(int x, int y, U upd)
        {
            update(0, 0, size, x, y, upd);
        }

        T query(int x, int y)
        {
            return query(0, 0, size, x, y);
        }
    };
 
    class Empty
    {
    public:
        Empty() {}
    };

}

#include <tuple>

namespace asl
{
    typedef long long i64;
    
} 

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

const int BITS = 20;

struct state
{
    int size, sum;
    bool lazy;
};

state xmerge(state &a, state &b)
{
    return {a.size + b.size, a.sum + b.sum, false};
}

void update(state &a, Empty &upd)
{
    a.sum = a.size - a.sum;
    a.lazy ^= 1;
}

optional<Empty> get_lazy(state &a)
{
    if (a.lazy)
    {
        a.lazy = false;
        return optional<Empty>(Empty{});
    }
    else
    {
        return optional<Empty>();
    }
}

void solve()
{
    int n;
    cin >> n;
    vec<SegmentTree<state, Empty>> st(BITS, SegmentTree<state, Empty>(vec<state>(n, {1, 0, 0}), update, xmerge, get_lazy));

    vec<int> a(n);
    cin >> a;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < BITS; ++j)
            if (a[i] >> j & 1)
                st[j].update(i, {});

    int q;
    cin >> q;

    while (q--)
    {
        int mode;
        cin >> mode;

        if (mode == 1)
        {
            int l, r;
            cin >> l >> r;

            i64 sum = 0;
            for (int i = 0; i < BITS; ++i)
                sum += (i64)st[i].query(l - 1, r).sum << i;

            cout << sum << endl;
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;

            for (int i = 0; i < BITS; ++i)
                if (x >> i & 1)
                    st[i].update(l - 1, r, {});
        }
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