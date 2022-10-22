#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;
const int mod = 1000000007;

int n;
int X[Maxn], Y[Maxn];
vector <int> neigh[Maxn];
int tk[Maxn];

bool Traverse(int v, int col)
{
    if (tk[v]) return tk[v] == col;
    tk[v] = col;
    for (int i = 0; i < neigh[v].size(); i++)
        if (!Traverse(neigh[v][i], -col)) return false;
    return true;
}

int getWays(int x)
{
    for (int i = 0; i < n; i++) {
        neigh[i].clear();
        tk[i] = 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (abs(X[i] - X[j]) + abs(Y[i] - Y[j]) > x) {
                neigh[i].push_back(j);
                neigh[j].push_back(i);
            }
    int res = 1;
    for (int i = 0; i < n; i++) if (!tk[i]) {
        if (!Traverse(i, 1)) return 0;
        res = 2 * res % mod;
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &X[i], &Y[i]);
    int lef = 0, rig = 10000;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (getWays(mid) != 0) rig = mid - 1;
        else lef = mid + 1;
    }
    printf("%d\n", lef);
    printf("%d\n", getWays(lef));
    return 0;
}