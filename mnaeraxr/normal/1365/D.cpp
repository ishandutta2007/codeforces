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

    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, +1, 0, -1};

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

    enum BFSResult
    {
        SKIP = 0,
        ADD = 1,
        FIN = 2,
    };

    void bfs4(int sx, int sy, std::function<BFSResult(int, int, int, int)> fn)
    {
        std::queue<std::pair<int, int>> q;
        if (fn(sx, sy, std::numeric_limits<int>::min(), std::numeric_limits<int>::min()) == BFSResult::ADD)
        {
            q.push({sx, sy});
        }

        bool fin = false;

        while (!fin && !q.empty())
        {
            int x, y;
            std::tie(x, y) = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k)
            {
                int nx = x + dx[k], ny = y + dy[k];

                auto res = fn(nx, ny, x, y);

                if (res == BFSResult::ADD)
                {
                    q.push({nx, ny});
                }
                else if (res == BFSResult::FIN)
                {
                    fin = true;
                    break;
                }
            }
        }
    }

    void bfs4(int sx, int sy, std::function<bool(int, int)> fn)
    {
        std::function<BFSResult(int, int, int, int)> inner_fn = [&](int x, int y, int fx, int fy) {
            auto res = fn(x, y);
            return res ? BFSResult::ADD : BFSResult::SKIP;
        };

        bfs4(sx, sy, inner_fn);
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

    vector<string> maze(n);
    cin >> maze;

    auto b = VBoard(n, m);

    int good = 0;

    for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y)
        {
            good += maze[x][y] == 'G';

            if (maze[x][y] != 'B')
                continue;

            for (int k = 0; k < 4; ++k)
            {
                int nx = x + dx[k], ny = y + dy[k];

                if (b.inside(nx, ny) && maze[nx][ny] == '.')
                    maze[nx][ny] = '#';
            }
        }

    auto vis = board<bool>(n, m, false);

    bfs4(n - 1, m - 1, [&](int x, int y) {
        if (!b.inside(x, y) || vis[x][y] || maze[x][y] == '#')
            return false;

        vis[x][y] = true;

        if (maze[x][y] == 'G')
            good--;

        if (maze[x][y] == 'B')
            good = -1;

        return true;
    });

    cout << (good == 0 ? "Yes" : "No") << endl;
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