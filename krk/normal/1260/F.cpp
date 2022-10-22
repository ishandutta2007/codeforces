#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int mod = 1000000007;
const int Maxn = 200005;

struct BIT {
    vector <int> Abot, Bbot;
    vector <int> Atop, Btop;
    BIT(int n = 1) {
        Abot.resize(n + 1, 0);
        Bbot.resize(n + 1, 0);
        Atop.resize(n + 1, 0);
        Btop.resize(n + 1, 0);
    }
    void addBot(int mult, int len, int ind)
    {
        int addA = ll(mult) * (len + ind) % mod;
        int addB = mult;
        ind++;
        for (int i = ind; i > 0; i -= i & -i) {
            Abot[i] = (Abot[i] + addA) % mod;
            Bbot[i] = (Bbot[i] + addB) % mod;
        }
    }
    void addTop(int mult, int len, int ind)
    {
        int addA = ll(len - ind + mod) % mod * mult % mod;
        int addB = mult;
        ind++;
        for (int i = ind; i < Atop.size(); i += i & -i) {
            Atop[i] = (Atop[i] + addA) % mod;
            Btop[i] = (Btop[i] + addB) % mod;
        }
    }
    ii getBot(int ind)
    {
        ii res = ii(0, 0);
        ind++;
        for (int i = ind; i < Abot.size(); i += i & -i) {
            res.first = (res.first + Abot[i]) % mod;
            res.second = (res.second + Bbot[i]) % mod;
        }
        return res;
    }
    ii getTop(int ind)
    {
        ii res = ii(0, 0);
        ind++;
        for (int i = ind; i > 0; i -= i & -i) {
            res.first = (res.first + Atop[i]) % mod;
            res.second = (res.second + Btop[i]) % mod;
        }
        return res;
    }
};

int n;
ii events[Maxn];
int elen;
vector <int> neigh[Maxn];
int mymult[Maxn], mydiv[Maxn];
int cur, lef[Maxn], rig[Maxn];
int cnt[Maxn], P[Maxn], L[Maxn];
int head[Maxn], id[Maxn];
bool on[Maxn];
BIT bt[Maxn];
ii GBIT[Maxn];
int ans, res;

void Add(int ind, ii my)
{
    for (int i = ind; i <= n; i += i & -i) {
        GBIT[i].first = (GBIT[i].first + my.first) % mod;
        GBIT[i].second = (GBIT[i].second + my.second) % mod;
    }
}

ii Get(int ind)
{
    ii res = ii(0, 0);
    for (int i = ind; i > 0; i -= i & -i) {
        res.first = (res.first + GBIT[i].first) % mod;
        res.second = (res.second + GBIT[i].second) % mod;
    }
    return res;
}

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

void Traverse1(int v)
{
    lef[v] = ++cur;
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == P[v]) continue;
        P[u] = v; L[u] = L[v] + 1;
        Traverse1(u);
        cnt[v] += cnt[u];
    }
    rig[v] = cur;
}

void Traverse2(int v)
{
    bool was = false;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == P[v]) continue;
        if (cnt[u] > cnt[v] / 2) {
            was = true;
            head[u] = head[v];
            id[u] = id[v] + 1;
        } else {
            head[u] = u;
            id[u] = 0;
        }
        Traverse2(u);
    }
    if (!was)
        bt[head[v]] = BIT(id[v] + 2);
}

void addWay(int v, int mult)
{
    Add(lef[v], ii(int(ll(mult) * L[v] % mod), mult));
    int len = 0;
    while (v != 0) {
        bt[head[v]].addTop(mult, len, id[v]);
        bt[head[v]].addBot(mult, len, id[v]);
        len += L[v] - L[P[head[v]]];
        v = P[head[v]];
    }
}

int getWay(int v, int mult2)
{
    int lst = -1;
    int res = 0;
    int len2 = 0;
    while (v != 0) {
        ii got = bt[head[v]].getTop(id[v] - 1);
        res = (res + ll(got.first) + ll(len2 + id[v]) * got.second) % mod;
        got = bt[head[v]].getBot(id[v]);
        res = (res + ll(got.first) + ll(len2 - id[v] + mod) % mod * got.second) % mod;
        if (lst != -1) {
            ii a = Get(rig[lst]);
            ii b = Get(lef[lst] - 1);
            a.first = (a.first - b.first + mod) % mod;
            a.second = (a.second - b.second + mod) % mod;
            int val = (a.first - ll(L[v]) * a.second % mod + mod) % mod;
            res = (res - val + mod) % mod;
            res = (res - ll(len2) * a.second % mod + mod) % mod;
        }
        lst = head[v];
        len2 += L[v] - L[P[head[v]]];
        v = P[head[v]];
    }
    res = ll(res) * mult2 % mod;
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int l, r; scanf("%d %d", &l, &r);
        events[elen++] = ii(l, i);
        events[elen++] = ii(r + 1, -i);
        mymult[i] = r - l + 1;
        mydiv[i] = Inv(r - l + 1);
    }
    sort(events, events + elen);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    L[1] = 1; Traverse1(1);
    head[1] = 1; id[1] = 0; Traverse2(1);
    for (int i = 0; i + 1 < elen; i++) {
        int ind = events[i].second;
        int in = events[i + 1].first - events[i].first;
        if (ind > 0) {
            ans = (ans + getWay(ind, mydiv[ind])) % mod;
            addWay(ind, mydiv[ind]);
        } else {
            ind = -ind;
            addWay(ind, (mod - mydiv[ind]) % mod);
            ans = (ans - getWay(ind, mydiv[ind]) + mod) % mod;
        }
        res = (res + ll(in) * ans) % mod;
    }
    for (int i = 1; i <= n; i++)
        res = ll(res) * mymult[i] % mod;
    printf("%d\n", res);
    return 0;
}