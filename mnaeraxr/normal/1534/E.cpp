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

using namespace std;
using namespace asl;

void solve(int n, int k)
{
    if (n % 2 == 1 && k % 2 == 0)
    {
        cout << -1 << endl;
        return;
    }

    int tot = n;
    int pos = 0;

    for (pos = 0; n * n * 5; ++pos)
    {
        if (tot % k == 0 && (pos + n - 1) / n * 2 + 1 <= tot / k)
            break;
        tot += 2;
    }

    if (tot % k != 0 || (pos + n - 1) / n * 2 + 1 > tot / k)
    {
        cout << -1 << endl;
        return;
    }

    if (tot % k)
    {
        
        assert(k % 2 == 0 && n % 2 == 1);
        cout << -1 << endl;
        return;
    }

    if (k % 2 != 0 || n % 2 != 1)
    {
    }
    else
    {
        
        exit(0);
    }

    vec<int> f(n, 1), a, lz(n, -1);

    for (int i = 0; i < pos; ++i)
        f[i % n] += 2;

    while (a.size() < tot)
    {
        int v = a.size();

        for (int i = 0; i < k; ++i)
        {
            int x = -1;
            for (int j = 0; j < n; ++j)
            {
                if (lz[j] == v)
                    continue;

                if (x == -1 || f[j] > f[x])
                    x = j;
            }

            assert(x != -1);
            lz[x] = v;
            f[x]--;
            a.push_back(x);
        }
    }

    i64 res = 0;
    for (int i = 0; i < a.size(); i += k)
    {
        cout << "?";
        for (int j = 0; j < k; ++j)
            cout << " " << a[i + j] + 1;
        cout << endl;
        cout.flush();

        i64 val;
        cin >> val;
        res ^= val;
    }

    cout << "! " << res << endl;
}

int main()
{
    int n, k;
    cin >> n >> k;
    solve(n, k);
    
    return 0;
}