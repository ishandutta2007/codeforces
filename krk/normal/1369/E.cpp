#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, m;
int w[Maxn];
bool tk[Maxn];
int st[Maxn];
set <ii> neigh[Maxn];
queue <int> Q;
vector <int> res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d %d", &x, &y);
        w[x]--; neigh[x].insert(ii(y, i));
        w[y]--; neigh[y].insert(ii(x, i));
    }
    for (int i = 1; i <= n; i++)
        if (w[i] >= 0) {
            tk[i] = true;
            Q.push(i);
        }
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (auto p: neigh[v]) {
            int u = p.first;
            int ind = p.second;
            neigh[u].erase(ii(v, ind));
            res.push_back(ind);
            w[u]++;
            if (!tk[u] && w[u] >= 0) {
                tk[u] = true;
                Q.push(u);
            }
        }
    }
    if (res.size() < m) printf("DEAD\n");
    else {
        printf("ALIVE\n");
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}