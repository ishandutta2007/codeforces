#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxk = 5;
const int Maxp = 320;

int n, k;
int m;
int par[Maxn], siz[Maxn];
int comp;
int tolef[Maxn][Maxk], torig[Maxn][Maxk];
int tls[Maxn], trs[Maxn];
ii mem[Maxn];
int mlen;
int q;
int ql[Maxn], qr[Maxn];
vector <ii> quer[Maxp];
int res[Maxn];

int fastGetPar(int x) { return par[x] == x? x: par[x] = fastGetPar(par[x]); }

void fastUnionSet(int a, int b)
{
    a = fastGetPar(a), b = fastGetPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    comp--;
}

int slowGetPar(int x) { return par[x] == x? x: slowGetPar(par[x]); }

void slowUnionSet(int a, int b)
{
    a = slowGetPar(a), b = slowGetPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    mem[mlen++] = ii(a, b);
}

int addAndSolve(int l, int r, int R)
{
    for (int i = r; i >= l; i--) {
        par[i] = i; siz[i] = 1;
        for (int j = 0; j < trs[i]; j++) {
            int u = torig[i][j];
            if (u <= R) slowUnionSet(i, u);
        }
    }
    int res = comp + (r - l + 1) - mlen;
    while (mlen > 0) {
        auto p = mem[--mlen];
        siz[p.first] -= siz[p.second];
        par[p.second] = p.second;
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        torig[a][trs[a]++] = b;
        tolef[b][tls[b]++] = a;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &ql[i], &qr[i]);
        if (qr[i] - ql[i] <= Maxp)
            res[i] = addAndSolve(ql[i], qr[i], qr[i]);
        else quer[ql[i] / Maxp + 1].push_back(ii(qr[i], i));
    }
    for (int i = 0; i < Maxp; i++) if (!quer[i].empty()) {
        sort(quer[i].begin(), quer[i].end());
        int L = i * Maxp, R = i * Maxp - 1;
        comp = 0;
        for (int j = 0; j < quer[i].size(); j++) {
            int ind = quer[i][j].second;
            while (R < qr[ind]) {
                R++; comp++;
                par[R] = R; siz[R] = 1;
                for (int j = 0; j < tls[R]; j++) {
                    int u = tolef[R][j];
                    if (u >= L) fastUnionSet(R, u);
                }
            }
            res[ind] = addAndSolve(ql[ind], L - 1, R);
        }
    }
    for (int i = 0; i < q; i++)
        printf("%d\n", res[i]);
    return 0;
}