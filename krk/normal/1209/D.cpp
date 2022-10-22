#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, k;
int par[Maxn], siz[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        par[i] = i, siz[i] = 1;
    int res = 0;
    while (k--) {
        int a, b; scanf("%d %d", &a, &b);
        if (!unionSet(a, b)) res++;
    }
    printf("%d\n", res);
    return 0;
}