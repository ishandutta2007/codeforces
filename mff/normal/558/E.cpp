#include <algorithm>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <iomanip>
#include <math.h>
#include <cmath>
#include <array>

#include <experimental/optional>
#define optional std::experimental::optional

namespace asl
{
    
    template <typename T, typename U = T>
    optional<U> noop_get_lazy(T &p)
    {
        return optional<U>();
    }

    template <typename T>
    T add_merge(T &l, T &r) { return l + r; }

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

        SegmentTree(int size,
                    std::function<void(T &, U &)> update,
                    std::function<T(T &, T &)> merge = add_merge<T>,
                    std::function<optional<U>(T &)> get_lazy = noop_get_lazy<T, U>)
        {
            init(size, update, merge, get_lazy);
        }

        void build(std::function<T(int)> builder)
        {
            build(0, 0, size, builder);
        }

        void update(int x, int y, U upd)
        {
            update(0, 0, size, x, y, upd);
        }

        T query(int x)
        {
            return query(0, 0, size, x, x + 1);
        }

        T query(int x, int y)
        {
            return query(0, 0, size, x, y);
        }
    };
} 

#define endl '\n'

using namespace asl;
using namespace std;

const int ALPHA = 26;

struct state
{
    vector<int> freq;
    short sort_to; 

    state()
    {
        freq = vector<int>(ALPHA);
        sort_to = -1;
    }

    void check()
    {
        assert(freq.size() == ALPHA);
    }

    int total()
    {
        check();
        int res = 0;
        for (int i = 0; i < ALPHA; ++i)
            res += freq[i];
        return res;
    }

    state get(int size)
    {
        check();
        state res;
        res.sort_to = sort_to;

        if (sort_to == 1)
        {
            for (int i = 0; i < ALPHA && size; ++i)
            {
                int cur = min(size, freq[i]);
                res.freq[i] += cur;
                freq[i] -= cur;
                size -= cur;
            }
        }
        else
        {
            for (int i = ALPHA - 1; i >= 0 && size; --i)
            {
                int cur = min(size, freq[i]);
                res.freq[i] += cur;
                freq[i] -= cur;
                size -= cur;
            }
        }

        return res;
    }

    state operator+(state &s)
    {
        check();
        state res;

        for (int i = 0; i < ALPHA; ++i)
        {
            res.freq[i] = freq[i] + s.freq[i];
        }

        return res;
    }

    char as_char()
    {
        check();
        assert(total() == 1);
        for (int i = 0; i < ALPHA; ++i)
            if (freq[i])
                return 'a' + i;
        assert(false);
        return '*';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    typedef state upd;

    auto update = [](state &s, upd &u) {
        auto tot = s.total();
        auto cur = u.get(tot);
        s = cur;
    };

    auto merge = [](state &a, state &b) {
        return a + b;
    };

    auto get_lazy = [](state &a) {
        if (a.sort_to >= 0)
        {
            state b = a;
            a.sort_to = -1;
            return optional<state>(b);
        }
        else
        {
            return optional<state>();
        }
    };

    auto builder = [&](int i) {
        state res;
        res.freq[s[i] - 'a'] = 1;
        return res;
    };

    SegmentTree<state> st(
        n, update, merge, get_lazy);

    st.build(builder);

    while (q--)
    {
        int x, y, m;
        cin >> x >> y >> m;

        auto cur = st.query(x - 1, y);

        cur.sort_to = m;
        st.update(x - 1, y, cur);
    }

    for (int i = 0; i < n; ++i)
        cout << st.query(i).as_char();
    cout << endl;

    return 0;
}