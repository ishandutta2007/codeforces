#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;
const int mod = 998244353;

int t;
int n, m;
vector <int> neigh[Maxn];
int col[Maxn];
ii my[Maxn];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

bool Fill(int v, int c)
{
    if (col[v]) return col[v] == c;
    my[v] = ii(1, 0);
    col[v] = c;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (col[u]) {
            if (!Fill(u, -c)) return false;
        } else {
            if (!Fill(u, -c)) return false;
            my[v].first += my[u].second;
            my[v].second += my[u].first;
        }
    }
    return true;
}

int getWays()
{
    int res = 1;
    for (int i = 1; i <= n; i++) if (col[i] == 0) {
        if (!Fill(i, 1)) return 0;
        int mult = (toPower(2, my[i].first) + toPower(2, my[i].second)) % mod;
        res = ll(res) * mult % mod;
    }
    return res;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            col[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        printf("%d\n", getWays());
    }
    return 0;
}