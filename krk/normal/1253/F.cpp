#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;
typedef pair <ll, ii> llii;
typedef pair <ll, int> lli;
typedef pair <int, ll> ill;

const int Maxn = 100005;
const int Maxm = 20;
const ll Inf = 1000000000000000000ll;

int n, m, k, q;
vector <ii> neigh[Maxn];
int par[Maxn], siz[Maxn];
ll dist[Maxn];
int p[Maxn];
vector <llii> E;
vector <ill> gneigh[Maxn];
int L[Maxn], P[Maxn][Maxm];
ll MX[Maxn][Maxm];

void Connect()
{
    fill(dist, dist + Maxn, Inf);
    priority_queue <lli> Q;
    for (int i = 1; i <= k; i++) {
        dist[i] = 0;
        p[i] = i;
        Q.push(lli(-dist[i], i));
    }
    while (!Q.empty()) {
        int v = Q.top().second;
        ll d = -Q.top().first; Q.pop();
        if (d != dist[v]) continue;
        for (int i = 0; i < neigh[v].size(); i++) {
            ii u = neigh[v][i];
            if (dist[u.first] < Inf && p[u.first] != p[v])
                E.push_back(llii(d + dist[u.first] + ll(u.second), ii(p[v], p[u.first])));
            if (d + u.second < dist[u.first]) {
                dist[u.first] = d + u.second;
                p[u.first] = p[v];
                Q.push(lli(-dist[u.first], u.first));
            }
        }
    }
}

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

void Traverse(int v)
{
    for (int i = 0; i < gneigh[v].size(); i++) {
        ill u = gneigh[v][i];
        if (P[v][0] == u.first) continue;
        L[u.first] = L[v] + 1;
        P[u.first][0] = v; MX[u.first][0] = u.second;
        Traverse(u.first);
    }
}

ll getMax(int a, int b)
{
    if (L[a] < L[b]) swap(a, b);
    ll res = 0;
    for (int i = Maxm - 1; i >= 0; i--)
        if (L[a] - (1 << i) >= L[b]) {
            res = max(res, MX[a][i]);
            a = P[a][i];
        }
    if (a == b) return res;
    for (int i = Maxm - 1; i >= 0; i--)
        if (P[a][i] != P[b][i]) {
            res = max(res, max(MX[a][i], MX[b][i]));
            a = P[a][i], b = P[b][i];
        }
    res = max(res, max(MX[a][0], MX[b][0]));
    return res;
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(ii(b, c));
        neigh[b].push_back(ii(a, c));
    }
    Connect();
    for (int i = 1; i <= k; i++)
        par[i] = i, siz[i] = 1;
    sort(E.begin(), E.end());
    for (int i = 0; i < E.size(); i++) {
        int a = E[i].second.first, b = E[i].second.second;
        if (unionSet(a, b)) {
            gneigh[a].push_back(ill(b, E[i].first));
            gneigh[b].push_back(ill(a, E[i].first));
        }
    }
    Traverse(1);
    for (int j = 1; j < Maxm; j++)
        for (int i = 1; i <= n; i++) {
            int mid = P[i][j - 1];
            P[i][j] = P[mid][j - 1];
            MX[i][j] = max(MX[i][j - 1], MX[mid][j - 1]);
        }
    for (int i = 0; i < q; i++) {
        int a, b; scanf("%d %d", &a, &b);
        printf("%I64d\n", getMax(a, b));
    }
    return 0;
}