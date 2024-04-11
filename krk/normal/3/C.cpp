#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 3;

char B[Maxn][Maxn];

int Calc(char c)
{
    int res = 0;
    for (int i = 0; i < Maxn; i++)
       for (int j = 0; j < Maxn; j++)
          res += B[i][j] == c;
    return res;
}

bool Win(char c)
{
     for (int i = 0; i < Maxn; i++) {
         int j;
         for (j = 0; j < Maxn; j++) if (B[i][j] != c) break;
         if (j == Maxn) return true;
     }
     for (int j = 0; j < Maxn; j++) {
         int i;
         for (i = 0; i < Maxn; i++) if (B[i][j] != c) break;
         if (i == Maxn) return true;
     }
     int i;
     for (i = 0; i < Maxn; i++) if (B[i][i] != c) break;
     if (i == Maxn) return true;
     for (i = 0; i < Maxn; i++) if (B[i][Maxn-1-i] != c) break;
     return i == Maxn;
}

int main()
{
    for (int i = 0; i < Maxn; i++)
       for (int j = 0; j < Maxn; j++) cin >> B[i][j];
    int X = Calc('X'), O = Calc('0');
    bool winX = Win('X'), winO = Win('0');
    if (X < O || X > O + 1 || winX && X == O || winO && X == O+1) cout << "illegal\n";
    else if (winX && winO) cout << "illegal\n";
    else if (winX) cout << "the first player won\n";
    else if (winO) cout << "the second player won\n";
    else if (X + O == Maxn*Maxn) cout << "draw\n";
    else if (X == O) cout << "first\n";
    else if (X == O + 1) cout << "second\n";
    else cout << "illegal\n";
    return 0;
}