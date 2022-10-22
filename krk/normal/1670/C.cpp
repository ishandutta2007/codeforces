#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int mod = 1000000007;

int T;
int n;
int a[Maxn];
int b[Maxn];
vector <int> neigh[Maxn];
bool tk[Maxn];

void Fill(int v)
{
    if (tk[v]) return;
    tk[v] = true;
    for (int i = 0; i < neigh[v].size(); i++)
        Fill(neigh[v][i]);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            tk[i] = false;
            neigh[i].clear();
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            neigh[a[i]].push_back(b[i]);
            neigh[b[i]].push_back(a[i]);
        }
        for (int i = 1; i <= n; i++) {
            int c; scanf("%d", &c);
            if (c || a[i] == b[i]) Fill(a[i]);
        }
        int res = 1;
        for (int i = 1; i <= n; i++) if (!tk[i]) {
            res = 2 * res % mod;
            Fill(i);
        }
        printf("%d\n", res);
    }
    return 0;
}