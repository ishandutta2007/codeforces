#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n, m;
int par[Maxn], col[Maxn];
int siz[Maxn];
int A[Maxn], B[Maxn], C[Maxn];

ii getPar(int x)
{
    if (par[x] == x) return ii(x, col[x]);
    ii got = getPar(par[x]);
    par[x] = got.first;
    col[x] ^= got.second;
    return ii(par[x], col[x]);
}

bool unionSet(int a, int b, int C)
{
    ii para = getPar(a);
    ii parb = getPar(b);
    if (para.first == parb.first)
        return (para.second ^ parb.second) == C;
    if (siz[para.first] < siz[parb.first]) swap(para, parb);
    siz[para.first] += siz[parb.first];
    par[parb.first] = para.first;
    col[parb.first] = (para.second ^ C ^ parb.second);
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            par[i] = i; col[i] = 0;
            siz[i] = 1;
        }
        bool fall = false;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d %d", &A[i], &B[i], &C[i]);
            if (C[i] != -1) {
                int col = __builtin_popcount(C[i]) % 2;
                if (!unionSet(A[i], B[i], col)) fall = true;
            }
        }
        for (int i = 0; i < m; i++) {
            int a, b, p; scanf("%d %d %d", &a, &b, &p);
            if (!unionSet(a, b, p)) fall = true;
        }
        if (fall) { printf("NO\n"); continue; }
        printf("YES\n");
        for (int i = 0; i < n - 1; i++) {
            if (C[i] == -1) {
                ii a = getPar(A[i]);
                ii b = getPar(B[i]);
                if (a.first != b.first) {
                    unionSet(A[i], B[i], 0);
                    C[i] = 0;
                } else C[i] = (a.second ^ b.second);
            }
            printf("%d %d %d\n", A[i], B[i], C[i]);
        }
    }
    return 0;
}