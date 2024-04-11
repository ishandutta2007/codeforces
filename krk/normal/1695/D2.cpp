#include <bits/stdc++.h>
using namespace std;

typedef pair <bool, bool> bb;

const int Maxn = 200005;

int T;
int n;
vector <int> neigh[Maxn];
int res;

bb Solve(int v, int p)
{
    int tk = 0;
    int deg = 0;
    bool wassafe = false;
    bool waslin = false;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        auto got = Solve(u, v);
        tk += got.first;
        deg++;
        if (got.second && !got.first) wassafe = true;
        if (got.second) waslin = true;
    }
    if (wassafe) {
        int add = max(0, deg - 1 - tk);
        tk += add; res += add;
    } else {
        int add = max(0, deg - tk);
        tk += add; res += add;
    }
    return bb(tk > 0, deg == 0 || deg == 1 && waslin);
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
        if (n == 1) { printf("0\n"); continue; }
        res = 0;
        int root = 1;
        while (root <= n && neigh[root].size() <= 2)
            root++;
        if (root > n) { printf("1\n"); continue; }
        Solve(root, 0);
        printf("%d\n", res);
    }
    return 0;
}