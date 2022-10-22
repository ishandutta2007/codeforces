#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 85;
const int Inf = 1000000000;
const ll bInf = 1000000000000000000ll;

struct edge {
    int a, b, cap;
    ll val;
    edge(int a = 0, int b = 0, int cap = 0, ll val = 0ll): a(a), b(b), cap(cap), val(val) {}
};

int n, k;
int A[Maxn];
int c[Maxn];
int lst[Maxn];
vector <edge> E;
vector <int> neigh[Maxn];
ll dist[Maxn];
int par[Maxn];
ll res;

void addEdge(int a, int b, int cap, ll val)
{
    neigh[a].push_back(E.size());
    E.push_back(edge(a, b, cap, val));
    neigh[b].push_back(E.size());
    E.push_back(edge(b, a, 0, -val));
}

void getFlow()
{
    fill(dist, dist + n + 1, -bInf); dist[0] = 0;
    priority_queue <lli> Q; Q.push(lli(0, 0));
    while (!Q.empty()) {
        int v = Q.top().second;
        ll d = Q.top().first; Q.pop();
        if (dist[v] != d) continue;
        for (int i = 0; i < neigh[v].size(); i++) {
            int e = neigh[v][i];
            if (E[e].cap > 0 && d + E[e].val > dist[E[e].b]) {
                dist[E[e].b] = d + E[e].val;
                par[E[e].b] = e;
                Q.push(lli(dist[E[e].b], E[e].b));
            }
        }
    }
    int cur = n;
    res -= dist[cur];
    while (cur) {
        int e = par[cur];
        E[e].cap--;
        E[e ^ 1].cap++;
        cur = E[e].a;
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    fill(lst, lst + n + 1, -1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++) {
        res += c[A[i]];
        if (lst[A[i]] != -1) {
            if (lst[A[i]] < i - 1)
                addEdge(lst[A[i]], i - 1, 1, c[A[i]]);
            else res -= c[A[i]];
        }
        lst[A[i]] = i;
        res += Inf;
        addEdge(i - 1, i, 1, Inf);
        addEdge(i - 1, i, Inf, 0);
    }
    while (k--)
        getFlow();
    printf("%d\n", res);
    return 0;
}