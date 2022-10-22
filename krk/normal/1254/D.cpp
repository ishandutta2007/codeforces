#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int mod = 998244353;
const int Maxn = 150005;
const int Maxp = 780;

int n, q;
int invn;
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int cnt[Maxn];
int qa[Maxn], qb[Maxn], qc[Maxn];
bool tk1[Maxn], tk2[Maxn];
int myind1[Maxn], myind2[Maxn];
ii tmp[Maxp];
int tlen;
int mult[Maxp][Maxp];
bool tk[Maxn];
int acc[Maxn];
vector <int> seq;
int all;
int res[Maxn];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

void Traverse(int v, int p = 0)
{
    cnt[v] = 1;
    lef[v] = ++cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        cnt[v] += cnt[u];
    }
    rig[v] = cur;
}

int Mult(int a, int b)
{
    if (a == b) return 0;
    if (lef[a] <= lef[b] && lef[b] <= rig[a])
        return mult[myind1[a]][myind2[b]];
    return n - cnt[a];
}

void Prepare(int v, int p, int got)
{
    if (tk2[v])
        for (int i = 0; i < tlen; i++)
            mult[myind1[tmp[i].first]][myind2[v]] = tmp[i].second;
    if (acc[v] > 0) {
        int mult = n - cnt[v];
        all = (all + ll(mult) * acc[v]) % mod;
        got = (ll(got) - ll(mult) * acc[v] % mod + mod) % mod;
        res[v] = (res[v] + got) % mod;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (u == p) continue;
            if (tk1[v]) tmp[tlen++] = ii(v, cnt[u]);
            int ngot = (got + ll(cnt[u]) * acc[v]) % mod;
            Prepare(u, v, ngot);
            if (tk1[v]) tlen--;
        }
        acc[v] = 0;
    } else {
        res[v] = (res[v] + got) % mod;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (u == p) continue;
            if (tk1[v]) tmp[tlen++] = ii(v, cnt[u]);
            Prepare(u, v, got);
            if (tk1[v]) tlen--;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    invn = Inv(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; scanf("%d %d", &x, &y);
        neigh[x].push_back(y);
        neigh[y].push_back(x);
    }
    Traverse(1);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &qa[i], &qb[i]);
        if (qa[i] == 1) scanf("%d", &qc[i]);
    }
    for (int i = 0; i < q; i += Maxp) {
        int to = min(q, i + Maxp);
        int pnt1 = 0, pnt2 = 0;
        for (int j = i; j < to; j++)
            if (qa[j] == 1 && !tk1[qb[j]]) {
                tk1[qb[j]] = true;
                myind1[qb[j]] = pnt1++;
            } else if (qa[j] == 2 && !tk2[qb[j]]) {
                tk2[qb[j]] = true;
                myind2[qb[j]] = pnt2++;
            }
        Prepare(1, 0, 0);
        for (int j = i; j < to; j++)
            if (qa[j] == 1) {
                if (tk1[qb[j]]) { tk1[qb[j]] = false; seq.push_back(qb[j]); }
                all = (all + qc[j]) % mod;
                int add = (mod - ll(qc[j]) * invn % mod) % mod;
                acc[qb[j]] = (acc[qb[j]] + add) % mod;
            } else {
                tk2[qb[j]] = false;
                int ans = (all + res[qb[j]]) % mod;
                for (int k = 0; k < seq.size(); k++)
                    ans = (ans + ll(Mult(seq[k], qb[j])) * acc[seq[k]]) % mod;
                printf("%d\n", ans);
            }
        seq.clear();
    }
    return 0;
}