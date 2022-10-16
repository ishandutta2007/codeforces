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

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n;
    cin >> n;
    vec<string> b(n);
    cin >> b;

    int x0, y0, x1, y1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (b[i][j] == '*')
            {
                x0 = i, y0 = j;
                swap(x0, x1);
                swap(y0, y1);
            }

    int x2, y2, x3, y3;

    if (x0 == x1)
    {
        y2 = y0, y3 = y1;
        if (x0 > 0)
            x2 = x3 = x0 - 1;
        else
            x2 = x3 = x0 + 1;
    }
    else if (y0 == y1)
    {
        x2 = x0, x3 = x1;
        if (y0 > 0)
            y2 = y3 = y0 - 1;
        else
            y2 = y3 = y0 + 1;
    }
    else
    {
        x2 = x0;
        y2 = y1;
        x3 = x1;
        y3 = y0;
    }

    b[x2][y2] = '*';
    b[x3][y3] = '*';

    for (auto l : b)
        cout << l << endl;
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