#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int Maxn = 5005;

int n;
pair <int, int> a[Maxn];
vector <int> neigh[Maxn], id[Maxn];
int p[Maxn], u[Maxn];
int cap[Maxn][Maxn];
int res[Maxn];

void findPaths(int v, int par, int use)
{
     p[v] = par; u[v] = use;
     for (int i = 0; i < neigh[v].size(); i++) {
         int u = neigh[v][i];
         if (u == par) continue;
         findPaths(u, v, id[v][i]);
     }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    for (int i = 0; i < n - 1; i++) {
        int v, u, c;
        cin >> v >> u >> c;
        neigh[v].push_back(u); id[v].push_back(i);
        neigh[u].push_back(v); id[u].push_back(i);
        fill(cap[i], cap[i] + Maxn, c);
    }
    sort(a, a + n);
    findPaths(1, 0, -1);
    for (int i = 0; i < n; i++) {
        int v = a[i].second, t = 0;
        while (v != 1) {
              t++;
              while (!cap[u[v]][t]) t++;
              cap[u[v]][t]--;
              v = p[v];
        }
        res[a[i].second] = t;
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i];
        if (i + 1 <= n) cout << " ";
        else cout << endl;
    }
    return 0;
}