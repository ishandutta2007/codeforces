/**
 * @author Macesuted
 * @date 2021-02-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;

#define bufferSiz (1 << 18)
char Buff[bufferSiz], *_S = Buff, *_T = Buff;
#define getchar() (_S == _T && (_T = (_S = Buff) + fread(Buff, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

template <typename T>
T read(void) {
    char c = getchar();
    T f = 1, num = 0;
    while (c < '0' || c > '9') {
        if (c == '-') f = -f;
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

#define maxn 1005

typedef pair<int, int> pii;

vector<vector<int> > graph;
int dis[2][maxn];
bool vis[maxn];
bool v[maxn][maxn];

void BFS(int start, int t) {
    static queue<pii> que;
    memset(vis, 0, sizeof(vis));
    while (!que.empty()) que.pop();
    vis[start] = true;
    que.push((pii){start, 0});
    while (!que.empty()) {
        pii p = que.front();
        que.pop();
        dis[t][p.first] = p.second;
        for (vector<int>::iterator i = graph[p.first].begin(); i != graph[p.first].end(); i++)
            if (!vis[*i]) que.push((pii){*i, p.second + 1}), vis[*i] = true;
    }
    return;
}

int main() {
    int n = read<int>(), m = read<int>(), s = read<int>(), t = read<int>();
    graph.resize(n + 1);
    for (register int i = 1, from, to; i <= m; i++)
        from = read<int>(), to = read<int>(), graph[from].push_back(to), graph[to].push_back(from), v[from][to] = v[to][from] = true;
    BFS(s, 0), BFS(t, 1);
    memset(vis, 0, sizeof(vis));
    int cnt = 0, shortest = dis[0][t];
    for (register int i = 1; i <= n; i++)
        for (register int j = i + 1; j <= n; j++)
            if (!v[i][j] && min(dis[0][i] + dis[1][j], dis[1][i] + dis[0][j]) + 1 >= shortest) cnt++;
    printf("%d\n", cnt);
    return 0;
}