#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int n, k, d;
ll mat[5][5];
ll akt[5][5];

void pomnoz(int type)
{
    ll tab[5][5];
    for (int i=1; i<=4; ++i)
        for (int j=1; j<=4; ++j) tab[i][j] = 0;
    for (int i=1; i<=4; ++i)
      for (int j=1; j<=4; ++j)
        for (int k=1; k<=4; ++k)
            if (!type) tab[i][j] += mat[i][k] * mat[k][j], tab[i][j] %= mod;
            else tab[i][j] += mat[i][k] * akt[k][j], tab[i][j] %= mod;
    if (!type) {
        for (int i=1; i<=4; ++i)
          for (int j=1; j<=4; ++j) mat[i][j] = tab[i][j];
    }
    else {
        for (int i=1; i<=4; ++i)
          for (int j=1; j<=4; ++j) akt[i][j] = tab[i][j];
    }

}
int main()
{
    cin >> n;
    for (int i=1; i<=4; ++i)
        for (int j=1; j<=4; ++j) mat[i][j] = 1;
    mat[1][1] = mat[2][2] = mat[3][3] = mat[4][4] = 0;
     for (int i=1; i<=4; ++i)
        for (int j=1; j<=4; ++j) akt[i][j] = mat[i][j];
    --n;
    while (n > 0)
    {
        if (n & 1) pomnoz(1);
        n /= 2;
        pomnoz(0);
    }
    cout << akt[1][1] % mod;
    
}