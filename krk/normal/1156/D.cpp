#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;

int n;
vector <ii> neigh[Maxn];
ll res;
ll dp01[Maxn], dp10[Maxn], dp1[Maxn], dp0[Maxn];

void Traverse(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p) continue;
        Traverse(u.first, v);
        if (u.second == 0) {
            ll my01 = dp01[u.first] + dp1[u.first];
            ll my0 = dp0[u.first] + 1;
            res += my01 + 2 * my0;
            res += my0 * dp01[v] + my0 * dp1[v] + my0 * dp0[v] * 2;
            res += my01 * dp0[v];
            dp01[v] += my01;
            dp0[v] += my0;
        } else if (u.second == 1) {
            ll my10 = dp10[u.first] + dp0[u.first];
            ll my1 = dp1[u.first] + 1;
            res += my10 + 2 * my1;
            res += my1 * dp10[v] + my1 * dp1[v] * 2 + my1 * dp0[v];
            res += my10 * dp1[v];
            dp10[v] += my10;
            dp1[v] += my1;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(ii(b, c));
        neigh[b].push_back(ii(a, c));
    }
    Traverse(1, 0);
    cout << res << endl;
    return 0;
}