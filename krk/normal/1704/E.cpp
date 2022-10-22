#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;
const int mod = 998244353;

int T;
int n, m;
ll a[Maxn];
bool tk[Maxn];
vector <int> neigh[Maxn];
vector <int> seq;
int dp[Maxn];

void Traverse(int v)
{
    if (tk[v]) return;
    tk[v] = true;
    for (int i = 0; i < neigh[v].size(); i++)
        Traverse(neigh[v][i]);
    seq.push_back(v);
}

bool Finished()
{
    for (int i = 1; i <= n; i++)
        if (a[i]) return false;
    return true;
}

void oneStep()
{
    for (int i = 0; i < seq.size(); i++) {
        int v = seq[i];
        if (a[v] > 0) {
            a[v]--;
            for (int j = 0; j < neigh[v].size(); j++)
                a[neigh[v][j]]++;
        }
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%I64d", &a[i]);
            tk[i] = false;
            neigh[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int x, y; scanf("%d %d", &x, &y);
            neigh[x].push_back(y);
        }
        seq.clear();
        for (int i = 1; i <= n; i++)
            Traverse(i);
        int res = 0;
        while (!Finished() && res < Maxn) {
            oneStep();
            res++;
        }
        dp[seq[0]] = 0;
        res = (res + a[seq[0]] % mod) % mod;
        for (int i = 1; i < seq.size(); i++) {
            int v = seq[i];
            dp[v] = int(neigh[v].size()) - 1;
            for (int j = 0; j < neigh[v].size(); j++)
                dp[v] = (dp[v] + dp[neigh[v][j]]) % mod;
            res = (res + a[v] % mod * ll(1 + dp[v])) % mod;
        }
        printf("%d\n", res);
    }
    return 0;
}