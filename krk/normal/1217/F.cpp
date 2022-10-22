#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;
const int Maxp = 1000;

typedef pair <int, int> ii;

int n, m;
int typ[Maxn], qa[Maxn], qb[Maxn];
int a1[Maxn], b1[Maxn];
int a2[Maxn], b2[Maxn];
set <ii> S, spec;
multiset <int> neigh[Maxn];
int tk[Maxn];
int seq[Maxn], slen;
int par[Maxn], siz[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
}

bool Find(int a, int b)
{
    if (a == b) return true;
    if (tk[a]) return false;
    tk[a] = true;
    seq[slen++] = a;
    for (auto it: neigh[a])
        if (Find(it, b)) return true;
    return false;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &typ[i], &qa[i], &qb[i]);
    int lst = 0;
    for (int i = 0; i < m; i += Maxp) {
        int to = min(i + Maxp, m);
        for (int j = i; j < to; j++) {
            a1[j] = (qa[j] + n - 1) % n + 1;
            b1[j] = (qb[j] + n - 1) % n + 1;
            a2[j] = (qa[j] + n) % n + 1;
            b2[j] = (qb[j] + n) % n + 1;
            if (a1[j] > b1[j]) swap(a1[j], b1[j]);
            if (a2[j] > b2[j]) swap(a2[j], b2[j]);
            if (typ[j] == 1) {
                spec.insert(ii(a1[j], b1[j]));
                spec.insert(ii(a2[j], b2[j]));
            }
        }
        for (int j = 1; j <= n; j++)
            par[j] = j, siz[j] = 1;
        for (auto it: S)
            if (spec.find(it) == spec.end())
                unionSet(it.first, it.second);
        for (auto it: S)
            if (spec.find(it) != spec.end()) {
                neigh[getPar(it.first)].insert(getPar(it.second));
                neigh[getPar(it.second)].insert(getPar(it.first));
            }
        for (int j = i; j < to; j++) {
            int a, b;
            if (lst == 0) a = a1[j], b = b1[j];
            else a = a2[j], b = b2[j];
            if (typ[j] == 1)
                if (S.find(ii(a, b)) == S.end()) {
                    S.insert(ii(a, b));
                    neigh[getPar(a)].insert(getPar(b));
                    neigh[getPar(b)].insert(getPar(a));
                } else {
                    S.erase(ii(a, b));
                    neigh[getPar(a)].erase(neigh[getPar(a)].find(getPar(b)));
                    neigh[getPar(b)].erase(neigh[getPar(b)].find(getPar(a)));
                }
            else {
                for (int z = 0; z < slen; z++)
                    tk[seq[z]] = false;
                slen = 0;
                lst = Find(getPar(a), getPar(b));
                printf("%d", lst);
            }
        }
        for (auto it: spec)
            if (S.find(it) != S.end()) {
                neigh[getPar(it.first)].erase(neigh[getPar(it.first)].find(getPar(it.second)));
                neigh[getPar(it.second)].erase(neigh[getPar(it.second)].find(getPar(it.first)));
            }
        spec.clear();
    }
    printf("\n");
    return 0;
}