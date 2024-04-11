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

#include <tuple>

namespace asl
{
    typedef long long i64;
    
} 

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    i64 n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;
    vec<i64> w(n);
    cin >> w;

    i64 best = 1e18;

    for (int i = 0; i < 2; ++i)
    {
        vec<i64> acc(n + 1);
        for (int i = 1; i <= n; ++i)
            acc[i] = acc[i - 1] + w[i - 1];

        i64 far = 0;
        for (int lp = 0, rp = n - 1; lp <= rp;)
        {
            i64 cur = far + (acc[rp + 1] - acc[lp]) * l + ql * (rp - lp);
            
            best = min(cur, best);
            far += w[lp++] * l;

            if (lp <= rp)
            {
                
                i64 cur = far + (acc[rp + 1] - acc[lp]) * r + qr * (rp - lp);
                
                best = min(cur, best);
                far += w[rp--] * r;
            }
        }

        reverse(w.begin(), w.end());
        swap(l, r);
        swap(ql, qr);
    }

    cout << best << endl;
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