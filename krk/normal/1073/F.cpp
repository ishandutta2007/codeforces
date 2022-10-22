#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Inf = 1000000000;

struct pos {
    int com, tot;
    int v1, v2;
    pos(int com = -Inf, int tot = -Inf, int v1 = 0, int v2 = 0): com(com), tot(tot), v1(v1), v2(v2) {}
    bool operator==(const pos &oth) const {
        return com == oth.com && tot == oth.tot && v1 == oth.v1 && v2 == oth.v2;
    }
};

pos max(const pos &a, const pos &b)
{
    if (a.com != b.com) return a.com > b.com? a: b;
    if (a.tot != b.tot) return a.tot > b.tot? a: b;
    return a;
}

struct pos2 {
    int com, tot;
    int v1, v2, v3, v4;
    pos2(int com = -Inf, int tot = -Inf, int v1 = 0, int v2 = 0, int v3 = 0, int v4 = 0): com(com), tot(tot), v1(v1), v2(v2), v3(v3), v4(v4) {}
};

pos2 max(const pos2 &a, const pos2 &b)
{
    if (a.com != b.com) return a.com > b.com? a: b;
    if (a.tot != b.tot) return a.tot > b.tot? a: b;
    return a;
}

int n;
vector <int> neigh[Maxn];
ii best[Maxn][3];
pos bestpos[Maxn][2];
pos my[Maxn];
pos2 res;

void updateBest(ii best[], const ii &val)
{
    if (val > best[0]) best[2] = best[1], best[1] = best[0], best[0] = val;
    else if (val > best[1]) best[2] = best[1], best[1] = val;
    else if (val > best[2]) best[2] = val;
}

void updateBestPos(pos best[], const pos &val)
{
    if (max(best[0], val) == val) best[1] = best[0], best[0] = val;
    else if (max(best[1], val) == val) best[1] = val;
}

pos getOth(pos best[], const pos &val)
{
    if (best[0] == val) return best[1];
    return best[0];
}

ii getOth(ii best[], const ii &val)
{
    if (best[0] == val) return best[1];
    return best[0];
}

ii incPath(const ii &val) { return ii(val.first + 1, val.second); }

pos incPos(const pos &val) { return pos(val.com + 1, val.tot + 2, val.v1, val.v2); }

pos Add(const ii &a, const ii &b) 
{
    if (a.first == 0 || b.first == 0) return pos();
    return pos{0, a.first + b.first, a.second, b.second};
}

pos2 Add(const pos &a, const pos &b) { return pos2(a.com + b.com, a.tot + b.tot, a.v1, a.v2, b.v1, b.v2); }

pos sumOth(ii best[], const ii &val)
{
    if (best[0] == val) return Add(best[1], best[2]);
    else if (best[1] == val) return Add(best[0], best[2]);
    return Add(best[0], best[1]);
}

void Traverse1(int v, int p)
{
    best[v][0] = best[v][1] = best[v][2] = ii(-Inf, 0);
    updateBest(best[v], ii(0, v));
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse1(u, v);
        updateBest(best[v], incPath(best[u][0]));
        updateBestPos(bestpos[v], incPos(my[u]));
    }
    my[v] = max(bestpos[v][0], Add(best[v][0], best[v][1]));
    res = max(res, Add(bestpos[v][0], bestpos[v][1]));
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        res = max(res, Add(incPos(my[u]), sumOth(best[v], incPath(best[u][0]))));
    }
}

void Traverse2(int v, int p, ii tp, const pos &tppos)
{
    res = max(res, Add(bestpos[v][0], tppos));
    tp = max(tp, ii(0, v));
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        ii fromu = incPath(best[u][0]);
        res = max(res, Add(getOth(bestpos[v], incPos(my[u])), Add(tp, fromu)));
        ii oth = getOth(best[v], fromu);
        Traverse2(u, v, incPath(max(tp, oth)), incPos(max(tppos, max(Add(tp, oth), sumOth(best[v], fromu)))));
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; scanf("%d %d", &u, &v);
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }
    Traverse1(1, 0);
    Traverse2(1, 0, ii(-Inf, 0), pos());
    cout << res.v1 << " " << res.v3 << endl;
    cout << res.v2 << " " << res.v4 << endl;
    return 0;
}