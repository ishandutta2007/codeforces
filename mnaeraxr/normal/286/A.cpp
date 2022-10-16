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

void solve()
{
    int n;
    cin >> n;

    if (n % 4 >= 2)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> p(n + 1);

    if (n & 1)
        p[(n + 1) / 2] = (n + 1) / 2;

    int tot = n & 1;

    for (int i = 1; tot < n; i += 2)
    {
        vec<int> cur = {i, i + 1, n - i + 1, n - (i + 1) + 1, i};
        for (int j = 0; j < 4; ++j)
            p[cur[j]] = cur[j + 1];

        tot += 4;
    }

    for (int i = 1; i <= n; ++i)
        cout << p[i] << " ";
    cout << endl;

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