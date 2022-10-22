#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int n;
vector <ii> seq;
vector <int> neigh[Maxn];
bool tk[Maxn];

int Ask(const vector <ii> &V)
{
    set <int> S;
    for (int i = 0; i < V.size(); i++) {
        S.insert(V[i].first);
        S.insert(V[i].second);
    }
    printf("? %d", int(S.size()));
    for (auto it: S)
        printf(" %d", it);
    printf("\n");
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void Answer(int a, int b)
{
    printf("! %d %d\n", a, b);
    fflush(stdout);
}

void Add(int v, vector <ii> &res)
{
    tk[v] = true;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (tk[u]) continue;
        res.push_back(ii(v, u));
        Add(u, res);
    }
}

void Solve(vector <ii> V, int res)
{
    if (V.size() == 1) Answer(V[0].first, V[0].second);
    else {
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            tk[i] = false;
        }
        for (int i = 0; i < V.size(); i++) {
            neigh[V[i].first].push_back(V[i].second);
            neigh[V[i].second].push_back(V[i].first);
        }
        V.clear();
        for (int i = 1; i <= n; i++) if (!tk[i])
            Add(i, V);
        int m = (V.size() - 1) / 2;
        vector <ii> A, B;
        for (int i = 0; i <= m; i++)
            A.push_back(V[i]);
        for (int i = m + 1; i < V.size(); i++)
            B.push_back(V[i]);
        if (Ask(A) == res)
            Solve(A, res);
        else Solve(B, res);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        seq.push_back(ii(a, b));
    }
    int res = Ask(seq);
    Solve(seq, res);
    return 0;
}