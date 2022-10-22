#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int Maxn = 21;

ull C[Maxn][Maxn];
ull fac[Maxn];
int n;

int main()
{
    fac[0] = 1;
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        if (i) fac[i] = i * fac[i - 1];
        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    scanf("%d", &n);
    cout << C[n - 1][n / 2 - 1] * fac[n / 2 - 1] * fac[n / 2 - 1] << endl;
    return 0;
}