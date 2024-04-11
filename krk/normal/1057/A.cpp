#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int P[Maxn];

void Print(int x)
{
    if (x == 1) printf("1");
    else {
        Print(P[x]);
        printf(" %d", x);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        scanf("%d", &P[i]);
    Print(n); printf("\n");
    return 0;
}