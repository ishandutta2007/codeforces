#define first f
#define second s
#include <iostream>
#include <vector>
#include <queue>
#define pb push_back

using namespace std;

constexpr int N = 7000, LOSE = 1, WIN = 2;

int n, r, m;
vector<int> s[2];
int res[2][7000];
int wst[2][7000];
queue<pair<int, int>> q;

void bfs()
{
    int p = q.front().f, o = q.front().s;
    q.pop();
    if (res[p][o] == LOSE)
        for (auto i: s[!p])
            if (!res[!p][(o + n - i) % n])
                res[!p][(o + n - i) % n] = WIN,
                q.push({!p, (o + n - i) % n});
    else;else
        for (auto i: s[!p])
            if (!res[!p][(o + n - i) % n] && ++wst[!p][(o + n - i) % n] == s[!p].size())
                res[!p][(o + n - i) % n] = LOSE,
                q.push({!p, (o + n - i) % n});
}

int main()
{
    cin >> n >> r;
    for (int i = 0; i < r; ++i)
        s[0].pb(0), cin >> s[0].back();
    cin >> m;
    for (int i = 0; i < m; ++i)
        s[1].pb(0), cin >> s[1].back();
    res[0][0] = res[1][0] = LOSE;
    q.push({0, 0});
    q.push({1, 0});
    while (q.size())
        bfs();
    for (int i = 0; i < 2; ++i, cout << '\n')
        for (int j = 1; j < n; ++j)
            cout << (vector<string>{"Loop ", "Lose ", "Win "})[res[i][j]];
    return 0;
}