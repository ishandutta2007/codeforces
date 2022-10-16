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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vec<string> b(n);
    cin >> b;

    int x = 0, y = 0, r = b[0][0] == '*';

    while (true)
    {
        b[x][y] = '.';
        int nx = n, ny = m;
        for (int i = x; i < n; ++i)
            for (int j = y; j < m; ++j)
            {
                if (b[i][j] == '*' && (i - x) + (j - y) < (nx - x) + (ny - y))
                    nx = i, ny = j;
            }

        if (nx == n)
            break;

        r++;
        x = nx, y = ny;
    }

    cout << r << endl;

    return 0;
}