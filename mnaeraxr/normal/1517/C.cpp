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

namespace asl
{
    
    template <typename T>
    std::vector<std::vector<T>> board(int n = 0, int m = 0)
    {
        return std::vector<std::vector<T>>(n, std::vector<T>(m));
    }

} 

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

    vec<int> p(n);
    cin >> p;

    auto ans = board<int>(n, n);

    for (int i = n - 1; i >= 0; --i)
    {
        int x = i, y = 0;

        for (int j = 0; j < n; ++j)
            if (p[j] > i)
            {
                
                ans[x][y] = p[j];
                x++;
                y++;
            }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
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