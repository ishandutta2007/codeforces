#include <algorithm>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <optional>

namespace asl
{
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, +1, 0, -1};

    class TBoard
    {
    public:
        int n, m;

        TBoard(int n = 0, int m = 0) : n(n), m(m) {}

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

    std::vector<std::vector<char>> read_board_string(int n, int m)
    {
        std::vector<std::vector<char>> res(n);

        for (int i = 0; i < n; ++i)
        {
            std::string s;
            std::cin >> s;
            res[i] = std::vector<char>(s.begin(), s.end());
        }

        return res;
    }

} 

#define endl '\n'

using namespace std;
using namespace asl;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    auto b = read_board_string(n, m);

    TBoard t(n, m);

    queue<pair<int, int>> que;

    auto dist = board(n, m, 0x3f3f3f3f);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            bool ok = false;
            for (int k = 0; k < 4 && !ok; ++k)
            {
                int nx = i + dx[k], ny = j + dy[k];

                if (t.inside(nx, ny) && b[nx][ny] == b[i][j])
                {
                    ok = true;
                }
            }

            if (ok)
            {
                que.push({i, j});
                dist[i][j] = 0;
            }
        }

    bool nobody = que.empty();

    while (!que.empty())
    {
        int x, y;
        tie(x, y) = que.front();
        que.pop();

        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k], ny = y + dy[k];

            if (t.inside(nx, ny) && dist[nx][ny] > dist[x][y] + 1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }

    while (q--)
    {
        int x, y;
        long long t;
        cin >> x >> y >> t;
        x--;
        y--;

        if (nobody)
        {
            cout << b[x][y] << endl;
        }
        else
        {
            if (t <= dist[x][y])
            {
                cout << b[x][y] << endl;
            }
            else
            {
                t -= dist[x][y];
                t &= 1;
                cout << (int(b[x][y] - '0') ^ t) << endl;
            }
        }
    }

    return 0;
}