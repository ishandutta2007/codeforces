#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 100005;
const int Maxd = 52;

int n, m, d;
vector <int> neigh[Maxn];
char op[Maxn][Maxd];
vector <ii> S;
bool onStack[Maxn][Maxd];
int cur, tim[Maxn][Maxd], low[Maxn][Maxd];
int comp, my[Maxn][Maxd], dp[Maxn * Maxd];
set <int> St[Maxn][Maxd];
vector <iii> exec;

void SCC()
{
    while (!exec.empty()) {
        ii v = exec.back().first;
        int i = exec.back().second;
        exec.pop_back();
        if (i == -1) {
            cur++; tim[v.first][v.second] = low[v.first][v.second] = cur;
            onStack[v.first][v.second] = true; S.push_back(v);
            exec.push_back(iii(v, 0));
        } else if (i / 2 == neigh[v.first].size()) {
            if (tim[v.first][v.second] == low[v.first][v.second]) {
                comp++;
                ii u;
                do {
                    u = S.back(); S.pop_back();
                    onStack[u.first][u.second] = false;
                    my[u.first][u.second] = comp;
                    if (op[u.first][u.second] == '1') St[v.first][v.second].insert(u.first);
                    for (int i = 0; i < neigh[u.first].size(); i++) {
                        ii z = ii(neigh[u.first][i], (u.second + 1) % d);
                        if (my[z.first][z.second] && my[z.first][z.second] < comp)
                            dp[comp] = max(dp[comp], dp[my[z.first][z.second]]);
                    }
                } while (u != v);
                dp[comp] += St[v.first][v.second].size();
                St[v.first][v.second].clear();
            }
        } else if (i % 2 == 0) {
            ii u = ii(neigh[v.first][i / 2], (v.second + 1) % d);
            if (!tim[u.first][u.second]) {
                exec.push_back(iii(v, i + 1));
                exec.push_back(iii(u, -1));
            } else if (onStack[u.first][u.second]) {
                low[v.first][v.second] = min(low[v.first][v.second], tim[u.first][u.second]);
                exec.push_back(iii(v, i + 2));
            } else exec.push_back(iii(v, i + 2));
        } else {
            ii u = ii(neigh[v.first][i / 2], (v.second + 1) % d);
            low[v.first][v.second] = min(low[v.first][v.second], low[u.first][u.second]);
            exec.push_back(iii(v, i + 1));
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
        scanf("%s", op[i]);
    exec.push_back(iii(ii(1, 0), -1));
    SCC();
    printf("%d\n", dp[my[1][0]]);
    return 0;
}