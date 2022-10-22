#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 1005;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m;
ll k;
int B[Maxn][Maxn];
vector <iii> seq;
ii par[Maxn][Maxn];
int siz[Maxn][Maxn];
int tk[Maxn][Maxn];

bool Valid(int r, int c) { return 0 <= r && r < n && 0 <= c && c < m; }

ii getPar(ii x) { return par[x.first][x.second] == x? x:
                         par[x.first][x.second] = getPar(par[x.first][x.second]); }

void unionSet(ii a, ii b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a.first][a.second] >= siz[b.first][b.second]) {
        siz[a.first][a.second] += siz[b.first][b.second];
        par[b.first][b.second] = a;
    } else {
        siz[b.first][b.second] += siz[a.first][a.second];
        par[a.first][a.second] = b;
    }
}

void Fill(ii root, int r, int c, int &need)
{
    if (!Valid(r, c) || getPar(ii(r, c)) != root || tk[r][c] > 0) return;
    tk[r][c] = 1;
    if (need > 0) { tk[r][c] = 2; need--; }
    for (int i = 0; i < Maxd; i++)
        Fill(root, r + dy[i], c + dx[i], need);
}

void Solve(ii pos, int need)
{
    Fill(getPar(pos), pos.first, pos.second, need);
    printf("YES\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("%d%c", (tk[i][j] == 2? B[pos.first][pos.second]: 0), (j + 1 < m? ' ': '\n'));
}

int main()
{
    scanf("%d %d %I64d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
            seq.push_back(iii(B[i][j], ii(i, j)));
            par[i][j] = ii(i, j); siz[i][j] = 1;
        }
    sort(seq.begin(), seq.end());
    for (int i = seq.size() - 1, j; i >= 0; i = j) {
        j = i;
        while (j >= 0 && seq[i].first == seq[j].first) {
            for (int d = 0; d < Maxd; d++) {
                ii u = ii(seq[j].second.first + dy[d], seq[j].second.second + dx[d]);
                if (Valid(u.first, u.second) && B[u.first][u.second] >= seq[i].first)
                    unionSet(seq[j].second, u);
            }
            j--;
        }
        j = i;
        while (j >= 0 && seq[i].first == seq[j].first) {
            ii par = getPar(seq[j].second);
            if (k % seq[i].first == 0 && siz[par.first][par.second] >= k / seq[i].first) {
                Solve(seq[j].second, k / seq[i].first);
                return 0;
            }
            j--;
        }
    }
    printf("NO\n");
	return 0;
}