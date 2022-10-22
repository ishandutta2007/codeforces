#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2000005;

int n, p, M, m;
int N;
vector <int> neigh[Maxn];
int lef[Maxn], rig[Maxn];
int cur, tim[Maxn], low[Maxn];
vector <int> S;
bool onStack[Maxn];
int incomp[Maxn];
int numcomp;
vector <int> ans;

int Not(int v) { return v <= p + M + 1? p + M + 1 + v: v - (p + M + 1); }

int Spec(int ind) { return p + 1 + ind; }

void Connect(int v)
{
    tim[v] = low[v] = ++cur;
    S.push_back(v);
    onStack[v] = true;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (!tim[u]) { Connect(u); low[v] = min(low[v], low[u]); }
        else if (onStack[u]) low[v] = min(low[v], tim[u]);
    }
    if (low[v] == tim[v]) {
        numcomp++;
        int u;
        do {
            u = S.back(); S.pop_back();
            onStack[u] = false;
            incomp[u] = numcomp;
        } while (u != v);
    }
}

int main()
{
    scanf("%d %d %d %d", &n, &p, &M, &m);
    N = 2 * (p + M + 1);
    for (int i = 0; i < M; i++) {
        neigh[Not(Spec(i))].push_back(Not(Spec(i + 1)));
        neigh[Spec(i + 1)].push_back(Spec(i));
    }
    for (int i = 0; i < n; i++) {
        int x, y; scanf("%d %d", &x, &y);
        neigh[Not(x)].push_back(y);
        neigh[Not(y)].push_back(x);
    }
    for (int i = 1; i <= p; i++) {
        scanf("%d %d", &lef[i], &rig[i]);
        neigh[i].push_back(Spec(lef[i] - 1));
        neigh[i].push_back(Not(Spec(rig[i])));
        neigh[Spec(rig[i])].push_back(Not(i));
        neigh[Not(Spec(lef[i] - 1))].push_back(Not(i));
    }
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        neigh[u].push_back(Not(v));
        neigh[v].push_back(Not(u));
    }
    for (int i = 1; i <= N; i++) if (!tim[i])
        Connect(i);
    for (int i = 1; i <= N; i++)
        if (incomp[i] == incomp[Not(i)]) {
            printf("-1\n"); return 0;
        }
    int pnt = 0;
    while (incomp[Spec(pnt)] < incomp[Not(Spec(pnt))]) pnt++;
    for (int i = 1; i <= p; i++)
        if (incomp[i] < incomp[Not(i)]) ans.push_back(i);
    printf("%d %d\n", int(ans.size()), pnt);
    for (int i = 0; i < ans.size(); i++)
        printf("%d%c", ans[i], i + 1 < ans.size()? ' ': '\n');
    return 0;
}