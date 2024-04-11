#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 5005;
const int Inf = 1000000000;

int n;
vector <ii> neigh[Maxn];
int L[Maxn], P[Maxn], W[Maxn];
int res[Maxn];
int m;
int A[Maxn], B[Maxn], C[Maxn];

void Traverse(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (P[v] == u.first) continue;
        P[u.first] = v; L[u.first] = L[v] + 1;
        W[u.first] = u.second; res[u.second] = 1;
        Traverse(u.first);
    }
}

void Update(int a, int b, int val)
{
    while (a != b) {
        if (L[a] < L[b]) swap(a, b);
        res[W[a]] = max(res[W[a]], val);
        a = P[a];
    }
}

bool Check(int a, int b, int val)
{
    int ans = Inf;
    while (a != b) {
        if (L[a] < L[b]) swap(a, b);
        ans = min(ans, res[W[a]]);
        a = P[a];
    }
    return ans == val;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; scanf("%d %d", &x, &y);
        neigh[x].push_back(ii(y, i));
        neigh[y].push_back(ii(x, i));
    }
    Traverse(1);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
        Update(A[i], B[i], C[i]);
    }
    for (int i = 0; i < m; i++)
        if (!Check(A[i], B[i], C[i])) { printf("-1\n"); return 0; }
    for (int i = 0; i < n - 1; i++)
        printf("%d%c", res[i], i + 1 < n - 1? ' ': '\n');
    return 0;
}