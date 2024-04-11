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
    int n, x;
    cin >> n >> x;

    map<int, i64> freq;

    set<int> s;

    for (int i = 0; i < n; ++i)
    {
        int u;
        cin >> u;
        freq[u]++;
        s.insert(u);
    }

    i64 answer = 0;

    for (auto u : s)
    {
        answer += freq[u] * freq[u ^ x];
    }

    if (x == 0)
        answer -= n;

    cout << answer / 2 << endl;
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