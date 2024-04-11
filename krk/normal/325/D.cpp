#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;
 
const int Maxn = 3005;
const int Maxk = 300005;
const int Maxm = Maxn * Maxn + 2;
const int Maxs = 1000000;
const int Maxj = 21;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, 1, 0, -1};
 
int r, c, n;
int qr[Maxk], qc[Maxk];
int N;
int B[Maxn][Maxn];
int par[Maxm], siz[Maxm];
int rcnt, rl[Maxm];
int rlw[Maxm];
vector <ii> neigh[Maxm];
int L[Maxs], P[Maxs][Maxj], W[Maxs][Maxj];
bool el[Maxm];
 
int getId(int i, int j) { return 1 + i * c + j; }
 
int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }
 
bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}
 
void Join(int a, int b, int cost)
{
    if (unionSet(rl[a], rl[b])) {
        neigh[rl[a]].push_back(ii(rl[b], cost));
        neigh[rl[b]].push_back(ii(rl[a], cost));
    }
}
 
void Traverse(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        auto u = neigh[v][i];
        if (P[v][0] == u.first) continue;
        L[u.first] = L[v] + 1;
        P[u.first][0] = v;
        W[u.first][0] = u.second;
        Traverse(u.first);
    }
}
 
int getWorst(int a, int b)
{
    int res = min(rlw[a], rlw[b]);
    if (L[a] < L[b]) swap(a, b);
    for (int i = Maxj - 1; i >= 0; i--)
        if (L[a] - (1 << i) >= L[b]) {
            res = min(res, W[a][i]);
            a = P[a][i];
        }
    if (a == b) return res;
    for (int i = Maxj - 1; i >= 0; i--)
        if (P[a][i] != P[b][i]) {
            res = min(res, min(W[a][i], W[b][i]));
            a = P[a][i], b = P[b][i];
        }
    res = min(res, min(W[a][0], W[b][0]));
    return res;
}
 
void Solve(int a, int b)
{
    if (a != 0 && a != N - 1) swap(a, b);
    int mid = 0;
    if (b == 0 || b == N - 1)
        mid = getWorst(rl[a], rl[b]);
    else if (a == 0 || a == N - 1) {
        int curr = (b - 1) / c;
        int curc = (b - 1) % c;
        for (int d = 0; d < Maxd; d++) {
            int nr = curr + dy[d], nc = curc + dx[d];
            int u;
            if (nr < 0) u = 0;
            else if (nr >= r) u = N - 1;
            else {
                if (nc < 0) nc += c;
                if (nc >= c) nc -= c;
                u = getId(nr, nc);
            }
            mid = max(mid, getWorst(rl[a], rl[u]));
        }
    } else {
        int curr = (b - 1) / c;
        int curc = (b - 1) % c;
        int curr2 = (a - 1) / c;
        int curc2 = (a - 1) % c;
        int d1 = abs(curr - curr2);
        int d2 = abs(curc - curc2 + c) % c;
        d2 = min(d2, c - d2);
        if (d1 + d2 <= 1) return;
        for (int d = 0; d < Maxd; d++) {
            int nr = curr + dy[d], nc = curc + dx[d];
            int u;
            if (nr < 0) u = 0;
            else if (nr >= r) u = N - 1;
            else {
                if (nc < 0) nc += c;
                if (nc >= c) nc -= c;
                u = getId(nr, nc);
            }
            for (int d2 = 0; d2 < Maxd; d2++) {
                int nr2 = curr2 + dy[d2], nc2 = curc2 + dx[d2];
                int u2;
                if (nr2 < 0) u2 = 0;
                else if (nr2 >= r) u2 = N - 1;
                else {
                    if (nc2 < 0) nc2 += c;
                    if (nc2 >= c) nc2 -= c;
                    u2 = getId(nr2, nc2);
                }
                mid = max(mid, getWorst(rl[u], rl[u2]));
            }
        }
    }
    if (mid > n) return;
    el[mid] = true;
    int v = getId(qr[mid], qc[mid]);
    Solve(a, v);
    Solve(b, v);
}
 
int main()
{
    scanf("%d %d %d", &r, &c, &n);
    N = r * c + 2;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &qr[i], &qc[i]);
        qr[i]--; qc[i]--;
        B[qr[i]][qc[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        par[i] = i; siz[i] = 1;
    }
    for (int j = 0; j < c; j++) {
        if (!B[0][j]) unionSet(0, getId(0, j));
        if (!B[r - 1][j]) unionSet(N - 1, getId(r - 1, j));
    }
    for (int i = 0; i + 1 < r; i++)
        for (int j = 0; j < c; j++) if (!B[i][j]) {
            if (!B[i + 1][j]) unionSet(getId(i, j), getId(i + 1, j));
            int nj = (j + 1) % c;
            if (!B[i][nj]) unionSet(getId(i, j), getId(i, nj));
        }
    for (int i = 0; i < N; i++) if (i == getPar(i))
        rl[i] = ++rcnt;
    for (int i = 0; i < N; i++) {
        rl[i] = rl[getPar(i)];
    }
    for (int i = 1; i <= rcnt; i++) {
        par[i] = i;
        siz[i] = 1;
        rlw[i] = n + 1;
    }
    for (int i = 1; i <= n; i++)
        rlw[rl[getId(qr[i], qc[i])]] = i;
    for (int z = n; z > 0; z--) {
        int i = qr[z], j = qc[z];
        int v = getId(i, j);
        vector <ii> tmp;
        if (i == 0) tmp.push_back(ii(n + 1, 0));
        else if (!B[i - 1][j] || B[i - 1][j] >= z)
            tmp.push_back(ii(!B[i - 1][j]? n + 1: B[i - 1][j], getId(i - 1, j)));
        if (i == r - 1) tmp.push_back(ii(n + 1, N - 1));
        else if (!B[i + 1][j] || B[i + 1][j] >= z) tmp.push_back(ii(!B[i + 1][j]? n + 1: B[i + 1][j], getId(i + 1, j)));
        int nj = (j - 1 + c) % c;
        if (!B[i][nj] || B[i][nj] >= z) tmp.push_back(ii(!B[i][nj]? n + 1: B[i][nj], getId(i, nj)));
        nj = (j + 1) % c;
        if (!B[i][nj] || B[i][nj] >= z) tmp.push_back(ii(!B[i][nj]? n + 1: B[i][nj], getId(i, nj)));
        sort(tmp.rbegin(), tmp.rend());
        for (int j = 0; j < tmp.size(); j++)
            Join(v, tmp[j].second, z);
    }
    Traverse(rl[0]);
    for (int j = 1; j < Maxj; j++)
        for (int i = 1; i <= rcnt; i++) {
            int par = P[i][j - 1];
            P[i][j] = P[par][j - 1];
            W[i][j] = min(W[i][j - 1], W[par][j - 1]);
        }
    Solve(0, N - 1);
    int res = n;
    for (int i = 1; i <= n; i++) if (el[i])
        res--;
    printf("%d\n", res);
    return 0;
}