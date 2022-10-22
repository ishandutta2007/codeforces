#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int Maxm = 21;
const ll Inf = 9000000000000000000ll;

struct pos {
    int b;
    ll c, d;
};

int n;
ll sw[Maxn];
vector <pos> neigh[Maxn];
int P[Maxn][Maxm];
int L[Maxn];
ll zer[Maxn], one[Maxn];
ll dp[Maxn][Maxm][2][2];

void Traverse(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        pos p = neigh[v][i];
        if (P[v][0] == p.b) continue;
        P[p.b][0] = v; L[p.b] = L[v] + 1;
        zer[p.b] = p.c, one[p.b] = p.d;
        Traverse(p.b);
    }
}

ll getSw(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        pos p = neigh[v][i];
        if (P[v][0] == p.b) continue;
        sw[v] = min(sw[v], getSw(p.b) + p.c + p.d);
    }
    return sw[v];
}

void getSw2(int v, ll cand)
{
    sw[v] = min(sw[v], cand);
    for (int i = 0; i < neigh[v].size(); i++) {
        pos p = neigh[v][i];
        if (P[v][0] == p.b) continue;
        getSw2(p.b, sw[v] + p.c + p.d);
    }
}

vector <ll> getNext(vector <ll> my, ll dp[][2])
{
    vector <ll> nmy(2, Inf);
    for (int i = 0; i < my.size(); i++)
        for (int j = 0; j < 2; j++)
            nmy[j] = min(nmy[j], my[i] + dp[i][j]);
    return nmy;
}

ll Join(int v, const vector <ll> &A, const vector <ll> &B)
{
    return min(min(A[0] + B[0], A[1] + B[1]), sw[v] + min(A[1] + B[0], A[0] + B[1]));
}

ll Solve(int ga, int gb)
{
    int a = (ga + 1) / 2, b = (gb + 1) / 2;
    if (L[a] < L[b]) { swap(a, b); swap(ga, gb); }
    vector <ll> dpa, dpb;
    if (ga % 2) dpa = {0ll, sw[a]};
    else dpa = {sw[a], 0ll};
    if (gb % 2) dpb = {0ll, sw[b]};
    else dpb = {sw[b], 0ll};
    for (int i = Maxm - 1; i >= 0; i--) if (L[a] - (1 << i) >= L[b]) {
        dpa = getNext(dpa, dp[a][i]);
        a = P[a][i];
    }
    if (a == b) return Join(a, dpa, dpb);
    for (int i = Maxm - 1; i >= 0; i--) if (P[a][i] != P[b][i]) {
        dpa = getNext(dpa, dp[a][i]);
        dpb = getNext(dpb, dp[b][i]);
        a = P[a][i], b = P[b][i];
    }
    dpa = getNext(dpa, dp[a][0]);
    dpb = getNext(dpb, dp[b][0]);
    return Join(P[a][0], dpa, dpb);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &sw[i]);
    for (int i = 0; i < n - 1; i++) {
        int a, b; ll c, d; scanf("%d %d %I64d %I64d", &a, &b, &c, &d);
        neigh[a].push_back({b, c, d});
        neigh[b].push_back({a, c, d});
    }
    Traverse(1);
    getSw(1);
    getSw2(1, Inf);
    for (int i = 2; i <= n; i++) {
        int v = P[i][0], b = i;
        dp[b][0][0][0] = min(zer[b], sw[b] + one[b] + sw[v]);
        dp[b][0][0][1] = min(zer[b] + sw[v], sw[b] + one[b]);
        dp[b][0][1][0] = min(sw[b] + zer[b], one[b] + sw[v]);
        dp[b][0][1][1] = min(one[b], sw[b] + zer[b] + sw[v]);
    }
    for (int j = 1; j < Maxm; j++)
        for (int i = 1; i <= n; i++) {
            int nxt = P[i][j - 1];
            P[i][j] = P[nxt][j - 1];
            vector <ll> got = getNext({dp[i][j - 1][0][0], dp[i][j - 1][0][1]}, dp[nxt][j - 1]);
            dp[i][j][0][0] = got[0]; dp[i][j][0][1] = got[1];
            got = getNext({dp[i][j - 1][1][0], dp[i][j - 1][1][1]}, dp[nxt][j - 1]);
            dp[i][j][1][0] = got[0]; dp[i][j][1][1] = got[1];
        }
    int q; scanf("%d", &q);
    while (q--) {
        int a, b; scanf("%d %d", &a, &b);
        ll res = Solve(a, b);
        printf("%I64d\n", res);
    }
    return 0;
}