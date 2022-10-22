#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long double ld;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
int X[Maxn], Y[Maxn];
int sumX, sumY;
ld probX[Maxn], probY[Maxn];
int cnt[Maxn];
ld sumP[Maxn], sumE[Maxn], sumU[Maxn];
ld res;

void Traverse1(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse1(u, v);
        cnt[v] += cnt[u];
        sumP[v] += sumP[u];
        sumE[v] += sumU[u] + sumP[u];
    }
    sumU[v] = sumE[v];
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        sumU[v] += ld(cnt[v] - cnt[u]) * sumP[u];
    }
    sumP[v] += probX[v];
    sumU[v] += ld(cnt[v]) * probX[v];
    cnt[v]++;
}

void Traverse2(int v, int p, ld P, ld U)
{
    res += probY[v] * (sumE[v] + U + P);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        ld newP = P + sumP[v] - sumP[u];
        ld newU = U + P +
                  sumU[v] - sumU[u] - sumP[u] - ld(cnt[v] - 1 - cnt[u]) * sumP[u] +
                  (sumP[v] - sumP[u]) * ld(n - cnt[v] - cnt[u]) +
                  P * ld(cnt[v] - 1 - cnt[u]);
        Traverse2(u, v, newP, newU);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; scanf("%d %d", &x, &y);
        neigh[x].push_back(y);
        neigh[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        sumX += X[i]; sumY += Y[i];
    }
    for (int i = 1; i <= n; i++) {
        probX[i] = ld(X[i]) / sumX;
        probY[i] = ld(Y[i]) / sumY;
    }
    Traverse1(1, 0);
    Traverse2(1, 0, 0, 0);
    cout << fixed << setprecision(15) << res << endl;
    return 0;
}