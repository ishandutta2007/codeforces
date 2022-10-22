#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll Inf = 9000000000000000000ll;

int n;
int T[Maxn];
int H[Maxn];
vector <int> neigh[Maxn];
ll dp[Maxn][3];
ll res;

void Traverse(int v, int p)
{
    fill(dp[v], dp[v] + 3, Inf);
    ll cur = 0;
    int in = 0, de = 0;
    vector <ll> seq;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        if (H[u] < H[v]) { in++; cur += dp[u][0]; }
        else if (H[u] > H[v]) { de++; cur += dp[u][1]; }
        else {
            in++;
            cur += dp[u][0];
            seq.push_back(dp[u][1] - dp[u][0]);
        }
    }
    sort(seq.begin(), seq.end());
    for (int i = 0; i <= seq.size(); i++) {
        int mn = min(in, de);
        ll cand = cur + ll(max(in, de)) * T[v];
        dp[v][2] = min(dp[v][2], cand);
        dp[v][0] = min(dp[v][0], cand + ll(in == mn? T[v]: 0));
        dp[v][1] = min(dp[v][1], cand + ll(de == mn? T[v]: 0));
        if (i < seq.size()) {
            in--; de++;
            cur += seq[i];
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &T[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &H[i]);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0);
    printf("%I64d\n", dp[1][2]);
    return 0;
}