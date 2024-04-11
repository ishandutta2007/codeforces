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


 // namespace asl


 // namespace asl


 // namespace asl


 // namespace asl


namespace asl
{
    template <typename T = int>
    class Vec : public std::vector<T>
    {
    public:
        Vec<T>(int size = 0) : std::vector<T>(size) {}
        Vec<T>(int size, T def) : std::vector<T>(size, def) {}
        Vec<T>(std::vector<T> v) : std::vector<T>(v) {}

        template <typename I>
        I fold(I initial, std::function<I(I, T &)> fn)
        {
            for (auto u : *this)
            {
                initial = fn(initial, u);
            }

            return initial;
        }
    };
 // namespace asl


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
    class Board : public Vec<Vec<T>>, public TBoard
    {
    public:
        Board(int n = 0, int m = 0) : Vec<Vec<T>>(n, Vec<T>(m)), TBoard(n, m) {}

        std::pair<int, int> shape()
        {
            int n = this->size();
            int m = (*this)[0].size();
            return {n, m};
        }

        Board<T> transpose()
        {
            int n, m;
            std::tie(n, m) = shape();

            Board<T> res(m, n);

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    res[j][i] = (*this)[i][j];

            return res;
        }
    };

    Board<char> read_board_string(int n, int m)
    {
        Board<char> res;

        for (int i = 0; i < n; ++i)
        {
            std::string s;
            std::cin >> s;
            res.push_back(std::vector<char>(s.begin(), s.end()));
        }

        return res;
    }

    
 // namespace asl


    enum BFSResult
    {
        SKIP = 0,
        ADD = 1,
        FIN = 2,
    };

    /// Run BFS over a grid using 4-neighbor vicinity
    void bfs4(int sx, int sy, std::function<BFSResult(int, int)> fn)
    {
        std::queue<std::pair<int, int>> q;
        if (fn(sx, sy) == BFSResult::ADD)
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

                auto res = fn(nx, ny);

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
        std::function<BFSResult(int, int)> inner_fn = [&](int x, int y) {
            auto res = fn(x, y);
            return res ? BFSResult::ADD : BFSResult::SKIP;
        };

        bfs4(sx, sy, inner_fn);
    }
} // namespace asl


#define endl '\n'

using namespace std;
using namespace asl;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    Board b = read_board_string(n, m);

    bool ok = true, hor = false, ver = false;

    for (int i = 0; i < 2; ++i)
    {
        for (auto &row : b)
        {
            auto state = row.fold<int>(0, [&](int state, char value) {
                if (value == '#')
                {
                    if (state % 2 == 0)
                        ++state;
                }
                else
                {
                    if (state == 1)
                        ++state;
                }
                return state;
            });

            if (state == 0)
                hor = true;

            ok &= state <= 2;
        }

        b = b.transpose();
        swap(hor, ver);
    }

    if (!ok || (ver != hor))
    {
        cout << -1 << endl;
    }
    else
    {
        int answer = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (b[i][j] == '#')
                {
                    bfs4(i, j, [&](int x, int y) {
                        if (b.inside(x, y) && b[x][y] == '#')
                        {
                            b[x][y] = '.';
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    });
                    answer++;
                }
            }
        }

        cout << answer << endl;
    }

    return 0;
}