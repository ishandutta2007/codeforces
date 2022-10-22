#include <bits/stdc++.h>
using namespace std;

const int Maxm = 16777216;
const int Maxn = 3000005;
const int Maxq = 5005;

char str[Maxn];
int slen;
int k;
int st[Maxm];
int wh[Maxn];
char val[Maxn];
int q;
int ql[Maxq], qr[Maxq];
int A[Maxn], alen;

void Create(int v, int l, int r)
{
    st[v] = r - l + 1;
    if (l < r) {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
    }
}

int Get(int v, int l, int r, int wh)
{
    if (l == r) return l;
    else {
        int m = l + r >> 1;
        if (wh <= st[2 * v]) return Get(2 * v, l, m, wh);
        else return Get(2 * v + 1, m + 1, r, wh - st[2 * v]);
    }
}

void Fill(int v, int l, int r, int a, int b)
{
    st[v] -= (b - a + 1);
    if (l == r) A[alen++] = l;
    else {
        int m = l + r >> 1;
        if (b <= st[2 * v]) { Fill(2 * v, l, m, a, b); return; }
        if (a > st[2 * v]) { Fill(2 * v + 1, m + 1, r, a - st[2 * v], b - st[2 * v]); return; }
        int sav = st[2 * v];
        Fill(2 * v, l, m, a, sav);
        Fill(2 * v + 1, m + 1, r, 1, b - sav);
    }
}

int main()
{
    scanf("%s", str); slen = strlen(str);
    scanf("%d", &k);
    Create(1, 1, k);
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
        scanf("%d %d", &ql[i], &qr[i]);
    for (int i = q - 1; i >= 0; i--)
        if (qr[i] < st[1]) {
            int lef = qr[i] + 1, rig = min(qr[i] + 1 + qr[i] - ql[i], st[1]);
            alen = 0;
            Fill(1, 1, k, lef, rig);
            int pnt = 0;
            for (int z = ql[i] + 1; z <= qr[i] && pnt < alen; z += 2)
                wh[A[pnt++]] = Get(1, 1, k, z);
            for (int z = ql[i]; z <= qr[i] && pnt < alen; z += 2)
                wh[A[pnt++]] = Get(1, 1, k, z);
        }
    alen = 0;
    Fill(1, 1, k, 1, st[1]);
    for (int i = 0; i < alen; i++)
        val[A[i]] = str[i];
    for (int i = 1; i <= k; i++) if (wh[i])
        val[i] = val[wh[i]];
    val[k + 1] = '\0';
    printf("%s\n", val + 1);
    return 0;
}