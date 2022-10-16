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

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

bool valid(int mask)
{
    int last = 0, cnt = 0;

    for (int i = 0; i < 4; ++i)
    {
        int b = mask & 1;
        mask >>= 1;

        if (b != last)
        {
            last = b;
            cnt = 0;
        }

        cnt++;

        if (cnt == 3)
            return false;
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int answer = n;

    for (int ini = 0; ini < 4; ++ini)
    {
        vec<int> dp(4, n);

        dp[ini] = int((s[0] == 'R') == (ini >> 1 & 1)) + int((s[1] == 'R') == (ini & 1));

        for (int i = 2; i < n; ++i)
        {
            vec<int> ndp(4, n);

            for (int m = 0; m < 4; ++m)
            {
                for (int p = 0; p < 4; ++p)
                {
                    if ((p & 1) != (m >> 1 & 1))
                        continue;
                    if (p == m && (p == 0 || p == 3))
                        continue;

                    ndp[m] = min(ndp[m], dp[p] + int((s[i] == 'R') == (m & 1)));
                }
            }

            dp.swap(ndp);
            
        }

        for (int fin = 0; fin < 4; ++fin)
        {
            if (valid(fin * 4 + ini))
            {
                answer = min(answer, dp[fin]);
            }
        }
    }

    cout << answer << endl;
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