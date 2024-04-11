#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
const int Maxm = 21;

int T;
int n;
int a[Maxn];
int G[Maxn][Maxm];
int globalg;

int gcd(int a, int b) { return a? gcd(b % a, a): b; }

int Get(int ind)
{
    int g = 0;
    for (int j = Maxm - 1; j >= 0; j--) if (ind + (1 << j) <= 2 * n) {
        int nw = gcd(g, G[ind][j]);
        if (nw != globalg) { g = nw; ind += 1 << j; }
    }
    return ind;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        globalg = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            globalg = gcd(globalg, a[i]);
            a[n + i] = a[i];
        }
        for (int i = 0; i < 2 * n; i++)
            G[i][0] = a[i];
        for (int j = 1; j < Maxm; j++)
            for (int i = 0; i + (1 << j) <= 2 * n; i++)
                G[i][j] = gcd(G[i][j - 1], G[i + (1 << j - 1)][j - 1]);
        int res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, Get(i) - i);
        printf("%d\n", res);
    }
    return 0;
}