#include <iostream>
#include <utility>
#include <cstring>
#include <queue>
#define N 2005

using namespace std;

const int dx[3] = {1, 0, -1};
const int dy[3] = {1, 0, -1};
char a[N][N];
queue<pair<int, int>> q;

int bad(int r, int c)
{
    for (int i = 0; i < 3; ++++i)
        for (int j = 0; j < 3; ++++j)
            if (a[r + dx[i]][c + dy[j]] + a[r][c + dy[j]] + a[r + dx[i]][c] == 0)
                return 1;
    return 0;
}

void bfs()
{
    int r = q.front().first;
    int c = q.front().second;
    q.pop();
    if (!a[r][c])
        return;
    if (!bad(r, c))
        return;
    a[r][c] = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            q.push({r + dx[i], c + dy[j]});
}

int main()
{
    cin.tie(0), ios_base::sync_with_stdio(0);
    memset(a, 1, sizeof(a));
    int n, m;
    cin >> n >> m;
    n += 4, m += 4;
    for (int r = 2; r < n - 2; ++r)
        for (int c = 2; c < m - 2; ++c)
            (cin >> a[r][c]), a[r][c] = a[r][c] == '*';
    for (int r = 1; r < n - 1; ++r)
        for (int c = 1; c < m - 1; ++c)
        {
            q.push({r, c});
            while (q.size())
                bfs();
        }
    for (int r = 2; (cout << '\n'), r < n - 2; ++r)
        for (int c = 2; c < m - 2; ++c)
            cout << ((a[r][c]? '*':'.'));
    return 0;
}