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
    int n, m;
    cin >> n >> m;

    vec<string> a(n);
    cin >> a;

    string s = "RW";

    for (int k = 0; k < 2; ++k)
    {
        auto x = a;

        bool ok = true;

        for (int i = 0; i < n && ok; ++i)
            for (int j = 0; j < m && ok; ++j)
                if (x[i][j] == '.')
                {
                    x[i][j] = s[(i + j) % 2 ^ k];
                }
                else
                {
                    char c = s[(i + j) % 2 ^ k];

                    if (x[i][j] != c)
                    {
                        ok = false;
                    }
                }

        if (ok)
        {
            cout << "YES" << endl;

            for (auto r : x)
                cout << r << endl;
            return;
        }
    }

    cout << "NO" << endl;
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