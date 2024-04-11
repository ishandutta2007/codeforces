#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 50;

int a, b, c, d, n, B[2][Maxn][Maxn], pnt;
vector <int> xs;

void Fill(int wh, int x, int y, int dy)
{
     if (x == a && wh == 0) Fill(wh+1, 0, y, dy);
     else if (x == c && wh == 1) return;
     else if (wh == 0 && y == b) Fill(wh, x+1, b-1, -1);
     else if (wh == 1 && y == d) Fill(wh, x+1, d-1, -1);
     else if (y < 0) Fill(wh, x+1, 0, 1);
     else {
          B[wh][x][y] = pnt + 1; xs[pnt]--;
          while (xs[pnt] == 0 && pnt < xs.size()) pnt++;
          Fill(wh, x, y+dy, dy);
     }
}

int main()
{
    cin >> a >> b >> c >> d >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        xs.push_back(tmp);
    }
    while (xs[pnt] == 0) pnt++;
    if (a % 2) Fill(0, 0, b-1, -1);
    else Fill(0, 0, 0, 1);
    cout << "YES\n";
    for (int i = 0; i < max(b, d); i++) {
        for (int j = 0; j < a; j++)
           if (B[0][j][i]) cout << char('a' + B[0][j][i] - 1);
           else cout << '.';
        for (int j = 0; j < c; j++)
           if (B[1][j][i]) cout << char('a' + B[1][j][i] - 1);
           else cout << '.';
        cout << endl;
    }
    return 0;
}