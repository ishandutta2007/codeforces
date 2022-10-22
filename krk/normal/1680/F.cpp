#include <bits/stdc++.h>
using namespace std;

const int Maxn = 4000005;

int T;
int n, m;
int A[Maxn], B[Maxn];
int edge[Maxn], oth[Maxn];
int par[Maxn], col[Maxn], siz[Maxn];
int SA[Maxn], SB[Maxn], slen;
bool bad;
char res[Maxn];

int getPar(int x) { return par[x] == x? x: getPar(par[x]); }

int getColour(int x) { return par[x] == x? col[x]: (col[x] ^ getColour(par[x])); }

void unionSet(int a, int b)
{
    int para = getPar(a), parb = getPar(b);
    int cola = getColour(a), colb = getColour(b);
    if (para == parb) {
        if (cola == colb) bad = true;
        return;
    }
    if (siz[para] < siz[parb]) {
        swap(para, parb);
        swap(a, b);
        swap(cola, colb);
    }
    SA[slen] = para; SB[slen] = parb; slen++;
    siz[para] += siz[parb]; par[parb] = para;
    col[parb] = (cola ^ colb ^ 1);
}

void Undo(int waslen, bool wasbad)
{
    bad = wasbad;
    while (slen > waslen) {
        slen--;
        int a = SA[slen], b = SB[slen];
        siz[a] -= siz[b]; par[b] = b;
        col[b] = 0;
    }
}

bool Solve(int l, int r)
{
    if (bad || r < m - 1 || l >= 3 * m) return false;
    if (l == r) {
        for (int i = 1; i <= n; i++)
            res[i] = getColour(i) + '0';
        int wh = edge[l];
        if (res[A[wh]] == '0' && res[B[wh]] == '0') {
            for (int i = 1; i <= n; i++)
                res[i] = res[i] == '0'? '1': '0';
        }
        return true;
    }
    int m = l + r >> 1;
    int oldlen = slen;
    for (int i = m + 1; i <= r; i++)
        if (oth[i] <= l) {
            int ind = edge[i];
            unionSet(A[ind], B[ind]);
        }
    if (Solve(l, m)) return true;
    Undo(oldlen, false);
    for (int i = l; i <= m; i++)
        if (oth[i] > r) {
            int ind = edge[i];
            unionSet(A[ind], B[ind]);
        }
    if (Solve(m + 1, r)) return true;
    Undo(oldlen, false);
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            par[i] = i, col[i] = 0;
            siz[i] = 1;
        }
        slen = 0;
        bad = false;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &A[i], &B[i]);
            int a = i, b = m + 2 * i, c = m + 2 * i + 1, d = 3 * m + i;
            oth[a] = b; oth[b] = a;
            oth[c] = d; oth[d] = c;
            edge[a] = edge[b] = edge[c] = edge[d] = i;
        }
        if (Solve(0, 4 * m - 1)) {
            printf("YES\n");
            res[n + 1] = '\0';
            printf("%s\n", res + 1);
        } else printf("NO\n");
    }
    return 0;
}