#include <iostream>
using namespace std;

const int Maxn = 255;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int t, n, m, ans;
bool B[Maxn][Maxn];

int Erase(int r, int c)
{
     if (!B[r][c]) return 0;
     int res = 1;
     B[r][c] = false;
     for (int i = 0; i < 8; i++)
        res += Erase(r+dx[i], c+dy[i]);
     return res;
}

int main()
{
    cin >> t;
    while (t--) {
          cin >> n >> m;
          fill((bool*)B, (bool*)B+Maxn*Maxn, false);
          char tmp;
          for (int i = 1; i <= n; i++)
             for (int j = 1; j <= m; j++) {
                 cin >> tmp;
                 B[i][j] = tmp == '1';
             }
          ans = 0;
          for (int i = 1; i <= n; i++)
             for (int j = 1; j <= m; j++) if (B[i][j]) {
                 int i2 = i + 1, j2 = j + 1;
                 while (B[i2][j]) i2++;
                 while (B[i][j2]) j2++;
                 if (i2 - i != j2 - j) Erase(i, j);
                 else {
                      i2--; j2--;
                      if (i2 == i && j2 == j) {
                             i2 = 1, j2 = 1;
                             while (B[i+i2][j+i2]) i2++;
                             while (B[i+j2][j-j2]) j2++;
                             if (i2 != j2) Erase(i, j);
                             else {
                                  i2--; j2--;
                                  int i3 = 1, j3 = 1;
                                  while (B[i+j2+i3][j-j2+i3]) i3++;
                                  while (B[i+i2+j3][j+i2-j3]) j3++;
                                  if (i3 == i2 + 1 && j3 == j2 + 1 &&
                                      4 * i2 == Erase(i, j)) ans++;
                                  Erase(i, j);
                             }
                      } else {
                             int i3 = i + 1, j3 = j + 1;
                             while (B[i3][j2]) i3++;
                             while (B[i2][j3]) j3++;
                             if (i3 == i2 + 1 && j3 == j2 + 1 && 
                                 2 * (i3 - i + j3 - j) - 4 == Erase(i, j)) ans++;
                             Erase(i, j);
                      }
                 }
             }
          cout << ans << endl;
    }
    return 0;
}