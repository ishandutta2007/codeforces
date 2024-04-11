#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
vector <int> neigh[Maxn];
ll sum[Maxn];
int my[Maxn][2];
ll res;

void Traverse(int v, int p)
{
    my[v][0] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        sum[u] += my[u][1];
        swap(my[u][0], my[u][1]);
        res += ll(my[v][0] + my[v][1]) * sum[u] + ll(my[u][0] + my[u][1]) * sum[v];
        res += ll(my[v][0]) * my[u][1] + ll(my[v][1]) * my[u][0] + ll(my[v][1]) * my[u][1];
        sum[v] += sum[u];
        my[v][0] += my[u][0];
        my[v][1] += my[u][1];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0);
    cout << res << endl;
    return 0;
}