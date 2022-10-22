#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 50;
const int Maxl = 26;
const int Maxd = 4;
const int dy[Maxd] = {1, 0, -1, 0};
const int dx[Maxd] = {0, 1, 0, -1};

int n, m, k;
char B[Maxn][Maxn];
int sx, sy, ex, ey;
int has[Maxl];
int dist[Maxn][Maxn];
ii p[Maxn][Maxn];
string s, res;
bool sol;

void BFS()
{
    fill((int*)dist, (int*)dist + Maxn * Maxn, Inf);
    ii v = make_pair(ex, ey); dist[v.first][v.second] = 0;
    vector <ii> seq, buck[Maxl];
    seq.push_back(v);
    for (int i = 0; !seq.empty(); i++) {
        for (int j = 0; j < seq.size(); j++) {
            v = seq[j];
            for (int d = 0; d < Maxd; d++) {
                int ni = v.first + dy[d], nj = v.second + dx[d];
                if (0 <= ni && ni < n && 0 <= nj && nj < m &&
                    i + 1 < dist[ni][nj] && (B[ni][nj] == 'S' || has[B[ni][nj] - 'a'])) {
                        dist[ni][nj] = i + 1;
                        p[ni][nj] = make_pair(v.first, v.second);
                        if (B[ni][nj] == 'S') return;
                        else buck[B[ni][nj] - 'a'].push_back(make_pair(ni, nj));
                    }
            }
        }
        seq.clear();
        for (int j = 0; j < Maxl; j++) {
            for (int l = 0; l < buck[j].size(); l++) seq.push_back(buck[j][l]);
            buck[j].clear();
        }
    }
}

void getPath(string &s)
{
    s = "";
    ii v = p[sx][sy];
    while (v.first != ex || v.second != ey) {
        s += B[v.first][v.second];
        v = p[v.first][v.second];
    }
}

void Search(int v, int from)
{
    if (v == k) {
        BFS();
        if (dist[sx][sy] == Inf) return;
        getPath(s);
        if (!sol || s.length() < res.length() || s.length() == res.length() && s < res) res = s;
        sol = true;
    } else for (int i = from; i < Maxl; i++) {
                has[i] = true;
                Search(v + 1, i + 1);
                has[i] = false;
           }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf(" %c", &B[i][j]);
            if (B[i][j] == 'S') { sx = i; sy = j; }
            else if (B[i][j] == 'T') { ex = i; ey = j; B[i][j] = 'a'; }
        }
    Search(0, 0);
    if (!sol) printf("-1\n");
    else printf("%s\n", res.c_str());
    return 0;
}