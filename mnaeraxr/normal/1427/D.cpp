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
    std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
    {
        bool start = true;

        for (auto x : vec)
        {
            if (start)
            {
                start = false;
            }
            else
            {
                out << " ";
            }

            out << x;
        }
        return out;
    }

    template <typename T>
    std::istream &operator>>(std::istream &is, std::vector<T> &vec)
    {
        for (auto &value : vec)
            is >> value;
        return is;
    }

} 

#include <experimental/optional>

#include <tuple>

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n;
    cin >> n;

    vec<int> deck(n);
    cin >> deck;

    for (auto &x : deck)
        x--;

    vec<vec<int>> answer;

    bool ok = false;

    auto add = [&](int a, int b, int c, int d) {
        
        vec<int> cur = {a, b, c, d};
        vec<int> rel;
        for (auto x : cur)
            if (x)
                rel.push_back(x);
        answer.push_back(rel);

        vec<vec<int>> ndeck;
        int p = 0;

        for (auto x : rel)
        {
            vec<int> tag;
            while (x--)
            {
                tag.push_back(deck[p++]);
            }
            ndeck.push_back(tag);
        }

        p = 0;
        while (!ndeck.empty())
        {
            for (auto x : ndeck.back())
                deck[p++] = x;
            ndeck.pop_back();
        }
    };

    while (!ok)
    {
        ok = true;

        for (int i = 0; i < n; ++i)
        {
            if (deck[i] != i)
            {
                ok = false;

                int s = 1;

                while (s + i < n && deck[s + i] == deck[s + i - 1] + 1)
                    s++;

                int r = 1;

                while (i + s + r - 1 < n && deck[i + s + r - 1] != deck[i] - 1)
                    r++;

                add(i, s, r, n - i - s - r);
                break;
            }
        }

    }

    cout << answer.size() << endl;
    for (auto row : answer)
    {
        cout << row.size() << " " << row << endl;
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