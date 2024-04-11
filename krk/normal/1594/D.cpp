#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

char tmp[50];
int T;
int n, m;
vector <ii> neigh[Maxn];
int col[Maxn];

bool Solve(int v, int c, ii &res)
{
    if (col[v]) return col[v] == c;
    col[v] = c;
    if (c == -1) res.first++;
    else res.second++;
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.second == 0) {
            if (!Solve(u.first, c, res)) return false;
        } else {
            if (!Solve(u.first, -c, res)) return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            col[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d %s", &a, &b, tmp);
            neigh[a].push_back(ii(b, tmp[0] == 'i'));
            neigh[b].push_back(ii(a, tmp[0] == 'i'));
        }
        int res = 0;
        bool ok = true;
        for (int i = 1; i <= n && ok; i++) if (!col[i]) {
            ii cur = ii(0, 0);
            ok = Solve(i, -1, cur);
            res += max(cur.first, cur.second);
        }
        printf("%d\n", ok? res: -1);
    }
    return 0;
}