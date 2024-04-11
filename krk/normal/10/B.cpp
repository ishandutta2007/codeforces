#include <iostream>
#include <algorithm>
using namespace std;

const int Inf = 2000000000;
const int Maxk = 105;

int n, k, xc, yc;
bool del[Maxk][Maxk];

bool canGet(int x, int y, int m, int &res)
{
     res = 0;
     for (int j = y; j < y + m; j++) {
         if (del[x][j]) return false;
         res += abs(x - xc) + abs(j - yc);
     }
     return true;
}

bool canSolve(int m, int &x, int &yl, int &yr)
{
    int res = Inf;
    for (int i = 1; i <= k; i++)
       for (int j = 1; j + m <= k + 1; j++) {
           int curres;
           if (canGet(i, j, m, curres) && curres < res) {
                         res = curres;
                         x = i; yl = j; yr = j + m - 1;
           }
       }
    if (res == Inf) return false;
    for (int j = yl; j <= yr; j++) del[x][j] = true;
    return true;
}

int main()
{
    cin >> n >> k;
    xc = yc = (k + 1) / 2;
    while (n--) {
          int m; cin >> m;
          int x, yl, yr;
          if (canSolve(m, x, yl, yr)) cout << x << " " << yl << " " << yr << endl;
          else cout << "-1\n";
    }
    return 0;
}