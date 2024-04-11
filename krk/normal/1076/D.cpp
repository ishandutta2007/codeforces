#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;
typedef pair <ll, int> lli;

const ll Inf = 1000000000000000000ll;
const int Maxn = 300005;

int n, m, k;
int A[Maxn], B[Maxn], C[Maxn];
bool incl[Maxn];
vector <ii> neigh[Maxn];
ll dist[Maxn];
int par[Maxn];
priority_queue <lli> Q;
int seq[Maxn], slen;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
        neigh[A[i]].push_back(ii(B[i], i));
        neigh[B[i]].push_back(ii(A[i], i));
    }
    int sav = min(n, 1 + k);
    fill(dist, dist + Maxn, Inf); dist[1] = 0; par[1] = 0;
    Q.push(lli(-dist[1], 1));
    while (!Q.empty() && sav) {
        int v = Q.top().second;
        ll d = -Q.top().first; Q.pop();
        if (d != dist[v]) continue;
        sav--;
        incl[par[v]] = true;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i].first;
            ll cand = d + C[neigh[v][i].second];
            if (cand < dist[u]) {
                dist[u] = cand;
                par[u] = neigh[v][i].second;
                Q.push(lli(-dist[u], u));
            }
        }
    }
    for (int i = 1; i <= m; i++)
        if (incl[i])
            seq[slen++] = i;
    printf("%d\n", slen);
    for (int i = 0; i < slen; i++)
        printf("%d%c", seq[i], i + 1 < slen? ' ': '\n');
    return 0;
}