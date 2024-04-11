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
    
} 
#include <stdint.h>

#include <experimental/optional>

#include <utility>

#include <tuple>

namespace asl
{
    
    template <typename int_type>
    int_type gcd(int_type a, int_type b)
    {
        while (b)
        {
            auto t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
} 

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    i64 a, b, x, y;
    cin >> a >> b >> x >> y;

    i64 g = gcd(x, y);
    x /= g;
    y /= g;

    i64 f = min(a / x, b / y);

    cout << f * x << " " << f * y << endl;
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