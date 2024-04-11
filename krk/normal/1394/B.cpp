#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxd = 10;

int n, m, k;
vector <ii> neigh[Maxn], rneigh[Maxn];
int forb[Maxd][Maxd][Maxd];
int seq[Maxd];
int res;

void Gen(int lvl)
{
    if (lvl > k) res++;
    else for (int i = 1; i <= lvl; i++) {
            seq[lvl] = i;
            bool fall = false;
            for (int j = 1; j <= lvl && !fall; j++)
                if (forb[lvl][i][j] & 1 << seq[j]) fall = true;
            if (!fall) Gen(lvl + 1);
        }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(ii(c, b));
        rneigh[b].push_back(ii(c, a));
    }
    for (int i = 1; i <= n; i++) {
        sort(neigh[i].begin(), neigh[i].end());
        if (neigh[i].empty()) { printf("0\n"); return 0; }
    }
    for (int i = 1; i <= n; i++) {
        vector <ii> un;
        for (int j = 0; j < rneigh[i].size(); j++) {
            ii p = rneigh[i][j];
            int v = p.second;
            p.second = i;
            int ind = 1 + lower_bound(neigh[v].begin(), neigh[v].end(), p) - neigh[v].begin();
            un.push_back(ii(neigh[v].size(), ind));
        }
        sort(un.begin(), un.end());
        for (int j = 1; j < un.size(); j++) {
            forb[un[j].first][un[j].second][un[j - 1].first] |= 1 << un[j - 1].second;
            if (un[j] != un[j - 1])
                for (int k = 0; k < j; k++)
                    forb[un[j].first][un[j].second][un[k].first] |= 1 << un[k].second;
        }
    }
    Gen(1);
    printf("%d\n", res);
    return 0;
}