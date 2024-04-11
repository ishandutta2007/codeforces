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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vec<int> a;

    int good = 0;
    int bad = 0;
    int points = 0;
    char prev = 'L';

    int tot = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'L')
        {
            bad++;
            tot++;
            prev = 'L';
        }
        else
        {
            points += 1 + int(prev == 'W');
            good++;
            a.push_back(tot);
            tot = 0;
            prev = 'W';
        }
    }

    a.push_back(tot);

    k = min(k, bad);

    if (k == 0)
    {
        cout << points << endl;
    }
    else if (a.size() == 1)
    {
        cout << 2 * k - 1 << endl;
    }
    else
    {
        
        a.pop_back();
        reverse(a.begin(), a.end());
        a.pop_back();
        sort(a.begin(), a.end());

        points += 2 * k;
        
        reverse(a.begin(), a.end());

        while (!a.empty() && a.back() == 0)
            a.pop_back();

        while (!a.empty() && a.back() <= k)
        {
            k -= a.back();
            a.pop_back();
            points++;
        }

        cout << points << endl;
    }
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