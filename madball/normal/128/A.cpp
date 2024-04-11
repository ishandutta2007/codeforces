#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

bool field[8][8][9];
bool been[8][8][9];
const int OFFSET[9][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {0, 0} };

void solve()
{

    For(i, 8) For(j, 8)
    {
        char c;
        cin >> c;
        if (c == 'S') For(k, 8)
        {
            if (i + k < 8)
                field[i + k][j][k] = true;
            if (i + k + 1 < 8)
                field[i + k + 1][j][k] = true;
        }
    }
    queue<tuple<int, int, int>> q;
    q.emplace(7, 0, -1);
    while (!q.empty())
    {
        int x, y, t;
        tie(x, y, t) = q.front();
        q.pop();
        For(dir, 9)
        {
            int x2 = x + OFFSET[dir][0];
            int y2 = y + OFFSET[dir][1];
            int t2 = min(t + 1, 8);
            if (0 <= x2 && x2 < 8 && 0 <= y2 && y2 < 8 && !field[x2][y2][t2] && !been[x2][y2][t2])
            {
                been[x2][y2][t2] = true;
                q.emplace(x2, y2, t2);
                if (x2 == 0 && y2 == 7)
                {
                    cout << "WIN\n";
                    return;
                }
            }
        }
    }
    cout << "LOSE\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}