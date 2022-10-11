#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int M = 5005, N = 5005, Q = 5005;

int m, n, q, ans = 0, vis = 0, p[N], c[N], ind[Q], ret[Q], chk[M], mat[M];
bool rem[N];
vector<int> adj[M];

bool DFS(int u)
{
    chk[u] = vis;
    for (int &v : adj[u])
        if (mat[v] == -1)
        {
            mat[v] = u;
            return true;
        }
    for (int &v : adj[u])
        if (chk[mat[v]] < vis && DFS(mat[v]))
        {
            mat[v] = u;
            return true;
        }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    fill(mat, mat + m + 1, -1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> ind[i];
        rem[ind[i]] = true;
    }
    for (int i = 1; i <= n; i++)
        if (!rem[i])
            adj[p[i]].push_back(c[i]);
    for (int i = q; i >= 1; i--)
    {
        vis++;
        while (DFS(ans))
        {
            ans++;
            vis++;
        }
        ret[i] = ans;
        adj[p[ind[i]]].push_back(c[ind[i]]);
    }
    for (int i = 1; i <= q; i++)
        cout << ret[i] << '\n';
}