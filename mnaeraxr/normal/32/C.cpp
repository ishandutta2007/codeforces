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

#include <random>

#include <utility>

#define endl '\n'

using namespace std;

long long calc(long long a, long long s)
{
    auto r = a % s;

    if (r == 0)
    {
        return a;
    }
    else
    {
        return r * ((a + s - 1) / s);
    }
}

void solve()
{
    long long a, b, s;
    cin >> a >> b >> s;

    cout << calc(a, s) * calc(b, s) << endl;
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