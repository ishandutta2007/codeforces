#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;

int L[Maxn], P[Maxn];
int n, k;
vector <int> neigh[Maxn];
priority_queue <ii> Q;
int sum[Maxn], lft[Maxn];
ll res;

void Traverse(int v, int p)
{
    lft[v] = int(neigh[v].size()) - (p != 0);
    if (int(neigh[v].size()) - (p != 0) == 0)
        Q.push(ii(L[v], v));
    P[v] = p;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        L[u] = L[v] + 1;
        Traverse(u, v);
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0);
    while (k > 0) {
        int v = Q.top().second;
        int val = Q.top().first; Q.pop();
        if (L[v] - sum[v] != val) continue;
        res += val; k--;
        sum[P[v]] += sum[v] + 1;
        if (--lft[P[v]] == 0)
            Q.push(ii(L[P[v]] - sum[P[v]], P[v]));
    }
    cout << res << endl;
    return 0;
}