#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

const int Maxt = 3;
const int Maxn = 100005;

int n[Maxt];
vector <int> neigh[Maxt][Maxn];
int cnt[Maxt][Maxn];
ll sum[Maxt], toup[Maxt][Maxn];
int best[Maxt];
ll res;

void Traverse1(int v, int p, vector <int> neigh[], int cnt[], ll toup[])
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse1(u, v, neigh, cnt, toup);
        cnt[v] += cnt[u]; toup[v] += toup[u] + cnt[u];
    }
}

void Traverse2(int n, int v, int p, vector <int> neigh[], int cnt[], ll &sum, ll toup[])
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        toup[u] = toup[v] + n - cnt[u] - cnt[u];
        Traverse2(n, u, v, neigh, cnt, sum, toup);
    }
    sum += toup[v];
}

ll Traverse3(int v, int p, int d, int n1, int n3, vector <int> neigh[], ll toup[])
{
    ll best = toup[v] * n1 + ll(d) * n1 * n3;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        best = max(best, Traverse3(u, v, d + 1, n1, n3, neigh, toup));
    }
    return best;
}

void Check(int a, int b, int c)
{
    ll frombest = Traverse3(best[b], 0, 0, n[a], n[c], neigh[b], toup[b]) + ll(n[c]) * toup[b][best[b]];
    res = max(res, sum[a] + sum[b] + sum[c] + ll(n[a]) * n[b] + ll(n[a]) * n[c] * 2 + ll(n[b]) * n[c] + 
                   toup[c][best[c]] * n[a] + (toup[a][best[a]] + toup[c][best[c]]) * n[b] + toup[a][best[a]] * n[c] + frombest);
}

int main()
{
    scanf("%d %d %d", &n[0], &n[1], &n[2]);
    for (int t = 0; t < Maxt; t++) {
        for (int i = 0; i < n[t] - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[t][a].push_back(b); neigh[t][b].push_back(a);
        }
        Traverse1(1, 0, neigh[t], cnt[t], toup[t]);
        Traverse2(n[t], 1, 0, neigh[t], cnt[t], sum[t], toup[t]);
        sum[t] /= 2ll;
        best[t] = 1;
        for (int i = 2; i <= n[t]; i++)
            if (toup[t][i] > toup[t][best[t]]) best[t] = i;
    }
    Check(0, 1, 2);
    Check(0, 2, 1);
    Check(1, 0, 2);
    Check(1, 2, 0);
    Check(2, 0, 1);
    Check(2, 1, 0);
    printf("%I64d\n", res);
    return 0;
}