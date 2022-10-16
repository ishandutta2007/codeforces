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
    string xx;
    cin >> xx;

    string w = "1689";

    vec<int> c(10);

    for (auto x : xx)
        c[x - '0']++;

    c[1]--;
    c[6]--;
    c[8]--;
    c[9]--;

    string s = "";
    for (int i = 1; i < 10; ++i)
        for (int j = 0; j < c[i]; ++j)
            s += (char)('0' + i);

    int rem = 0;
    for (auto x : s)
        rem = (10 * rem + x - '0') % 7;

    vec<int> order = {1, 6, 8, 9};

    do
    {
        int tmp = rem;

        for (auto u : order)
            tmp = (10 * tmp + u) % 7;

        if (tmp == 0)
            break;

    } while (next_permutation(order.begin(), order.end()));

    for (auto u : order)
        s += (char)('0' + u);

    for (int i = 0; i < c[0]; ++i)
        s += '0';

    cout << s << endl;
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