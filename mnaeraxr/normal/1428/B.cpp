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
    string s;
    cin >> s;
    vec<bool> ok(s.length());

    bool a = false, b = false;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '<')
            a = true;
        else if (s[i] == '>')
            b = true;
        else
            ok[i] = true, ok[(i + 1) % n] = true;
    }

    if (!a || !b)
    {
        cout << n << endl;
    }
    else
    {
        int res = 0;
        for (auto x : ok)
            res += x;
        cout << res << endl;
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