#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n;
int L[Maxn], R[Maxn];
int x;
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &L[i], &R[i]);
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
        if (x <= R[i]) res++;
    printf("%d\n", res);
    return 0;
}