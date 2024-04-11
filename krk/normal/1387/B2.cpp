#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
int cnt[Maxn];
int root, lvl[Maxn];
int pop[Maxn];
vector <ii> seq;
ll totres;
int res[Maxn];

void Count(int v, int p = 0)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Count(u, v);
        cnt[v] += cnt[u];
    }
}

int findCentroid(int v, int p, int lim)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        if (cnt[u] > lim) return findCentroid(u, v, lim);
    }
    return v;
}

void Traverse(int v, int p, int col, int L)
{
    lvl[v] = L;
    seq.push_back(ii(v, col));
    pop[col]++;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v, col, L + 1);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Count(1);
    root = findCentroid(1, 0, n / 2);
    seq.push_back(ii(root, 0));
    pop[0]++;
    for (int i = 0; i < neigh[root].size(); i++) {
        int v = neigh[root][i];
        Traverse(v, root, i + 1, 1);
    }
    int mx = 0;
    for (int i = 1; i <= n; i++)
        if (pop[i] > pop[mx]) mx = i;
    int st = 0;
    while (seq[st].second != mx) st++;
    int pnt = (st + 1);
    for (int j = 0; j < n; j++) {
        int i = (st + j) % n;
        while (seq[i].second == seq[pnt].second)
            pnt = (pnt + 1) % n;
        res[seq[i].first] = seq[pnt].first;
        totres += lvl[seq[i].first] + lvl[seq[pnt].first];
        pnt = (pnt + 1) % n;
    }
    cout << totres << endl;
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}