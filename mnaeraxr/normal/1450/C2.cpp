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

    vec<int> order = {0, 1, 2};
    vec<int> res;
    string mp = "OX";
    int value = n * n;

    auto check = [&](vec<int> a, bool change) {
        int s = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                int t = (i + j) % 3;

                if (a[t] == 0 && b[i][j] == 'X')
                {
                    ++s;
                    if (change)
                        b[i][j] = 'O';
                }

                else if (a[t] == 1 && b[i][j] == 'O')
                {
                    ++s;
                    if (change)
                        b[i][j] = 'X';
                }
            }
        return s;
    };

    do
    {
        int cur = check(order, false);
        
        if (cur < value)
        {
            value = cur;
            res = order;
        }

    } while (next_permutation(order.begin(), order.end()));

    auto s = check(res, true);
    
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