#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int n;
vector <int> neigh[Maxn];
int cnt[Maxn];
vector <ii> seq;
vector <int> seqA, seqB;
int sumA, sumB;

void Traverse(int v, int p)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        cnt[v] += cnt[u];
    }
}

int getCentroid(int v, int p, int lim)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        if (cnt[u] > lim) return getCentroid(u, v, lim);
    }
    return v;
}

int Write(int v, int p, int fir, int delt)
{
    printf("%d %d %d\n", v, p, fir + delt);
    int cur = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        cur += Write(u, v, cur, delt);
    }
    return cur + delt;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0);
    int C = getCentroid(1, 0, cnt[1] / 2);
    for (int i = 0; i < neigh[C].size(); i++) {
        int v = neigh[C][i];
        Traverse(v, C);
        seq.push_back(ii(cnt[v], v));
    }
    sort(seq.rbegin(), seq.rend());
    for (int i = 0; i < seq.size(); i++)
        if (sumA <= sumB) {
            sumA += seq[i].first;
            seqA.push_back(seq[i].second);
        } else {
            sumB += seq[i].first;
            seqB.push_back(seq[i].second);
        }
    int cur = 0;
    for (int i = 0; i < seqA.size(); i++)
        cur += Write(seqA[i], C, cur, 1);
    cur = 0;
    for (int i = 0; i < seqB.size(); i++)
        cur += Write(seqB[i], C, cur, sumA + 1);
    return 0;
}