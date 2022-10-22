#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n, m;
vector <int> neigh[Maxn];
int tim[Maxn];

int getCycle(int v, int t)
{
    if (tim[v] != -1) return t - tim[v];
    tim[v] = t;
    for (int i = 0; i < neigh[v].size(); i++) {
        int cand = getCycle(neigh[v][i], t + 1);
        if (cand != -1) return cand;
    }
    return -1;
}

bool Check(int v, int col, int mod)
{
    if (tim[v] != -1) return tim[v] == col;
    tim[v] = col;
    for (int i = 0; i < neigh[v].size(); i++)
        if (!Check(neigh[v][i], (col + 1) % mod, mod))
            return false;
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
    }
    fill(tim + 1, tim + n + 1, -1);
    int my = getCycle(1, 0);
    for (int i = my; i > 0; i--) if (my % i == 0) {
        fill(tim + 1, tim + n + 1, -1);
        if (Check(1, 0, i)) {
            printf("%d\n", i);
            vector <int> res;
            for (int j = 1; j <= n; j++) if (tim[j] == 0)
                res.push_back(j);
            printf("%d\n", int(res.size()));
            for (int j = 0; j < res.size(); j++)
                printf("%d%c", res[j], j + 1 < res.size()? ' ': '\n');
            break;
        }
    }
    return 0;
}