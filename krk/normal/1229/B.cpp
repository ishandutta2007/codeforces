#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 100005;
const int Maxk = 20;
const int mod = 1000000007;

int n;
ll x[Maxn];
vector <int> neigh[Maxn];
int P[Maxn][Maxk], L[Maxn];
ll my[Maxn][Maxk];
int res;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

void Traverse(int v, int p, int lvl)
{
    P[v][0] = p; L[v] = lvl;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v, lvl + 1);
    }
}

int getNext(int v, ll g)
{
    for (int i = Maxk - 1; i >= 0; i--) if ((1 << i) <= L[v] && (g == 0 && my[v][i] == 0 ||
                                                                 g != 0 && my[v][i] % g == 0))
        v = P[v][i];
    return v;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &x[i]);
        my[i][0] = x[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0, 1);
    for (int j = 1; j < Maxk; j++)
        for (int i = 1; i <= n; i++) {
            P[i][j] = P[P[i][j - 1]][j - 1];
            my[i][j] = gcd(my[i][j - 1], my[P[i][j - 1]][j - 1]);
        }
    for (int i = 1; i <= n; i++) {
        ll g = x[i];
        int v = i;
        while (v != 0) {
            int u = getNext(v, g);
            res = (ll(res) + ll(g) % mod * (L[v] - L[u])) % mod;
            v = u;
            g = gcd(g, x[u]);
        }
    }
    cout << res << endl;
    return 0;
}