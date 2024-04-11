#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 1005;

int n;
int A[Maxn], B[Maxn], C[Maxn];
vector <ii> neigh[Maxn];
ii P[Maxn];
int L[Maxn];
int root;
int rep[Maxn];
vector <iii> res;

void Traverse(int v)
{
    for (int i = 0; i < neigh[v].size(); i++)
        if (neigh[v][i].first == P[v].first) {
            neigh[v].erase(neigh[v].begin() + i);
            break;
        }
    if (neigh[v].empty()) { rep[v] = v; return; }
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        P[u.first] = ii(v, u.second); L[u.first] = L[v] + 1;
        Traverse(u.first);
        rep[v] = rep[u.first];
    }
}

void Add(int a, int b, int val)
{
    if (val == 0) return;
    res.push_back(iii(ii(a, b), val));
    while (a != b)
        if (L[a] >= L[b]) {
            C[P[a].second] -= val;
            a = P[a].first;
        } else {
            C[P[b].second] -= val;
            b = P[b].first;
        }
}

void Solve(int v)
{
    if (neigh[v].size() == 0)
        Add(v, root, C[P[v].second]);
    else if (neigh[v].size() == 1)
        Solve(neigh[v][0].first);
    else {
        while (neigh[v].size() > 2) {
            ii u = neigh[v].back(); neigh[v].pop_back();
            Solve(u.first);
        }
        int a = neigh[v][0].second, b = neigh[v][1].second;
        int x = (C[a] + C[b] - C[P[v].second]) / 2;
        int y = C[a] - x;
        Add(rep[neigh[v][0].first], rep[neigh[v][1].first], x);
        Add(rep[neigh[v][0].first], root, y);
        Solve(neigh[v][0].first);
        Solve(neigh[v][1].first);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
        neigh[A[i]].push_back(ii(B[i], i));
        neigh[B[i]].push_back(ii(A[i], i));
    }
    for (int i = 1; i <= n; i++)
        if (neigh[i].size() == 1) root = i;
        else if (neigh[i].size() == 2) {
            int u = neigh[i][0].second, v = neigh[i][1].second;
            if (C[u] != C[v]) { printf("NO\n"); return 0; }
        }
    Traverse(root);
    Solve(root);
    printf("YES\n");
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d %d\n", res[i].first.first, res[i].first.second, res[i].second);
    return 0;
}