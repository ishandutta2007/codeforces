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

namespace asl
{
    typedef long long i64;
    
#include <stdint.h>

    template <typename T>
    using vec = std::vector<T>;

    class Mo
    {
    public:
        class Query
        {
        public:
            int b, e, block, index;
        };

        int low, high;
        std::vector<Query> query;

        std::function<void(int)> add_left;
        std::function<void(int)> add_right;
        std::function<void(int)> remove_left;
        std::function<void(int)> remove_right;
        std::function<void(int)> solve_query;

        Mo() : low(1e9), high(-1e9),
               add_left([](int) {}),
               add_right([](int) {}),
               remove_left([](int) {}),
               remove_right([](int) {}),
               solve_query([](int) {}) {}

        Mo(std::vector<std::pair<int, int>> queries) : Mo()
        {
            query.reserve(queries.size());
            for (auto [b, e] : queries)
                insert_query(b, e);
        }

        void set_add(std::function<void(int)> add)
        {
            add_left = add;
            add_right = add;
        }

        void set_remove(std::function<void(int)> remove)
        {
            remove_left = remove;
            remove_right = remove;
        }

        void insert_query(int b, int e)
        {
            int index = query.size();
            low = std::min(low, b);
            high = std::max(high, e);
            query.push_back({b, e, -1, index});
        }

        void run()
        {
            
            int n = high - low;
            int q = query.size();
            int block_size = std::max((int)(n / sqrt(q)), 1);

            for (auto &u : query)
                u.block = u.b / block_size;

            std::sort(query.begin(), query.end(), [](Query &a, Query &b) {
                if (a.block != b.block)
                    return a.block < b.block;
                if (a.block & 1)
                    return a.e > b.e;
                else
                    return a.e < b.e;
            });

            int b = low, e = low;

            for (auto u : query)
            {
                while (b > u.b)
                    add_left(--b);
                while (e < u.e)
                    add_right(e++);
                while (b < u.b)
                    remove_left(b++);
                while (e > u.e)
                    remove_right(--e);
                solve_query(u.index);
            }
        }
    };
} 

#include <experimental/optional>

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace asl;
using namespace std;

void solve()
{
    int n, q, k;
    cin >> n >> q >> k;

    vec<int> arr(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        arr[i] ^= arr[i - 1];
    }

    vec<pair<int, int>> que(q);

    for (int i = 0; i < q; ++i)
    {
        int u, v;
        cin >> u >> v;
        que[i] = {u - 1, v + 1};
    }

    i64 answer = 0;
    vec<int> freq(2e6);
    vec<i64> res(q);

    Mo mo(que);

    mo.set_add([&](int p) {
        int u = arr[p];
        answer += freq[u ^ k];
        freq[u]++;
    });

    mo.set_remove([&](int p) {
        int u = arr[p];
        freq[u]--;
        answer -= freq[u ^ k];
    });

    mo.solve_query = [&](int index) {
        res[index] = answer;
    };

    mo.run();

    for (auto u : res)
        cout << u << endl;
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