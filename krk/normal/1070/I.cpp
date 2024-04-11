#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1205;

int t;
int n, m, k;
vector <int> my[Maxn];
int R[Maxn][Maxn];
vector <int> neigh[Maxn];
int A[Maxn], B[Maxn], col[Maxn];
int par[Maxn], flow[Maxn];
int N;

void addEdge(int a, int b, int cap1, int cap2)
{
    neigh[a].push_back(b);
    neigh[b].push_back(a);
    R[a][b] = cap1; R[b][a] = cap2;
}

void printNone()
{
    for (int i = 1; i <= m; i++)
        printf("0%c", i + 1 <= m? ' ': '\n');
}

int getFlow()
{
    fill(flow, flow + N, 0); flow[0] = Maxn;
    priority_queue <ii> Q; Q.push(ii(flow[0], 0));
    while (!Q.empty()) {
        int v = Q.top().second, f = Q.top().first; Q.pop();
        if (flow[v] != f) continue;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (min(f, R[v][u]) > flow[u]) {
                flow[u] = min(f, R[v][u]); par[u] = v;
                Q.push(ii(flow[u], u));
            }
        }
    }
    int v = N - 1;
    int res = flow[v];
    if (!res) return 0;
    while (v) {
        int u = par[v];
        R[u][v] -= res; R[v][u] += res;
        v = u;
    }
    return res;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
            my[i].clear();
        N = n + m + 2;
        for (int i = 0; i < N; i++) {
            neigh[i].clear();
            for (int j = 0; j < N; j++)
                R[i][j] = 0;
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &A[i], &B[i]);
            my[A[i]].push_back(i);
            my[B[i]].push_back(i);
            col[i] = 0;
            addEdge(A[i], n + i, 1, 0);
            addEdge(B[i], n + i, 1, 0);
            addEdge(n + i, N - 1, 1, 0);
        }
        bool ok = true;
        int need = 0;
        for (int i = 1; i <= n && ok; i++)
            if (my[i].size() <= k) ;
            else if (my[i].size() <= 2 * k) {
                addEdge(0, i, 2 * (int(my[i].size()) - k), 0);
                need += 2 * (int(my[i].size()) - k);
            } else ok = false;
        if (!ok) { printNone(); continue; }
        int f = 0;
        while ((f = getFlow()) != 0)
            need -= f;
        if (need > 0) { printNone(); continue; }
        int cur = 1;
        for (int i = 1; i <= n; i++) {
            if (my[i].size() > k) {
                int forme = 2 * (int(my[i].size()) - k);
                int lft = 2;
                for (int j = 1; j <= m; j++)
                    if (R[n + j][i] > 0) {
                        lft--;
                        if (lft < 0) { cur++; lft = 1; }
                        col[j] = cur;
                    }
            }
            cur++;
        }
        for (int i = 1; i <= m; i++) {
            if (!col[i]) col[i] = cur++;
            printf("%d%c", col[i], i + 1 <= m? ' ': '\n');
        }
    }
    return 0;
}