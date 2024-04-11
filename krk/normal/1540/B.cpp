#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 205;
const int mod = 1000000007;

int C[Maxn][Maxn];
int pw[Maxn], ipw[Maxn];
int add[Maxn][Maxn];
int n;
vector <int> neigh[Maxn];
int res;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

vector <ii> Solve(int v, int p)
{
    vector <ii> cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        auto seq = Solve(u, v);
        int lim = cur.size();
        for (int i = 0; i < seq.size(); i++) {
            seq[i].second++;
            for (int j = 0; j < lim; j++)
                if (cur[j].first > seq[i].first) res = (res + add[cur[j].second][seq[i].second]) % mod;
                else res = (res + add[seq[i].second][cur[j].second]) % mod;
            if (v > seq[i].first) res = (res + 1) % mod;
            cur.push_back(seq[i]);
        }
    }
    cur.push_back(ii(v, 0));
    return cur;
}

int main()
{
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    pw[0] = ipw[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw[i] = 2 * pw[i - 1] % mod;
        ipw[i] = Inv(pw[i]);
    }
    for (int b = 1; b < Maxn; b++)
        for (int a = 1; a < Maxn; a++) if (a + b < Maxn)
            add[b][a] = (add[b][a - 1] + ll(C[a + b - 2][a - 1]) * ipw[a - 1 + b]) % mod;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) 
        Solve(i, 0);
    res = ll(res) * Inv(n) % mod;
    printf("%d\n", res);
    return 0;
}