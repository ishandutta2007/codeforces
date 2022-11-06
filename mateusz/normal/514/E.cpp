#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 1e9 + 7, D = 100;
int n, x;
int krotnosc[D + 5];
struct Macierz
{
    int tab[105][105];
    int size;
    Macierz(int s)
    {
        size = s;
        for(int i = 1; i <= size; i++)
            for(int j = 1; j <= size; j++)
                tab[i][j] = 0;
    }
    Macierz operator * (const Macierz &B)
    {
        Macierz ret(size);
        for(int i = 1; i <= size; i++)
        {
            for(int j = 1; j <= size; j++)
            {
                for(int k = 1; k <= size; k++)
                {
                    ret.tab[i][j] += (long long)tab[i][k] * B.tab[k][j]  % M;
                    ret.tab[i][j] %= M;
                }
            }
        }
        return ret;
    }
    void wypisz()
    {
        for(int i = 1; i <= size; i++)
        {
            for(int j = 1; j <= size; j++)
            {
                printf("%d ", tab[i][j]);
            }
            printf("\n");
        }
    }
};
Macierz jednostkowa(int s)
{
    Macierz ret(s);
    for(int i = 1; i <= ret.size; i++)
        for(int j = 1; j <= ret.size; j++)
            ret.tab[i][j] = (i == j);
    return ret;
}

Macierz potegowanie(Macierz A, int k)
{
    Macierz ret = jednostkowa(A.size);
    while(k >= 1)
    {
        if(k % 2 == 1)
        {
            ret = A * ret;
        }
        k /= 2;
        A = A * A;
    }
    return ret;
}
int przez_wektor(Macierz A, vector<int> v)
{
    int ret = 0;
    for(int i = 1; i <= D + 1; i++)
    {
        ret += (long long)A.tab[1][i] * v[i - 1] % M;
        ret %= M;
    }
    return ret;
}
int main()
{
    scanf("%d %d", &n, &x);
    for(int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        krotnosc[a]++;
    }
    Macierz X(D + 1);
    for(int i = 1; i <= D; i++)
        X.tab[1][i] = krotnosc[i];
    X.tab[1][D + 1] = 1;
    for(int i = 1; i < D; i++)
        X.tab[i + 1][i] = 1;
    X.tab[D + 1][D + 1] = 1;
    X = potegowanie(X, x);
    vector<int> v;
    v.push_back(1);
    for(int i = 1; i < D; i++)
        v.push_back(0);
    v.push_back(1);
    printf("%d\n", przez_wektor(X, v));
    return 0;
}