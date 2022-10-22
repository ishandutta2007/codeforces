#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const ll Inf = 1000000000000000000ll;
const int Maxn = 100005;
const int Maxk = 20;
const int Maxm = 50;

int n, m;
int par[Maxn], siz[Maxn];
vector <ii> neigh[Maxn];
map <int, int> ID;
vector <int> un;
ll dist[Maxm][Maxm];
int L[Maxn];
ll W[Maxn];
int P[Maxn][Maxk];
int q;
ll distA[Maxm], distB[Maxm];

int getId(int x)
{
    auto it = ID.find(x);
    if (it == ID.end()) {
        int cur = ID.size();
        un.push_back(x);
        ID.insert(make_pair(x, cur));
        return cur;
    }
    return it->second;
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

int getLCA(int a, int b)
{
    if (L[a] < L[b]) swap(a, b);
    for (int i = Maxk - 1; i >= 0; i--)
        if (L[a] - (1 << i) >= L[b])
            a = P[a][i];
    if (a == b) return a;
    for (int i = Maxk - 1; i >= 0; i--)
        if (P[a][i] != P[b][i])
            a = P[a][i], b = P[b][i];
    return P[a][0];
}

ll getDist(int a, int b)
{
    int lca = getLCA(a, b);
    return W[a] + W[b] - 2 * W[lca];
}

void Traverse(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        ll a = neigh[v][i].second;
        if (P[v][0] == u) continue;
        P[u][0] = v;
        L[u] = L[v] + 1;
        W[u] = W[v] + a;
        Traverse(u);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        siz[i] = 1;
    }
    for (int i = 0; i < Maxm; i++)
        for (int j = 0; j < Maxm; j++)
            dist[i][j] = ll(i != j) * Inf;
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        if (unionSet(a, b)) {
            neigh[a].push_back(ii(b, c));
            neigh[b].push_back(ii(a, c));
        } else {
            a = getId(a);
            b = getId(b);
            dist[a][b] = dist[b][a] = min(dist[a][b], ll(c));
        }
    }
    Traverse(1);
    for (int j = 1; j < Maxk; j++)
        for (int i = 1; i <= n; i++)
            P[i][j] = P[P[i][j - 1]][j - 1];
    for (int i = 0; i < ID.size(); i++)
        for (int j = i + 1; j < ID.size(); j++) {
            ll cand = getDist(un[i], un[j]);
            dist[i][j] = dist[j][i] = min(dist[i][j], cand);
        }
    for (int k = 0; k < ID.size(); k++)
        for (int i = 0; i < ID.size(); i++)
            for (int j = 0; j < ID.size(); j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    scanf("%d", &q);
    while (q--) {
        int a, b; scanf("%d %d", &a, &b);
        ll res = getDist(a, b);
        for (int i = 0; i < ID.size(); i++) {
            distA[i] = getDist(a, un[i]);
            distB[i] = getDist(b, un[i]);
        }
        for (int i = 0; i < ID.size(); i++)
            for (int j = 0; j < ID.size(); j++)
                res = min(res, distA[i] + dist[i][j] + distB[j]);
        printf("%I64d\n", res);
    }
    return 0;
}