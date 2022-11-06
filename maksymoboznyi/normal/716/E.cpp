#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e5 + 5;

bool is[N];
int lvl[N], num[N], par[N], n, M, v1[N], v2[N], to[N], from[N], ans = 0, phi, dep[N];
map<int, int> m1, m2;
vector<int> comp, t[N];
vector<pair<int, int> > g[N];

int gp(int a, int b) {
    int res = 1;
    while (b > 0)
        if (b % 2 == 0)
            b /= 2, a *= a, a %= M;
        else
            b--, res *= a, res %= M;
    return res;
}

void calc_phi(int M) {
    phi = M;
    int p = 2;
    int m = M;
    while (p * p <= m) {
        while (p * p <= m && M % p != 0)
            p++;
        if (M % p == 0) {
            phi /= p;
            phi *= (p - 1);
            while (M % p == 0)
                M /= p;
        }
    }
    if (M != 1)
        phi /= M, phi *= (M - 1);
}

int dfs1(int v, int sz, int &center, int p = -1) {
    int sum = 1;
    comp.pb(v);
    for (int i = 0; i < g[v].size(); i++)
        if (lvl[g[v][i].first] == -1 && g[v][i].first != p)
            sum += dfs1(g[v][i].first, sz, center, v);
    if (center == -1 && 2 * sum >= sz)
        center = v;
    return sum;
}

void build(int v, int dep, int p = 0) {
    int center = -1, tmp = -1;
    int sz = dfs1(v, tmp, tmp);
    comp.clear();
    dfs1(v, sz, center);
    //cout << center << endl;
    lvl[center] = dep;
    par[center] = p;
    t[center] = comp;
  //  cout << g[center].size() << endl;
    for (int i = 0; i < g[center].size(); i++)
        if (lvl[g[center][i].first] == -1)
            build(g[center][i].first, dep + 1, center);

}

void dfs2(int v, int p = -1, int up = 0, int down = 0, int part = -1, int h = 0) {
    v1[v] = up;
    v2[v] = down;
    dep[v] = h;
    num[v] = part;
    for (int i = 0; i < g[v].size(); i++)
    if (is[g[v][i].first] && g[v][i].first != p) {
        int p1 = part;
        if (part == -1)
            p1 = i;
        int up1 = up, down1 = down;
        int x = g[v][i].second;
        down1 *= 10;
        down1 += x;
        down1 %= M;
        up1 += gp(10, h)*x % M;
        up1 %= M;
        dfs2(g[v][i].first, v, up1, down1, p1, h + 1);
    }
}

void solve(int center) {
    m1.clear();
    m2.clear();
    //cout << center << endl;
    for (int i = 0; i < t[center].size(); i++)
        is[t[center][i]] = 1;//, cout << '*' << t[center][i] << endl;
    dfs2(center);
    vector<map<int, int> > sub;
    sub.resize(g[center].size());
    map<int, int> kol;
    for (int i = 0; i < t[center].size(); i++) {
        int u = t[center][i];
        if (u != center) {
            sub[num[u]][v1[u]]++;
            kol[v1[u]]++;
        }
    }
   //cout << '1' << ans << endl;
    ans += kol[0];

    //cout << '2' << ans << endl;
    for (int i = 0; i < t[center].size(); i++)
        if (v2[t[center][i]] == 0)
            ans++;
    ans--;

   // cout << '3' << ans << endl;
    for (int i = 0; i < t[center].size(); i++) {
        int u = t[center][i];
        if (u != center) {
            int want = (-v2[u] * gp(gp(10, phi - 1), dep[u]) % M) + M;
            want %= M;
            ans += kol[want] - sub[num[u]][want];
        }
    }
    for (int i = 0; i < t[center].size(); i++)
        is[t[center][i]] = 0;
    //cout << '/' << center << ' ' << ans << endl;
}

signed main()
{
    cin >> n >> M;
    calc_phi(M);
    for (int i = 1; i <= n; i++)
        lvl[i] = -1;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a++;
        b++;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    build(1, 1);
    for (int i = 1; i <= n; i++)
        solve(i);
    cout << ans << endl;
    return 0;
}