#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, m, k;
vector <ii> neigh[Maxn];
int dist[Maxn];
queue <int> Q;
vector <int> my[Maxn];
vector <int> seq;
vector <vector <int> > res;
char str[Maxn];

void Gen(int v)
{
    if (v > n) res.push_back(seq);
    else {
        seq.push_back(0);
        for (int i = 0; i < my[v].size() && res.size() < k; i++) {
            seq.back() = my[v][i];
            Gen(v + 1);
        }
        seq.pop_back();
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(ii(b, i));
        neigh[b].push_back(ii(a, i));
    }
    fill(dist, dist + Maxn, Maxn); dist[1] = 0;
    Q.push(1);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i].first;
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                Q.push(u);
            }
        }
    }
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < neigh[i].size(); j++) {
            ii u = neigh[i][j];
            if (dist[u.first] + 1 == dist[i])
                my[i].push_back(u.second);
        }
    Gen(2);
    printf("%d\n", int(res.size()));
    str[m] = '\0';
    for (int i = 0; i < res.size(); i++) {
        fill(str, str + m, '0');
        for (int j = 0; j < res[i].size(); j++)
            str[res[i][j]] = '1';
        printf("%s\n", str);
    }
    return 0;
}