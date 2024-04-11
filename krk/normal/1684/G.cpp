#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1005;

int n, m;
int a[Maxn];
vector <int> un;
vector <int> cnt;
int R[Maxn][Maxn];
vector <int> neigh[Maxn];
int N;
vector <ii> res;
int fl[Maxn], par[Maxn];

void addEdge(int a, int b, int cap)
{
    R[a][b] = cap;
    neigh[a].push_back(b);
    neigh[b].push_back(a);
}

int getFlow()
{
    fill(fl, fl + Maxn, 0); fl[0] = Maxn;
    priority_queue <ii> Q; Q.push(ii(fl[0], 0));
    while (!Q.empty()) {
        int v = Q.top().second, f = Q.top().first; Q.pop();
        if (fl[v] != f) continue;
        if (v == N - 1) break;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            int cand = min(f, R[v][u]);
            if (cand > fl[u]) {
                fl[u] = cand;
                par[u] = v;
                Q.push(ii(fl[u], u));
            }
        }
    }
    int v = N - 1;
    int res = fl[v];
    if (!res) return res;
    while (v) {
        int u = par[v];
        R[u][v] -= res;
        R[v][u] += res;
        v = u;
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        un.push_back(a[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    cnt.resize(un.size(), 0);
    for (int i = 1; i <= n; i++) {
        int ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
        cnt[ind]++;
    }
    int need = 0;
    N = int(un.size()) + 2;
    for (int i = 0; i < un.size(); i++)
        if (3ll * ll(un[i]) <= m) addEdge(i + 1, N - 1, cnt[i]);
        else {
            need += cnt[i];
            addEdge(0, i + 1, cnt[i]);
            for (int j = 0; j < i; j++) if (un[i] % un[j] == 0 && 2ll * ll(un[i]) + ll(un[j]) <= m)
                addEdge(i + 1, j + 1, cnt[i]);
        }
    int tot = 0, f;
    while ((f = getFlow()) != 0)
        tot += f;
    if (tot < need) { printf("-1\n"); return 0; }
    for (int i = 0; i < un.size(); i++)
        if (3ll * ll(un[i]) <= m) {
            int lft = R[i + 1][N - 1];
            while (lft--) res.push_back(ii(3 * un[i], 2 * un[i]));
        } else for (int j = 0; j < i; j++)
                while (R[j + 1][i + 1]--)
                    res.push_back(ii(2 * un[i] + un[j], un[i] + un[j]));
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}