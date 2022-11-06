#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define LL long long
#define MP make_pair
#define PB push_back
#define ff first
#define ss second

using namespace std;
const int N = 5005, M = 1000000007;
int n, a, b, k;
int dp[2][N];
inline int mod(int w)
{
    if(w >= M)
        return w - M;
    if(w < 0)
        return w + M;
    return w;
}
int main()
{
    scanf("%d%d%d%d", &n, &a, &b, &k);
    
    dp[0][a] = 1;
    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=n; j++)
            dp[1][j] = 0;
        int suma = 0, koniec = 1;
        for(int j=1; j<b; j++)
        {
            while(b - koniec > koniec - j)
            {
                suma += dp[0][koniec];
                suma = mod(suma);
                koniec++;
            }
            dp[1][j] = mod(suma - dp[0][j] + M);
        }
        suma = 0;
        koniec = n;
        for(int j=n; j>b; j--)
        {
            while(koniec - b > j - koniec)
            {
                suma += dp[0][koniec];
                suma = mod(suma);
                koniec--;
            }
            dp[1][j] = mod(suma - dp[0][j]);
        }
        for(int j=1; j<=n; j++)
            dp[0][j] = dp[1][j];
    }
    
    int wynik = 0;
    for(int i=1; i<=n; i++)
    {
        wynik = mod(wynik + dp[0][i]);
    }
    printf("%d", wynik);
    return 0;
}