#include <iostream>
#include <string>
using namespace std;

const int Maxn = 20;

int a, b, s, x, ans;
string pic[Maxn];

bool Rot1(int sx1, int sy1, int sx2, int sy2, int xx, int yy)
{
     for (int i = 0; i < xx; i++)
        for (int j = 0; j < yy; j++)
           if (pic[sx1+i][sy1+j] != pic[sx2+j][sy2+yy-i-1]) return false;
     return true;
}

bool Rot2(int sx1, int sy1, int sx2, int sy2, int xx, int yy)
{
     for (int i = 0; i < xx; i++)
        for (int j = 0; j < yy; j++)
           if (pic[sx1+i][sy1+j] != pic[sx2+xx-j-1][sy2+i]) return false;
     return true;
}

bool Rot3(int sx1, int sy1, int sx2, int sy2, int xx, int yy)
{
     for (int i = 0; i < xx; i++)
        for (int j = 0; j < yy; j++)
           if (pic[sx1+i][sy1+j] != pic[sx2+i][sy2+j]) return false;
     return true;
}

bool Rot4(int sx1, int sy1, int sx2, int sy2, int xx, int yy)
{
     for (int i = 0; i < xx; i++)
        for (int j = 0; j < yy; j++)
           if (pic[sx1+i][sy1+j] != pic[sx2+xx-i-1][sy2+yy-j-1]) return false;
     return true;
}

void Try(int xx, int yy)
{
     for (int i = 0; i < a; i += xx)
        for (int j = 0; j < b; j += yy)
           for (int i2 = 0; i2 < a; i2 += xx)
              for (int j2 = 0; j2 < b; j2 += yy)
                 if (i != i2 || j != j2) {
                       if (xx == yy) {
                              if (Rot1(i, j, i2, j2, xx, yy)) return;
                              if (Rot2(i, j, i2, j2, xx, yy)) return;
                       }
                       if (Rot3(i, j, i2, j2, xx, yy)) return;
                       if (Rot4(i, j, i2, j2, xx, yy)) return;
                 }
     ans++;
     if (s == 0 || xx*yy < s || xx*yy == s && xx < x) {
           s = xx*yy;
           x = xx;
     }
}

int main()
{
    cin >> a >> b;
    for (int i = 0; i < a; i++) cin >> pic[i];
    for (int i = 1; i <= a; i++) if (a % i == 0)
       for (int j = 1; j <= b; j++) if (b % j == 0)
          Try(i, j);
    cout << ans << endl;
    cout << x << " " << s / x << endl;
    return 0;
}