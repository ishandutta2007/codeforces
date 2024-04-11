#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};
const int Maxn = 400005;

int n, m;
vector <vector <int> > B;
ii best[Maxn];
ii my[Maxn];
set <int> S;
int cur;

void clearBest(ii &res) { res.first = res.second = Maxn; }

void addBest(ii &res, int x)
{
    if (x < res.first) { res.second = res.first; res.first = x; }
    else if (x < res.second) res.second = x;
}

int getBest(const ii &res, int x) { return res.first != x? res.first: res.second; }

bool isInside(const ii &p) { return 0 <= p.first && p.first < n && 0 <= p.second && p.second < m; }

ii computeBest(int x)
{
    ii res; clearBest(res);
    for (int i = 0; i < Maxd; i++) {
        ii pos = ii(my[x].first + dy[i], my[x].second + dx[i]);
        if (isInside(pos)) addBest(res, B[pos.first][pos.second]);
    }
    return res;
}

bool Bad(int best, int me) { return me != 1 && best >= me; }

bool Neighbours(const ii &a, const ii &b) { return abs(a.first - b.first) + abs(a.second - b.second) == 1; }

bool Swap(int a, int b)
{
    if (a > b) swap(a, b);
    int sav = 0;
    for (int d = 0; d < Maxd; d++) {
        ii pos = ii(my[a].first + dy[d], my[a].second + dx[d]);
        if (!isInside(pos) || B[pos.first][pos.second] == b) continue;
        int x = B[pos.first][pos.second];
        if (Bad(best[x].first, x)) return false;
        if (Neighbours(pos, my[b])) continue;
        if (Bad(min(getBest(best[x], a), b), x)) return false;
    }
    for (int d = 0; d < Maxd; d++) {
        ii pos = ii(my[b].first + dy[d], my[b].second + dx[d]);
        if (!isInside(pos) || B[pos.first][pos.second] == a) continue;
        int x = B[pos.first][pos.second];
        if (!Bad(best[x].first, x)) continue;
        if (Bad(min(getBest(best[x], b), a), x)) return false;
        sav++;
    }
    sav += Bad(best[a].first, a) + Bad(best[b].first, b);
    swap(B[my[a].first][my[a].second], B[my[b].first][my[b].second]);
    swap(my[a], my[b]);
    ii best1 = computeBest(a);
    ii best2 = computeBest(b);
    sav -= (Bad(best1.first, a) + Bad(best2.first, b));
    swap(my[a], my[b]);
    swap(B[my[a].first][my[a].second], B[my[b].first][my[b].second]);
    return sav == cur;
}

int main()
{
    scanf("%d %d", &n, &m);
    B.resize(n);
    for (int i = 0; i < n; i++) {
        B[i].resize(m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
            my[B[i][j]] = ii(i, j);
        }
    }
    for (int i = 1; i <= n * m; i++) {
        best[i] = computeBest(i);
        if (Bad(best[i].first, i)) {
            cur++;
            S.insert(i);
            for (int d = 0; d < Maxd; d++) {
                ii pos = ii(my[i].first + dy[d], my[i].second + dx[d]);
                if (isInside(pos)) S.insert(B[pos.first][pos.second]);
            }
        }
    }
    if (S.empty()) { printf("0\n"); return 0; }
    if (S.size() > 100) { printf("2\n"); return 0; }
    int res = 0;
    for (auto it = S.begin(); it != S.end(); it++)
        for (auto it2 = S.begin(); it2 != it; it2++)
            res += Swap(*it, *it2);
    if (S.size() <= 5)
        for (int i = 1; i <= n * m; i++) if (S.find(i) == S.end())
            for (auto j: S)
                res += Swap(i, j);
    if (res) printf("1 %d\n", res);
    else printf("2\n");
    return 0;
}