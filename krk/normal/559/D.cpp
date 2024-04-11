#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxn = 100005;
const int Maxm = 105;

ld pw[Maxm];
int n;
int X[Maxn], Y[Maxn];
ld res1, res2;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

void getApproxVal(int a, int b)
{
    int lef = (a - b - 1 + n) % n;
    ld tmp = (Y[a] + Y[b]) / 2.0l * (X[a] - X[b]);
    tmp -= gcd(abs(Y[a] - Y[b]), abs(X[a] - X[b])) / 2.0l;
    res1 += tmp / pw[n - lef];
}

ld solveApprox()
{
    for (int i = 0; i < n; i++)
        for (int j = 1; j < 100; j++)
            getApproxVal(i, (i + j) % n);
    return res1 + 1;
}

void getFullVal(int a, int b)
{
    int lef = (a - b - 1 + n) % n;
  //  printf("a = %d, b = %d, lef = %d\n", a, b, lef);
    ld tmp = (Y[a] + Y[b]) / 2.0l * (X[a] - X[b]);
    tmp -= gcd(abs(Y[a] - Y[b]), abs(X[a] - X[b])) / 2.0l;
    res1 += tmp * (pw[lef] - 1);
}

ld solveFull()
{
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
            getFullVal(i, (i + j) % n);
    res2 = pw[n] - 1 - ld(n) - ld(n) * (n - 1) / 2;
    return res1 / res2 + 1;
}

int main()
{
    pw[0] = 1;
    for (int i = 1; i < Maxm; i++)
        pw[i] = 2.0l * pw[i - 1];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &X[i], &Y[i]);
    cout << fixed << setprecision(15) << (n <= 100? solveFull(): solveApprox()) << endl;
    return 0;
}