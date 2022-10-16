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

} 

#include <experimental/optional>

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n;
    i64 w;
    cin >> n >> w;

    vec<i64> a(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    vec<int> pos;
    i64 sum = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > w)
        {
        }
        else if (a[i] * 2 >= w)
        {
            cout << 1 << endl;
            cout << i << endl;
            return;
        }
        else
        {
            sum += a[i];
            pos.push_back(i);

            if (sum * 2 >= w)
                break;
        }
    }

    if (sum * 2 >= w)
    {
        cout << pos.size() << endl;
        cout << pos << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}