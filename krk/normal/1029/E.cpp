#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxd = 3;

int n;
vector <int> neigh[Maxn];
int res;

ii Traverse(int v, int p, int root)
{
    int ch = int(neigh[v].size()) - (p != 0);
    if (ch == 0) return ii(0, 1);
    else {
        bool tk = false, mn = false;
        int res = 0;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (u == p) continue;
            ii got = Traverse(u, v, root);
            res += got.first;
            if (got.second == 1) tk = true;
            if (got.second == -1) mn = true;
        }
        if (tk) {
            if (v != root) res++;
            return ii(res, -1);
        }
        if (mn) return ii(res, 0);
        return ii(res, 1);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int i = 0; i < neigh[1].size(); i++) {
        int v = neigh[1][i];
        res += Traverse(v, 1, v).first;
    }
    cout << res << endl;
    return 0;
}