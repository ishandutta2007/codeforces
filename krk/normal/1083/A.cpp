#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 300005;

int n;
int w[Maxn];
vector <ii> neigh[Maxn];
ll res;

ll Traverse(int v, int p)
{
    ll best[2] = {0, 0};
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p) continue;
        ll cand = Traverse(u.first, v) - u.second;
        if (cand > best[0]) best[1] = best[0], best[0] = cand;
        else if (cand > best[1]) best[1] = cand;
    }
    res = max(res, best[0] + best[1] + w[v]);
    return best[0] + w[v];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(ii(b, c));
        neigh[b].push_back(ii(a, c));
    }
    Traverse(1, 0);
    cout << res << endl;
    return 0;
}