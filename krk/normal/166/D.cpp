#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000LL;
const int Maxm = 100005;

struct pos {
    int x, y, z;
    pos(int x = 0, int y = 0, int z = 0): x(x), y(y), z(z) {}
};

int n;
map <int, pair <int, int> > S;
int m, d[Maxm], l[Maxm];
int C[Maxm];
ll best[Maxm][2][2];
pos par[Maxm][2][2];
int wth[Maxm][2][2];
vector <int> res1, res2;

bool Less(const int &a, const int &b)
{
    return l[a] > l[b];
}

pos getNext(const pos &p)
{
    pos v; v.x = p.x + 1;
    if (v.x < m && l[C[p.x]] == l[C[v.x]]) { v.y = p.y; v.z = p.z; }
    else if (v.x < m && l[C[p.x]] - 1 == l[C[v.x]]) { v.y = p.z; v.z = 0; }
    else { v.y = v.z = 0; }
    return v;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int c, s; scanf("%d %d", &c, &s);
        S[s] = make_pair(c, i);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) { scanf("%d %d", &d[i], &l[i]); C[i] = i; }
    sort(C, C + m, Less);
    fill((ll*)best, (ll*)best + Maxm * 2 * 2, -Inf); best[0][0][0] = 0ll;
    pos p;
    for (p.x = 0; p.x < m; p.x++)
        for (p.y = 0; p.y < 2; p.y++)
            for (p.z = 0; p.z < 2; p.z++) {
                ll cand = best[p.x][p.y][p.z];
                pos v = getNext(p);
                if (cand > best[v.x][v.y][v.z]) {
                    best[v.x][v.y][v.z] = cand;
                    par[v.x][v.y][v.z] = p;
                    wth[v.x][v.y][v.z] = 0;
                }
                if (!p.y && S.find(l[C[p.x]] + 1) != S.end() && d[C[p.x]] >= S[l[C[p.x]] + 1].first) {
                    cand = best[p.x][p.y][p.z] + S[l[C[p.x]] + 1].first;
                    v = getNext(pos(p.x, 1, p.z));
                    if (cand > best[v.x][v.y][v.z]) {
                        best[v.x][v.y][v.z] = cand;
                        par[v.x][v.y][v.z] = p;
                        wth[v.x][v.y][v.z] = 1;
                    }
                }
                if (!p.z && S.find(l[C[p.x]]) != S.end() && d[C[p.x]] >= S[l[C[p.x]]].first) {
                    cand = best[p.x][p.y][p.z] + S[l[C[p.x]]].first;
                    v = getNext(pos(p.x, p.y, 1));
                    if (cand > best[v.x][v.y][v.z]) {
                        best[v.x][v.y][v.z] = cand;
                        par[v.x][v.y][v.z] = p;
                        wth[v.x][v.y][v.z] = 2;
                    }
                }
            }
    pos v = pos(m, 0, 0);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) if (best[m][i][j] > best[v.x][v.y][v.z]) v = pos(m, i, j);
    printf("%I64d\n", best[v.x][v.y][v.z]);
    while (v.x) {
        pos p = par[v.x][v.y][v.z];
        switch (wth[v.x][v.y][v.z]) {
            case 1: res1.push_back(C[p.x] + 1); res2.push_back(S[l[C[p.x]] + 1].second + 1); break;
            case 2: res1.push_back(C[p.x] + 1); res2.push_back(S[l[C[p.x]]].second + 1); break;
        }
        v = p;
    }
    printf("%d\n", res1.size());
    for (int i = 0; i < res1.size(); i++) printf("%d %d\n", res1[i], res2[i]);
    return 0;
}