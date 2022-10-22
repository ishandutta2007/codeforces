#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 205;
const int Inf = 1000000000;

int n;
int a[Maxn];
int id[Maxn];
int eno, ono;
int N;
int R[Maxn][Maxn];
vector <int> neigh[Maxn];
int flow[Maxn], par[Maxn];
int rind[Maxn];
vector <int> neigh2[Maxn];
int tk[Maxn];
vector <int> seq;
vector <vector <int> > res;

bool Prime(int val)
{
    if (val <= 1) return false;
    if (val == 2) return true;
    if (val % 2 == 0) return false;
    for (int i = 3; i * i <= val; i += 2)
        if (val % i == 0) return false;
    return true;
}

int getFlow()
{
    fill(flow, flow + N, 0); flow[0] = Inf;
    priority_queue <ii> Q; Q.push(ii(Inf, 0));
    while (!Q.empty()) {
        int f = Q.top().first, v = Q.top().second; Q.pop();
        if (flow[v] != f) continue;
        if (v == N - 1) break;
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

void Fill(int v)
{
    if (tk[v]) return;
    tk[v] = true; seq.push_back(v);
    for (int i = 0; i < neigh2[v].size(); i++)
        Fill(neigh2[v][i]);
}

int main()
{
    scanf("%d", &n); eno = n / 2;
    if (n % 2) { printf("Impossible\n"); return 0; }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2) id[i] = ++ono;
        else id[i] = ++eno;
    }
    if (ono != n / 2) { printf("Impossible\n"); return 0; }
    N = n + 2;
    for (int i = 0; i < n; i++)
        if (a[i] % 2) {
            R[0][id[i]] = 2; neigh[0].push_back(id[i]); neigh[id[i]].push_back(0);
            for (int j = 0; j < n; j++)
                if (a[j] % 2 == 0 && Prime(a[i] + a[j])) {
                    R[id[i]][id[j]] = 1; neigh[id[i]].push_back(id[j]); neigh[id[j]].push_back(id[i]);
                }
        } else {
            R[id[i]][N - 1] = 2; neigh[id[i]].push_back(N - 1); neigh[N - 1].push_back(id[i]);
        }
    int mf = 0;
    int f;
    while ((f = getFlow()) != 0) mf += f;
    if (mf != n) { printf("Impossible\n"); return 0; }
    for (int i = 0; i < n; i++)
        rind[id[i]] = i;
    for (int i = 1; i <= n / 2; i++)
        for (int j = n / 2; j <= n; j++)
            if (R[j][i] > 0) {
                neigh2[rind[j]].push_back(rind[i]); neigh2[rind[i]].push_back(rind[j]);
            }
    for (int i = 0; i < n; i++) if (!tk[i]) {
        seq.clear();
        Fill(i);
        res.push_back(seq);
    }
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++) {
        printf("%d", res[i].size());
        for (int j = 0; j < res[i].size(); j++)
            printf(" %d", res[i][j] + 1);
        printf("\n");
    }
    return 0;
}