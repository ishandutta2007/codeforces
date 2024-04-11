#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, int> lli;

const int Maxn = 25;
const int Maxm = 500;
const int MaxN = 4 * Maxm;
const int sInf = 1000000000;
const ll Inf = 1000000000000000000ll;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m, males, females;
char B[Maxn][Maxn];
int Mr[Maxm], Mc[Maxm], Mt[Maxm], Mcnt;
int Fr[Maxm], Fc[Maxm], Ft[Maxm], Fcnt;
int D[Maxn][Maxn][Maxn][Maxn];
int N;
vector <int> neigh[MaxN];
ll C[MaxN][MaxN];
int R[MaxN][MaxN];
ll dist[MaxN];
int par[MaxN];

void calcDist(int R, int C)
{
    fill((int*)D[R][C], (int*)D[R][C] + Maxn * Maxn, sInf); D[R][C][R][C] = 0;
    queue <ii> Q; Q.push(ii(R, C));
    while (!Q.empty()) {
        ii v = Q.front(); Q.pop();
        int d = D[R][C][v.first][v.second];
        for (int i = 0; i < Maxd; i++) {
            ii u = ii(v.first + dy[i], v.second + dx[i]);
            if (0 <= u.first && u.first < n && 0 <= u.second && u.second < m && 
                B[u.first][u.second] == '.' && d + 1 < D[R][C][u.first][u.second]) {
                D[R][C][u.first][u.second] = d + 1; Q.push(u);
            }
        }
    }
}

int getMiddle1(int r, int c)
{
    return 1 + Mcnt + r * m + c;
}

int getMiddle2(int r, int c)
{
    return 1 + Mcnt + n * m + r * m + c;
}

int getLast(int ind)
{
    return Mcnt + 2 * n * m + ind;
}

void addEdge(int a, int b, ll w = 0)
{
    C[a][b] = C[b][a] = w;
    R[a][b] = 1;
    neigh[a].push_back(b); neigh[b].push_back(a);
}

int getFlow(ll &res)
{
    fill(dist, dist + N, Inf); dist[0] = 0;
    priority_queue <lli> Q; Q.push(lli(-dist[0], 0));
    while (!Q.empty()) {
        int v = Q.top().second; ll d = -Q.top().first; Q.pop();
        if (v == N - 1) break;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (R[v][u] && max(d, C[v][u]) < dist[u]) {
                dist[u] = max(d, C[v][u]); par[u] = v;
                Q.push(lli(-dist[u], u));
            }
        }
    }
    int v = N - 1;
    if (dist[v] == Inf) return 0;
    res = dist[v];
    while (v) {
        int u = par[v];
        R[u][v]--; R[v][u]++;
        v = u;
    }
    return 1;
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &males, &females);
    for (int i = 0; i < n; i++)
        scanf("%s", B[i]);
    if (males - females == 1) { scanf("%d %d %d", &Fr[0], &Fc[0], &Ft[0]); Fr[0]--; Fc[0]--; Fcnt++; }
    else if (females - males == 1) { scanf("%d %d %d", &Mr[0], &Mc[0], &Mt[0]); Mr[0]--; Mc[0]--; Mcnt++; }
    else { printf("-1\n"); return 0; }
    while (males--) {
        scanf("%d %d %d", &Mr[Mcnt], &Mc[Mcnt], &Mt[Mcnt]); Mr[Mcnt]--; Mc[Mcnt]--; Mcnt++;
    }
    while (females--) {
        scanf("%d %d %d", &Fr[Fcnt], &Fc[Fcnt], &Ft[Fcnt]); Fr[Fcnt]--; Fc[Fcnt]--; Fcnt++;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (B[i][j] == '.') calcDist(i, j);

    N = 1 + Mcnt + 2 * n * m + Fcnt + 1;
    for (int i = 1; i <= Mcnt; i++) {
        addEdge(0, i);
        for (int j = 0; j < n; j++)
            for (int l = 0; l < m; l++) {
                int d = D[Mr[i - 1]][Mc[i - 1]][j][l];
                if (d < sInf) {
                    ll w = ll(Mt[i - 1]) * d;
                    addEdge(i, getMiddle1(j, l), w);
                }
            }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            addEdge(getMiddle1(i, j), getMiddle2(i, j));
    for (int i = 1; i <= Fcnt; i++) {
        addEdge(getLast(i), N - 1);
        for (int j = 0; j < n; j++)
            for (int l = 0; l < m; l++) {
                int d = D[Fr[i - 1]][Fc[i - 1]][j][l];
                if (d < sInf) {
                    ll w = ll(Ft[i - 1]) * d;
                    addEdge(getMiddle2(j, l), getLast(i), w);
                }
            }
    }

    int mf = 0, f;
    ll c;
    while ((f = getFlow(c)) != 0) mf += f;
    if (mf != Mcnt) printf("-1\n");
    else printf("%I64d\n", c);
    return 0;
}