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

} // namespace asl

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    long long n;
    cin >> n;

    vec<long long> a(n);
    cin >> a;

    long long h = a[n - 1];
    vec<long long> pos = {n - 1};

    for (int i = n - 2; i >= 0; --i)
    {

        while (pos.size() > 1)
        {
            auto t = pos.back() - i;
            auto hlow = h - (t - 1);

            if (a[i] == hlow)
            {
                h = hlow;
                pos.push_back(i);
                break;
            }

            auto rem = min(hlow - 1 - a[i], t);

            a[i] += rem;

            if (rem < t)
            {
                pos.back() -= rem;
                h -= rem;
                break;
            }
            else
            {
                auto delta = pos[pos.size() - 2] - pos.back();
                pos.pop_back();

                if (a[i] == hlow - 1)
                {
                    pos.push_back(i);
                    h = hlow - 1;
                    break;
                }
                else
                {
                    h += delta - 1;
                }
            }
        }

        if (pos.size() == 1)
        {
            auto t = n - 1 - i;
            auto k = (h - (t - 1) - a[i]) / (t + 1);
            a[i] += t * k;
            h -= k;

            auto hlow = h - (t - 1);

            if (a[i] == hlow)
            {
                h = hlow;
                pos.push_back(i);
            }
            else
            {
                auto rem = hlow - 1 - a[i];

                if (rem == 0)
                {
                }
                else
                {
                    h -= rem;
                    auto b = pos[0] - rem;
                    pos.push_back(b);
                }
            }
        }
    }

    vec<long long> res(n);

    reverse(pos.begin(), pos.end());
    h -= pos[0];

    for (int i = 0, j = 0; i < n; ++i)
    {
        res[i] = h;

        if (j < pos.size() && pos[j] == i)
        {
        }
        else
            ++h;
    }

    for (auto x : res)
        cout << x << " ";
    cout << endl;
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