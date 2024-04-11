#include <bits/stdc++.h>
using namespace std;

int n;
bool pr;

void Print(int x)
{
    if (pr) printf(" ");
    else pr = true;
    printf("%d", x);
}

void Solve(int n, int mult)
{
    if (n == 1) { Print(mult); return; }
    int pnt = 3;
    while (n / pnt == n / 2) pnt++;
    pnt--;
    for (int i = 1; i <= n; i++) if (i % pnt)
        Print(mult);
    Solve(n / pnt, mult * pnt);
}

int main()
{
    scanf("%d", &n);
    Solve(n, 1);
    printf("\n");
    return 0;
}