#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxb = 30;

int T;
int n, m;
int A[Maxn], B[Maxn], C[Maxn];
int par[Maxn], siz[Maxn], comp;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    comp--;
}

bool Check(int mask)
{
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        siz[i] = 1;
    }
    comp = n;
    for (int i = 1; i <= m; i++)
        if ((C[i] | mask) == mask)
            unionSet(A[i], B[i]);
    return comp == 1;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; i++)
            scanf("%d %d %d", &A[i], &B[i], &C[i]);
        int mask = (1 << Maxb) - 1;
        for (int b = Maxb - 1; b >= 0; b--) {
            mask ^= 1 << b;
            if (!Check(mask)) mask ^= 1 << b;
        }
        printf("%d\n", mask);
    }
    return 0;
}