#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxb = 30;

int n;
int a[Maxn];
int X[Maxn];
int has[Maxb];

void Insert(int x)
{
    for (int i = Maxb - 1; i >= 0; i--) if (x & 1 << i)
        if (has[i] == -1) { has[i] = x; break; }
        else x ^= has[i];
}

int main()
{
    fill(has, has + Maxb, -1);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        X[i] = (X[i - 1] ^ a[i]);
    }
    if (X[n] == 0) { printf("-1\n"); return 0; }
    for (int i = n; i > 0; i--)
        Insert(X[i]);
    int res = 0;
    for (int i = 0; i < Maxb; i++)
        if (has[i] != -1) res++;
    printf("%d\n", res);
    return 0;
}