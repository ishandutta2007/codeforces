#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
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

#include <experimental/optional>
#define optional std::experimental::optional

namespace asl
{
    
    template <typename T, typename U = T>
    optional<U> noop_get_lazy(T &p)
    {
        return optional<U>();
    }

    template <typename T>
    T add_merge(T &l, T &r) { return l + r; }

} 

namespace asl
{
    
    template <typename T>
    std::istream &operator>>(std::istream &is, std::vector<T> &vec)
    {
        for (auto &value : vec)
            is >> value;
        return is;
    }

    template <typename T>
    std::vector<std::vector<T>> board(int n, int m, T def)
    {
        return std::vector<std::vector<T>>(n, std::vector<T>(m, def));
    }

} 

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n, m;
    cin >> n >> m;

    auto b = board<int>(n, m, 0);

    cin >> b;

    vector<int> A(n), B(m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            A[i] += b[i][j] == 0;
            B[j] += b[i][j] == 0;
        }

    int ra = 0, rb = 0;

    for (int i = 0; i < n; ++i)
        ra += A[i] == m;

    for (int i = 0; i < m; ++i)
        rb += B[i] == n;

    int r = min(ra, rb);

    cout << (r & 1 ? "Ashish" : "Vivek") << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        solve();
    }

    return 0;
}