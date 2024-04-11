#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 20;

int T;
int n;
vector <int> neigh[Maxn];
vector <int> L[2];
int res[Maxn];
vector <int> has[Maxm];

void Traverse(int v, int p, int lvl)
{
    L[lvl % 2].push_back(v);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v, lvl + 1);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        L[0].clear(); L[1].clear();
        Traverse(1, 0, 0);
        for (int i = 0; i < Maxm; i++)
            has[i].clear();
        for (int i = 1; i <= n; i++)
            for (int j = Maxm - 1; j >= 0; j--) if (i & 1 << j) {
                has[j].push_back(i);
                break;
            }
        for (int i = Maxm - 1; i >= 0; i--) {
            int ind = 0;
            if (has[i].size() > L[ind].size())
                ind++;
            while (!has[i].empty()) {
                int a = has[i].back(); has[i].pop_back();
                int b = L[ind].back(); L[ind].pop_back();
                res[b] = a;
            }
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}