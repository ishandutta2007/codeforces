#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 505;
const int Maxd = 5;
const int dy[Maxd] = {-1, 0, 0, 0, 1};
const int dx[Maxd] = {0, -1, 0, 1, 0};

int n, m, k;
char B[Maxn][Maxn];
ll stars[Maxn][Maxn];
ll res;

bool Star(int r, int c)
{
     for (int i = 0; i < Maxd; i++)
         if (B[r + dy[i]][c + dx[i]] == '0') return false;
     return true;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i <= n + 1; i++) B[i][0] = B[i][m + 1] = '0';
    for (int j = 0; j <= m + 1; j++) B[0][j] = B[n + 1][j] = '0';
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> B[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            stars[i][j] = stars[i - 1][j] + stars[i][j - 1] - stars[i - 1][j - 1] + Star(i, j);
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            int ri = n;
            for (int rj = j + 1; rj <= m; rj++) {
                while (stars[ri - 1][rj - 1] - stars[ri - 1][j] - 
                       stars[i][rj - 1] + stars[i][j] >= ll(k))
                      ri--;
                res += n - ri;
            }
        }
    cout << res << endl;
    return 0;
}