#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, ii> iiii;

const int Maxd = 8;
const int dy[Maxd] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dx[Maxd] = {-1, 1, -2, 2, -2, 2, -1, 1};

int k;
bool B[Maxd][Maxd];
bool tk[Maxd][Maxd];
vector <iiii> res;

void Move(int ax, int ay, int bx, int by)
{
    res.push_back(iiii(ii(ax, ay), ii(bx, by)));
    swap(B[ax][ay], B[bx][by]);
}

bool Solve(int x, int y)
{
    if (tk[x][y] || x < 0 || x >= Maxd || y < 0 || y >= Maxd) return false;
    tk[x][y] = true;
    if (B[x][y]) return true;
    for (int i = 0; i < Maxd; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (Solve(nx, ny)) {
            Move(nx, ny, x, y);
            return true;
        }
    }
    return false;
}

bool Solve2(int x, int y)
{
    if (tk[x][y] || x < 0 || x >= Maxd || y < 0 || y >= Maxd) return false;
    tk[x][y] = true;
    if (!B[x][y]) return true;
    for (int i = 0; i < Maxd; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (Solve2(nx, ny)) {
            Move(x, y, nx, ny);
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        string s; cin >> s;
        B[s[0] - 'a'][s[1] - '1'] = true;
    }
    if (k <= 32)
        for (int i = 0; i < k; i++) {
            for (int x = 0; x < Maxd; x++)
                for (int y = 0; y < Maxd; y++)
                    tk[x][y] = y * Maxd + x < i;
            int y = i / Maxd, x = i % Maxd;
            assert(Solve(x, y));
        }
    else for (int i = 0; i < 64 - k; i++) {
            for (int x = 0; x < Maxd; x++)
                for (int y = 0; y < Maxd; y++)
                    tk[Maxd - 1 - x][Maxd - 1 - y] = y * Maxd + x < i;
            int y = Maxd - 1 - i / Maxd, x = Maxd - 1 - i % Maxd;
            assert(Solve2(x, y));
        }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%c%c-%c%c\n", res[i].first.first + 'a', res[i].first.second + '1',
                              res[i].second.first + 'a', res[i].second.second + '1');
    return 0;
}