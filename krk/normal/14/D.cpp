#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 205;

int n;
int a[Maxn], b[Maxn];
vector <int> neigh[Maxn];
bool vis[Maxn];
int best[Maxn], h[Maxn];
int res;

void Search(int v, int p)
{
     vis[v] = true;
     for (int i = 0; i < neigh[v].size(); i++) {
         int u = neigh[v][i];
         if (u != p) Search(u, v);
     }
     for (int i = 0; i < neigh[v].size(); i++) {
         int a = neigh[v][i];
         if (a == p) continue;
         h[v] = max(h[v], h[a] + 1);
         best[v] = max(best[v], best[a]);
         for (int j = 0; j < neigh[v].size(); j++) {
             int b = neigh[v][j];
             if (a != b && b != p) best[v] = max(best[v], h[a] + h[b] + 2);
         }
     }
     best[v] = max(best[v], h[v]);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i];
        neigh[a[i]].push_back(b[i]); neigh[b[i]].push_back(a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        neigh[a[i]].erase(find(neigh[a[i]].begin(), neigh[a[i]].end(), b[i]));
        neigh[b[i]].erase(find(neigh[b[i]].begin(), neigh[b[i]].end(), a[i]));
        fill(vis, vis + n + 1, false); fill(best, best + n + 1, 0); fill(h, h + n + 1, 0);
        int cand = 1;
        for (int j = 1; j <= n; j++)
            if (!vis[j]) {
                         Search(j, 0);
                         cand *= best[j];
            }
        res = max(res, cand);
        neigh[a[i]].push_back(b[i]); neigh[b[i]].push_back(a[i]);
    }
    cout << res << endl;
    return 0;
}