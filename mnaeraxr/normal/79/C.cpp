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

#include <tuple>

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vec<string> a(n);
    cin >> a;

    int best = 0, pos = 0;

    for (int i = 0, j = 0; i < s.length(); ++i)
    {
        for (auto u : a)
        {
            if (u.size() <= i + 1)
            {
                bool eq = true;
                for (int k = 0; k < u.size() && eq; ++k)
                    if (u[k] != s[i - u.size() + 1 + k])
                        eq = false;

                if (eq)
                    j = max(j, int(i - u.size() + 2));
            }
        }

        int cur = i - j + 1;

        if (cur > best)
        {
            best = cur;
            pos = j;
        }
    }

    cout << best << " " << pos << endl;
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