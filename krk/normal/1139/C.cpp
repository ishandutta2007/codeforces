#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod = 1000000007;
const int Maxn = 100005;

int n, k;
vector <ii> neigh[Maxn];
int cnt[Maxn];
ll spec;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Traverse(int v, int p)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p || u.second == 1) continue;
        cnt[v] += Traverse(u.first, v);
    }
    return cnt[v];
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(ii(b, c));
        neigh[b].push_back(ii(a, c));
    }
    int onlyred = 0;
    for (int i = 1; i <= n; i++) if (cnt[i] == 0) {
        int comp = Traverse(i, 0);
        onlyred = (onlyred + toPower(comp, k)) % mod;
    }
    int all = toPower(n, k);
    printf("%d\n", (all - onlyred + mod) % mod);
    return 0;
}