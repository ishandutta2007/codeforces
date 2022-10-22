#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 500005;

struct lin {
    int a;
    ll b;
    bool operator <(const lin &oth) const {
        if (a != oth.a) return a < oth.a;
        return b < oth.b;
    }
};

ll getX(const lin &l1, const lin &l2)
{
    if (l1.a == l2.a || l1.b <= l2.b) return 0;
    return (l1.b - l2.b - 1) / (l2.a - l1.a) + 1;
}

map <lin, ll> M;
map <ll, lin> X;

void Insert(const lin &l)
{
    map <lin, ll>::iterator it = M.lower_bound(l);
    while (it != M.begin()) {
        it--;
        ll myX = getX(it->first, l);
        if (myX <= it->second) {
            X.erase(it->second);
            M.erase(it++);
        } else { it++; break; }
    }
    ll candX;
    if (it == M.begin()) candX = 0;
    else {
        it--;
        candX = getX(it->first, l);
        it++;
    }
    if (it != M.end()) {
        ll myX = getX(l, it->first);
        if (myX <= candX) return;
        map <lin, ll>::iterator it2 = it;
        for (it2++; it2 != M.end(); it2++)
            if (it2->second <= myX) {
                X.erase(it->second);
                M.erase(it++);
                myX = getX(l, it2->first);
                if (myX <= candX) return;
            } else break;
        X.erase(it->second);
        it->second = myX;
        X.insert(make_pair(myX, it->first));
    }
    M[l] = candX; X[candX] = l;
}

ll Get(int x)
{
    if (X.empty()) return 0;
    map <ll, lin>::iterator it = X.upper_bound(x); it--;
    return ll(it->second.a) * x + it->second.b;
}

int n;
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int gcnt[Maxn];
int cnt[Maxn];
bool er[Maxn];
ll res;

void Init(int v, int p = 0)
{
    gcnt[v] = 1;
    lef[v] = ++cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Init(u, v);
        gcnt[v] += gcnt[u];
    }
    rig[v] = cur;
}

void Count(int v, int p)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        Count(u, v);
        cnt[v] += cnt[u];
    }
}

int getCentroid(int v, int p, int siz)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        if (cnt[u] > siz / 2) return getCentroid(u, v, siz);
    }
    return v;
}

int Neighs(int v, int p = 0)
{
    if (p == 0) return n;
    if (lef[v] < lef[p]) return n - gcnt[p];
    else return gcnt[v];
}

void Comp(int v, int p, int a, ll b)
{
    int my = Neighs(v, p);
    bool ch = false;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        ch = true; break;
    }
    if (!ch) {
        int na = a + my;
        ll nb = b + ll(a) * my;
        res = max(res, nb + ll(na) * (n - na));
        res = max(res, Get(na) + nb + ll(na) * n - ll(na) * na);
    }
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        Comp(u, v, a + my - Neighs(u, v), b + ll(a) * (my - Neighs(u, v)));
    }
}

void Record(int v, int p, int a, ll b)
{
    int my = Neighs(v, p);
    bool ch = false;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        ch = true; break;
    }
    if (!ch) {
        int na = a + my;
        ll nb = b + ll(a) * my;
        Insert(lin{-na, nb + ll(na) * n - ll(na) * na});
    }
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        Record(u, v, a + my - Neighs(u, v), b + ll(a) * (my - Neighs(u, v)));
    }
}

void Solve(int v)
{
    M.clear(); X.clear();
    Count(v, 0);
    int r = getCentroid(v, 0, cnt[v]);
    for (int i = 0; i < neigh[r].size(); i++) {
        int u = neigh[r][i];
        if (er[u]) continue;
        Comp(u, r, 0, 0);
        Record(u, r, 0, 0);
    }
    er[r] = true;
    for (int i = 0; i < neigh[r].size(); i++) {
        int u = neigh[r][i];
        if (er[u]) continue;
        Solve(u);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Init(1);
    Solve(1);
    res += ll(n) * (n - 1) / 2;
    printf("%I64d\n", res);
    return 0;
}