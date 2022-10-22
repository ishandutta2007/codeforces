#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, int> lli;
typedef pair <ll, ii> llii;

const int Maxn = 100005;
const ll Inf = 4000000000000000000ll;

int n, m;
vector <ii> neigh[Maxn];
int par[Maxn], siz[Maxn];
int k;
ll dist[Maxn];
int P[Maxn];
vector <llii> seq;
unsigned long long res;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(ii(b, c));
        neigh[b].push_back(ii(a, c));
    }
    scanf("%d", &k);
    fill(dist, dist + n + 1, Inf);
    priority_queue <lli> Q;
    while (k--) {
        int v; scanf("%d", &v);
        dist[v] = 0; P[v] = v;
        Q.push(lli(0, v));
    }
    while (!Q.empty()) {
        int v = Q.top().second;
        ll d = -Q.top().first; Q.pop();
        if (d != dist[v]) continue;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i].first;
            ll cand = d + neigh[v][i].second;
            if (P[u] != 0 && P[u] != P[v])
                seq.push_back(llii(cand + dist[u], ii(P[v], P[u])));
            if (cand < dist[u]) {
                dist[u] = cand;
                P[u] = P[v];
                Q.push(lli(-dist[u], u));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        par[i] = i, siz[i] = 1;
    sort(seq.begin(), seq.end());
    for (int i = 0; i < seq.size(); i++) {
        int a = seq[i].second.first;
        int b = seq[i].second.second;
        if (unionSet(a, b)) res += seq[i].first;
    }
    res += dist[1];
    cout << res << endl;
    return 0;
}