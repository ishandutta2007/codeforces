#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxb = 30;
const int Maxn = 500005;

map <int, int> ID;
ii par[Maxb][Maxn];
int siz[Maxb][Maxn];
int q;

int getId(int v)
{
    map <int, int>::iterator it = ID.find(v);
    if (it == ID.end()) {
        int cur = ID.size();
        for (int i = 0; i < Maxb; i++) {
            par[i][cur] = ii(cur, 0);
            siz[i][cur] = 1;
        }
        ID[v] = cur;
        return cur;
    }
    return it->second;
}

ii getPar(int b, int x)
{
    ii my = par[b][x];
    if (my.first == x) return my;
    ii got = getPar(b, my.first);
    got.second ^= my.second;
    par[b][x] = got;
    return got;
}

void unionSet(int b, int u, int v, int val)
{
    ii paru = getPar(b, u);
    ii parv = getPar(b, v);
    if (paru.first == parv.first) return;
    if (siz[b][paru.first] < siz[b][parv.first])
        swap(u, v);
    siz[b][paru.first] += siz[b][parv.first];
    par[b][parv.first] = ii(paru.first, (parv.second ^ paru.second ^ val));
}

int main()
{
    scanf("%d", &q);
    int lst = 0;
    while (q--) {
        int typ; scanf("%d", &typ);
        if (typ == 1) {
            int l, r, x; scanf("%d %d %d", &l, &r, &x);
            l ^= lst;
            r ^= lst;
            x ^= lst;
            if (l > r) swap(l, r);
            r++;
            l = getId(l);
            r = getId(r);
            bool ok = true;
            for (int i = 0; i < Maxb && ok; i++) {
                ii a = getPar(i, l);
                ii b = getPar(i, r);
                ok = a.first != b.first || (a.second ^ b.second) == bool(x & 1 << i);
            }
            if (ok)
                for (int i = 0; i < Maxb; i++)
                    unionSet(i, l, r, bool(x & 1 << i));
        } else {
            int l, r; scanf("%d %d", &l, &r);
            l ^= lst;
            r ^= lst;
            if (l > r) swap(l, r);
            r++;
            l = getId(l);
            r = getId(r);
            bool ok = true;
            lst = 0;
            for (int i = 0; i < Maxb && ok; i++) {
                ii a = getPar(i, l);
                ii b = getPar(i, r);
                if (a.first != b.first) ok = false;
                else if (a.second ^ b.second) lst |= 1 << i;
            }
            if (!ok) lst = -1;
            printf("%d\n", lst);
            if (lst == -1) lst = 1;
        }
    }
    return 0;
}