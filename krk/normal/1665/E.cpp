#include <bits/stdc++.h>
using namespace std;

const int Maxb = 30;
const int Maxn = 100005;

struct node {
    int ch[2];
    int lst[2];
    node() {
        ch[0] = ch[1] = 0;
        lst[0] = lst[1] = 0;
    }
    void Add(int ind) {
        lst[0] = lst[1];
        lst[1] = ind;
    }
};

int T;
int n;
int a[Maxn];
int q;
int ql[Maxn], qr[Maxn];
int res[Maxn];
vector <int> quer[Maxn];
vector <node> V;
int seq[Maxn];
int slen;
int mn;

void addNode() { V.push_back(node()); }

int getLst() { return int(V.size()) - 1; }

void Clear()
{
    slen = 0;
    mn = 1 << Maxb;
}

void solveLst()
{
    for (int i = 0; i + 1 < slen; i++)
        mn = min(mn, (a[seq[i]] | a[seq[slen - 1]]));
}

void Add(int tr, int mask, int lvl, int sav)
{
    V[tr].Add(sav);
    if (lvl < 0) return;
    int ind = bool(mask & 1 << lvl);
    if (!V[tr].ch[ind]) {
        addNode();
        V[tr].ch[ind] = getLst();
    }
    Add(V[tr].ch[ind], mask, lvl - 1, sav);
}

int Get(int tr, int lvl, int lf)
{
    if (lvl < 0) {
        if (V[tr].lst[0] >= lf) {
            seq[slen++] = V[tr].lst[1];
            solveLst();
        }
        if (V[tr].lst[1] >= lf) {
            seq[slen++] = V[tr].lst[1];
            solveLst();
        }
        return mn;
    }
    int wh = V[tr].ch[0];
    if (!wh || V[wh].lst[1] < lf)
        if (V[tr].ch[1]) return Get(V[tr].ch[1], lvl - 1, lf);
        else return mn;
    if (V[wh].lst[0] < lf) {
        seq[slen++] = V[wh].lst[1];
        solveLst();
        if (V[tr].ch[1]) return Get(V[tr].ch[1], lvl - 1, lf);
        else return mn;
    }
    return Get(wh, lvl - 1, lf);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            quer[i].clear();
        }
        V.clear(); addNode();
        scanf("%d", &q);
        for (int i = 1; i <= q; i++) {
            scanf("%d %d", &ql[i], &qr[i]);
            quer[qr[i]].push_back(i);
        }
        addNode();
        int root = getLst();
        for (int i = 1; i <= n; i++) {
            Add(root, a[i], Maxb - 1, i);
            for (int j = 0; j < quer[i].size(); j++) {
                int ind = quer[i][j];
                Clear();
                res[ind] = Get(root, Maxb - 1, ql[ind]);
            }
        }
        for (int i = 1; i <= q; i++)
            printf("%d\n", res[i]);
    }
    return 0;
}