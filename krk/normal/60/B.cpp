#include <iostream>
using namespace std;

const int Maxn = 11;

int k, n, m, ans;
bool empty[Maxn][Maxn][Maxn];

void Search(int lvl, int x, int y)
{
     if (lvl < 1 || lvl > k || x < 1 || x > n || y < 1 || y > m) return;
     if (!empty[lvl][x][y]) return;
     ans++; empty[lvl][x][y] = false;
     Search(lvl-1, x, y); Search(lvl+1, x, y);
     Search(lvl, x-1, y); Search(lvl, x+1, y);
     Search(lvl, x, y-1); Search(lvl, x, y+1);
}

int main()
{
    int x, y;
    char c;
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++)
       for (int j = 1; j <= n; j++)
          for (int l = 1; l <= m; l++) {
              cin >> c;
              empty[i][j][l] = c == '.';
          }
    cin >> x >> y;
    Search(1, x, y);
    cout << ans << endl;
    return 0;
}