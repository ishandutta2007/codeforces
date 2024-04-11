#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 500005;

int T;
vector <vector <int> > ans;
int n, m;
int nd;
vector <int> neigh[Maxn];
bool tk[Maxn];

void Traverse(int v, int lvl)
{
    tk[v] = true;
    if (ans.size() <= lvl) ans.push_back(vector<int>());
    ans[lvl].push_back(v);
    for (int i = 0; i < neigh[v].size() && ans.size() < nd; i++) {
        int u = neigh[v][i];
        if (!tk[u]) Traverse(u, lvl + 1);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        nd = (n + 1) / 2;
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            tk[i] = false;
        }
        ans.clear();
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        for (int i = 1; i <= n && ans.size() < nd; i++) if (!tk[i])
            Traverse(i, 0);
        if (ans.size() >= nd) {
            printf("PATH\n");
            printf("%d\n", int(ans.size()));
            for (int i = 0; i < ans.size(); i++)
                printf("%d%c", ans[i].back(), i + 1 < ans.size()? ' ': '\n');
        } else {
            vector <ii> res;
            for (int i = 0; i < ans.size(); i++)
                for (int j = 0; j + 1 < ans[i].size(); j += 2)
                    res.push_back(ii(ans[i][j], ans[i][j + 1]));
            printf("PAIRING\n");
            printf("%d\n", int(res.size()));
            for (int i = 0; i < res.size(); i++)
                printf("%d %d\n", res[i].first, res[i].second);
        }
    }
    return 0;
}