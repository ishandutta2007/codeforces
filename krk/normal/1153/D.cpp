#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int n;
int f[Maxn];
vector <int> neigh[Maxn];

ii Get(int v)
{
    if (neigh[v].empty()) return ii(1, 1);
    else if (f[v] == 0) {
        ii res = ii(0, 0);
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            ii got = Get(u);
            res.first += got.first - 1;
            res.second += got.second;
        }
        res.first++;
        return res;
    } else {
        int mn = Maxn;
        ii res = ii(0, 0);
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            ii got = Get(u);
            mn = min(mn, got.second - got.first);
            res.second += got.second;
        }
        res.first = res.second - mn;
        return res;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &f[i]);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
    }
    printf("%d\n", Get(1).first);
    return 0;
}