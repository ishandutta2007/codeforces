#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, m;
vector <ii> my[Maxn];
int N;
vector <int> got[Maxn];
vector <int> neigh[Maxn];
int col[Maxn];
int cnt[Maxn];
bool er[Maxn];

void Count(int v, int p)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (er[u] || u == p) continue;
        Count(u, v);
        cnt[v] += cnt[u];
    }
}

int getCentroid(int v, int p, int lim)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (er[u] || u == p) continue;
        if (cnt[u] > lim) return getCentroid(u, v, lim);
    }
    return v;
}

void Solve(int v, int cl)
{
    Count(v, 0);
    int C = getCentroid(v, 0, cnt[v] / 2);
    col[C] = cl;
    er[C] = true;
    for (int i = 0; i < neigh[C].size(); i++) {
        int u = neigh[C][i];
        if (er[u]) continue;
        Solve(u, cl + 1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        my[b].push_back(ii(a, i));
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) my[i].push_back(ii(i - 1, 0));
        if (i == n) my[i].push_back(ii(1, 0));
        sort(my[i].begin(), my[i].end());
    }
    for (int i = n; i >= 1; i--)
        for (int j = int(my[i].size()) - 1; j > 0; j--) {
            N++;
            got[my[i][j - 1].second].push_back(N);
            got[my[i][j].second].push_back(N);
            int a = my[i][j - 1].first, b = my[i][j].first;
            while (a < b) {
                got[my[b][0].second].push_back(N);
                b = my[b][0].first;
            }
        }
    for (int i = 1; i <= m; i++) {
        neigh[got[i][0]].push_back(got[i][1]);
        neigh[got[i][1]].push_back(got[i][0]);
    }
    Solve(1, 1);
    for (int i = N; i >= 1; i--)
        printf("%d%c", col[i], i - 1 >= 1? ' ': '\n');
    return 0;
}