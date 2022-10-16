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
    i64 a;
    cin >> a;

    vec<i64> q;

    for (int i = 1; i * i <= a; ++i)
    {
        if (a % i == 0)
        {
            q.push_back(i);
            q.push_back(a / i);
        }
    }

    if (q.back() * q.back() == a)
        q.pop_back();

    sort(q.begin(), q.end());

    i64 low = -1, hi = -1;

    for (int pa = 0; pa < q.size(); ++pa)
    {
        for (int pb = 0; pb < q.size(); ++pb)
        {
            if ((a / q[pa]) % q[pb] == 0)
            {
                i64 A = q[pa];
                i64 B = q[pb];
                i64 C = a / A / B;

                i64 cur = (A + 1) * (B + 2) * (C + 2);

                if (low == -1)
                {
                    low = hi = cur;
                }
                else
                {
                    low = min(low, cur);
                    hi = max(hi, cur);
                }
            }
        }
    }

    cout << low - a << " " << hi - a << endl;
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