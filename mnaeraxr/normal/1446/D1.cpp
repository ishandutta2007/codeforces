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
    T max(std::vector<T> &vec)
    {
        return *std::max_element(vec.begin(), vec.end());
    }

    template <typename T>
    std::istream &operator>>(std::istream &is, std::vector<T> &vec)
    {
        for (auto &value : vec)
            is >> value;
        return is;
    }

} 

#include <experimental/optional>

namespace asl
{
    
    template <typename T>
    std::vector<std::vector<T>> board(int n, int m, T def)
    {
        return std::vector<std::vector<T>>(n, std::vector<T>(m, def));
    }

} 

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n;
    cin >> n;
    vec<int> a(n);
    cin >> a;

    map<int, int> freq;

    for (auto u : a)
        freq[u]++;

    int big = 0, f = 0, w = -1;

    for (auto p : freq)
    {
        if (p.second > big)
        {
            big = p.second;
            f = 0;
            w = p.first;
        }

        if (p.second == big)
            ++f;
    }

    if (f > 1)
    {
        cout << n << endl;
        return;
    }

    int M = max(a);

    auto last = board<int>(2 * n + 1, M + 1, 1e9);

    int solution = 0;
    vec<int> arr(M + 1);

    for (int j = 0; j <= M; ++j)
        last[0 + n][j] = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == w)
        {
            for (int j = 0; j <= M; ++j)
                arr[j]++;
        }
        else
        {
            arr[a[i]]--;
        }

        for (int j = 1; j <= M; ++j)
        {
            if (j == w)
                continue;

            solution = max(solution, i + 1 - last[arr[j] + n][j]);
            last[arr[j] + n][j] = min(last[arr[j] + n][j], i + 1);
        }

    }

    cout << solution << endl;
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