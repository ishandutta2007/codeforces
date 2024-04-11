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
    T max(std::vector<T> &vec)
    {
        return *std::max_element(vec.begin(), vec.end());
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
    int n, k;
    cin >> n >> k;

    vec<int> t(2);

    string s;
    cin >> s;

    for (int i = 0; i < k; ++i)
    {
        int sel = -1;

        for (int j = i; j < n; j += k)
        {
            if (s[j] != '?')
            {
                int cur = s[j] - '0';

                if (sel == -1)
                {
                    sel = cur;
                }
                else
                {
                    if (sel != cur)
                    {
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        }

        if (sel != -1)
        {
            t[sel]++;
        }
    }

    if (max(t) * 2 <= k)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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