#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, m;
int p[Maxn];
vector <ii> neigh[Maxn];
bool tk[Maxn];
int ind[Maxn];
vector <int> bef[Maxn];
vector <int> res;

void Write(int v)
{
    if (tk[v]) return;
    tk[v] = true;
    for (int i = 0; i < bef[v].size(); i++)
        Write(bef[v][i]);
    res.push_back(v);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(ii(b, i));
        neigh[b].push_back(ii(a, i));
    }
    for (int i = 1; i <= n; i++) if (!tk[i]) {
        vector <int> cycle;
        int num = i;
        while (!tk[num]) {
            ind[num] = cycle.size();
            cycle.push_back(num);
            tk[num] = true;
            num = p[num];
        }
        for (int i = 0; i < cycle.size(); i++) {
            int v = cycle[i];
            vector <ii> seq;
            for (int j = 0; j < neigh[v].size(); j++) {
                int u = neigh[v][j].first;
                seq.push_back(ii(ind[u], neigh[v][j].second));
            }
            sort(seq.begin(), seq.end());
            int st = lower_bound(seq.begin(), seq.end(), ii(ind[v], 0)) - seq.begin();
            if (st >= seq.size()) st = 0;
            for (int i = 0; i + 1 < seq.size(); i++) {
                int a = seq[(st + i) % int(seq.size())].second;
                int b = seq[(st + i + 1) % int(seq.size())].second;
                bef[b].push_back(a);
            }
        }
    }
    fill(tk, tk + m + 1, false);
    for (int i = 1; i <= m; i++)
        Write(i);
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}