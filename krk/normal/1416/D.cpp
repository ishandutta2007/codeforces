#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 300005;
const int Maxq = 500005;

int n, m, q;
int P[Maxn];
int par[Maxn], siz[Maxn];
set <ii> S[Maxn];
int A[Maxm], B[Maxm];
bool was[Maxm];
int qa[Maxq], qb[Maxq];
ii und[Maxq];

int getPar(int x) { return par[x] == x? x: getPar(par[x]); }

ii unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return ii(-1, -1);
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    if (!S[b].empty()) {
        int val = S[b].rbegin()->first;
        S[a].insert(ii(val, b));
    }
    return ii(a, b);
}

void remBest(int v)
{
    if (S[v].empty()) return;
    set <ii>::iterator it = S[v].end(); it--;
    int from = it->second;
    S[v].erase(it);
    if (from == v) return;
    remBest(from);
    if (!S[from].empty()) {
        int val = S[from].rbegin()->first;
        S[v].insert(ii(val, from));
    }
}

int Get(int v)
{
    v = getPar(v);
    if (S[v].empty()) return 0;
    set <ii>::iterator it = S[v].end(); it--;
    int res = it->first;
    remBest(v);
    return res;
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &P[i]);
        S[i].insert(ii(P[i], i));
        par[i] = i, siz[i] = 1;
    }
    for (int i = 1; i <= m; i++)
        scanf("%d %d", &A[i], &B[i]);
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &qa[i], &qb[i]);
        if (qa[i] == 2) was[qb[i]] = true;
        und[i] = ii(-1, -1);
    }
    for (int i = 1; i <= m; i++)
        if (!was[i]) unionSet(A[i], B[i]);
    for (int i = q; i >= 1; i--)
        if (qa[i] == 2) {
            int ind = qb[i];
            und[i] = unionSet(A[ind], B[ind]);
        }
    for (int i = 1; i <= q; i++)
        if (qa[i] == 1) printf("%d\n", Get(qb[i]));
        else if (und[i].first != -1) {
            int a = und[i].first;
            int b = und[i].second;
            siz[a] -= siz[b]; par[b] = b;
            if (!S[b].empty()) {
                int val = S[b].rbegin()->first;
                S[a].erase(ii(val, b));
            }
        }
    return 0;
}