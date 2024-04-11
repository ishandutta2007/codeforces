#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
int was[Maxn];
int b[Maxn];
bool tk[Maxn];
int pnt = 1;
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        was[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        while (tk[pnt]) pnt++;
        if (was[b[i]] != pnt) res++;
        tk[was[b[i]]] = true;
    }
    printf("%d\n", res);
    return 0;
}