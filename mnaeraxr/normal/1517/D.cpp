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
    std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
    {
        bool start = true;

        for (auto x : vec)
        {
            if (start)
            {
                start = false;
            }
            else
            {
                out << " ";
            }

            out << x;
        }
        return out;
    }

} 

#include <experimental/optional>

namespace asl
{
    int DX[4] = {-1, 0, +1, 0};
    int DY[4] = {0, +1, 0, -1};

    class VBoard
    {
    public:
        int n, m;

        VBoard(int n = 0, int m = 0) : n(n), m(m) {}

        bool inside(int x, int y)
        {
            return 0 <= x && x < n && 0 <= y && y < m;
        }

    };

    template <typename T>
    std::vector<std::vector<T>> board(int n, int m, T def)
    {
        return std::vector<std::vector<T>>(n, std::vector<T>(m, def));
    }

    template <typename T>
    std::vector<std::vector<T>> board(int n = 0, int m = 0)
    {
        return std::vector<std::vector<T>>(n, std::vector<T>(m));
    }

    template <typename T>
    std::ostream &operator<<(std::ostream &out, const std::vector<std::vector<T>> &board)
    {
        bool first = true;

        for (auto &row : board)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                out << std::endl;
            }
            out << row;
        }
        return out;
    }
} 

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

const int maxn = 501;

int a[maxn][maxn];
int b[maxn][maxn];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    if (k % 2 == 1)
    {
        auto res = board<int>(n, m, -1);
        cout << res << endl;
        return;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 1; j < m; ++j)
            cin >> a[i][j];

    for (int i = 1; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> b[i][j];

    auto dp = board<int>(n, m);

    VBoard vir(n, m);
    for (int s = 0; s < k; s += 2)
    {
        auto ndp = dp;

        for (int x = 0; x < n; ++x)
            for (int y = 0; y < m; ++y)
            {
                int best = 1000000000;
                for (int k = 0; k < 4; ++k)
                {
                    int nx = x + DX[k], ny = y + DY[k];

                    if (vir.inside(nx, ny))
                    {
                        int ev = 1000000000;
                        if (k & 1)
                            ev = min(ev, a[max(x, nx)][max(y, ny)]);
                        else
                            ev = min(ev, b[max(x, nx)][max(y, ny)]);
                        best = min(best, dp[nx][ny] + 2 * ev);
                    }
                }
                ndp[x][y] = best;
            }
        dp.swap(ndp);
        
    }
    cout << dp << endl;

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