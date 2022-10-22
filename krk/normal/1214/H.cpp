#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, k;
vector <int> neigh[Maxn];
int L[Maxn], MX[Maxn];
int col[Maxn];

ii Traverse(int v, int p, int lvl = 0)
{
    L[v] = MX[v] = lvl;
    ii res = ii(L[v], v);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        ii got = Traverse(u, v, lvl + 1);
        MX[v] = max(MX[v], got.first);
        res = max(res, got);
    }
    return res;
}

bool Solve(int v, int p, int c)
{
    if (MX[v] + 1 >= k) {
        col[v] = L[v] % k;
        if (c != -1 && c != col[v]) return false;
        vector <int> difs;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (u == p) continue;
            if (MX[u] + 1 >= k)
                difs.push_back(MX[u] - L[v]);
        }
        sort(difs.rbegin(), difs.rend());
        if (difs.size() >= 2 && difs[0] + difs[1] + 1 >= k) return false;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (u == p) continue;
            if (MX[u] + 1 >= k) {
                if (!Solve(u, v, -1)) return false;
            } else if (!Solve(u, v, (L[v] - 1 + k) % k)) return false;
        }
        return true;
    } else {
        if (c != -1) col[v] = c;
        else col[v] = L[v] % k;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (u == p) continue;
            if (c != -1) {
                if (!Solve(u, v, (c - 1 + k) % k)) return false;
            } else if (!Solve(u, v, -1)) return false;
        }
        return true;
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    int a = Traverse(1, 0).second;
    int b = Traverse(a, 0).second;
    Traverse(b, 0);
    if (k == 2) {
        printf("Yes\n");
        for (int i = 1; i <= n; i++)
            printf("%d%c", L[i] % 2 + 1, i + 1 <= n? ' ': '\n');
        return 0;
    }
    if (Solve(b, 0, -1)) {
        printf("Yes\n");
        for (int i = 1; i <= n; i++)
            printf("%d%c", col[i] + 1, i + 1 <= n? ' ': '\n');
    } else printf("No\n");
    return 0;
}