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

namespace asl
{
    typedef long long i64;
    
} 

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

i64 get(i64 a, int t)
{
    i64 x = a / t;
    i64 r = a % t;
    return x * x * (t - r) + (x + 1) * (x + 1) * r;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    typedef pair<i64, int> state;
    priority_queue<state> pq;

    i64 res = 0;

    vec<i64> a(n);
    vec<int> t(n, 1);

    auto delta = [&](int p) {
        i64 cur = get(a[p], t[p] + 1) - get(a[p], t[p]);
        
        return -cur;
    };

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        res += a[i] * a[i];
        pq.push({delta(i), i});
    }

    for (int i = n, p; i < k; ++i)
    {
        i64 d;
        tie(d, p) = pq.top();
        pq.pop();

        res -= d;

        t[p]++;
        pq.push({delta(p), p});
    }

    cout << res << endl;
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