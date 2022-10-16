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

#include <utility>

#include <tuple>

#include <random>

using namespace std;
using namespace asl;

int n;

vec<int> ask(int u)
{
    cout << "? " << u + 1 << endl;
    cout.flush();

    vec<int> a(n);
    cin >> a;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    auto ini = ask(0);

    set<pair<int, int>> edges;

    vec<int> p(2);

    for (int i = 0; i < n; ++i)
    {
        p[ini[i] % 2]++;

        if (ini[i] == 1)
            edges.insert({0, i});
    }

    int s = p[1] < p[0] ? 1 : 0;

    for (int i = 1; i < n; ++i)
    {
        if (ini[i] % 2 != s)
            continue;

        auto cur = ask(i);

        for (int j = 0; j < n; ++j)
        {
            if (cur[j] == 1)
            {
                int u = i, v = j;
                if (u > v)
                    swap(u, v);
                edges.insert({u, v});
            }
        }
    }

    cout << "!" << endl;

    for (auto [u, v] : edges)
        cout << u + 1 << " " << v + 1 << endl;

    cout.flush();

    return 0;
}