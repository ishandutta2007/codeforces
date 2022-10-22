#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Inf = 1000000000;

const string lets = "URDL";
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, 1, 0, -1};

char tmp[Maxn];
int T;
int n, m;
int N;
vector <string> B;
vector <string> dirs;
int to[Maxn];
vector <ii> neigh[Maxn];
int seq[Maxn];
set <int> all, black;

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

int Id(int r, int c) { return r * m + c; }

void Traverse(int v, int col, int len)
{
    if (seq[v] != Inf) return;
    seq[v] = col;
    all.insert(col);
    int r = v / m, c = v % m;
    if (B[r][c] == '0') black.insert(col);
    for (int i = 0; i < neigh[v].size(); i++) {
        int ncol = col + neigh[v][i].second;
        if (ncol < 0) ncol += len;
        if (ncol >= len) ncol -= len;
        Traverse(neigh[v][i].first, ncol, len);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        B.resize(n);
        for (int i = 0; i < n; i++)
            Read(B[i]);
        dirs.resize(n);
        for (int i = 0; i < n; i++)
            Read(dirs[i]);
        N = n * m;
        for (int i = 0; i < N; i++) {
            neigh[i].clear();
            seq[i] = Inf;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int v = Id(i, j);
                int ind = lets.find(dirs[i][j]);
                int u = Id(i + dy[ind], j + dx[ind]);
                to[v] = u;
                neigh[v].push_back(ii(u, 1));
                neigh[u].push_back(ii(v, -1));
            }
        int res1 = 0, res2 = 0;
        for (int i = 0; i < N; i++) if (seq[i] == Inf) {
            int len = 0;
            int cur = i, col = 0;
            vector <int> tmp;
            while (seq[cur] == Inf) {
                tmp.push_back(cur);
                seq[cur] = col++;
                cur = to[cur];
            }
            len = col - seq[cur];
            for (int i = 0; i < tmp.size(); i++)
                seq[tmp[i]] = Inf;
            all.clear();
            black.clear();
            Traverse(i, 0, len);
            res1 += all.size();
            res2 += black.size();
        }
        printf("%d %d\n", res1, res2);
    }
    return 0;
}