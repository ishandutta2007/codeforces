#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxm = 200005;
const int Maxn = 200005;

bool nprime[Maxm];
vector <int> pr;
int n;
int a[Maxn];
vector <int> V[Maxm];
vector <ii> E[Maxm];
vector <int> neigh[Maxn];
bool tk[Maxn];
int best[Maxn][2];
int res;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

void Solve(int v)
{
    tk[v] = true; best[v][0] = best[v][1] = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (tk[u]) continue;
        Solve(u);
        if (best[u][0] > best[v][0]) best[v][1] = best[v][0], best[v][0] = best[u][0];
        else if (best[u][0] > best[v][1]) best[v][1] = best[u][0];
    }
    res = max(res, best[v][0] + best[v][1] + 1);
    best[v][0]++; best[v][1]++;
}

int main()
{
    for (int i = 2; i < Maxm; i++) {
        if (!nprime[i]) pr.push_back(i);
        for (int j = 0; j < pr.size() && pr[j] * i < Maxm; j++) {
            nprime[pr[j] * i] = true;
            if (i % pr[j] == 0) break;
        }
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        V[a[i]].push_back(i);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; scanf("%d %d", &u, &v);
        E[gcd(a[u], a[v])].push_back(ii(u, v));
    }
    for (int i = 0; i < pr.size(); i++) {
        for (int j = pr[i]; j < Maxm; j += pr[i])
            for (int k = 0; k < V[j].size(); k++) {
                int v = V[j][k];
                neigh[v].clear(); tk[v] = false;
            }
        for (int j = pr[i]; j < Maxm; j += pr[i])
            for (int k = 0; k < E[j].size(); k++) {
                int a = E[j][k].first, b = E[j][k].second;
                neigh[a].push_back(b);
                neigh[b].push_back(a);
            }
        for (int j = pr[i]; j < Maxm; j += pr[i])
            for (int k = 0; k < V[j].size(); k++) {
                int v = V[j][k];
                if (!tk[v]) Solve(v);
            }
    }
    printf("%d\n", res);
    return 0;
}