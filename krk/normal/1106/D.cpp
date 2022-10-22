#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, m;
vector <int> neigh[Maxn];
bool tk[Maxn];
set <int> S;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    S.insert(1); tk[1] = true;
    bool pr = false;
    while (!S.empty()) {
        if (pr) printf(" ");
        else pr = true;
        int v = *S.begin(); S.erase(S.begin());
        printf("%d", v);
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (!tk[u]) { S.insert(u); tk[u] = true; }
        }
    }
    printf("\n");
    return 0;
}