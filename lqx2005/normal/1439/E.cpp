#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define vi vector<int>
#define pr pair<int, int>
using namespace std;
const int N = 4e5 + 10;
int n;
int depth(pr u) {
    return u.first + u.second;
}
pr lca(pr u, pr v) {
    pr w;
    ROF(i, 30, 0) {
        pr uu, vv;
        uu = {u.first >> i & 1, u.second >> i & 1};
        vv = {v.first >> i & 1, v.second >> i & 1};
        if(uu == vv) {
            w.first += uu.first << i;
            w.second += uu.second << i;
            continue;
        }
        if(uu.first) {
            u = {(1 << i) - 1, 0};
        }
        if(uu.second) {
            u = {0, (1 << i) - 1};
        }
        if(vv.first) {
            v = {(1 << i) - 1, 0};
        }
        if(vv.second) {
            v = {0, (1 << i) - 1};
        }
    }
    return w;
}
int cmp(pr u, pr v) {
    if(u == v) return 0;
    pr w, pu = u, pv = v;
    ROF(i, 30, 0) {
        pr uu, vv;
        uu = {u.first >> i & 1, u.second >> i & 1};
        vv = {v.first >> i & 1, v.second >> i & 1};
        if(uu == vv) {
            w.first += uu.first << i;
            w.second += uu.second << i;
            continue;
        }
        else if((uu.first | uu.second) && (vv.first | vv.second)) return uu > vv;
        if(uu.first) {
            u = {(1 << i) - 1, 0};
        }
        if(uu.second) {
            u = {0, (1 << i) - 1};
        }
        if(vv.first) {
            v = {(1 << i) - 1, 0};
        }
        if(vv.second) {
            v = {0, (1 << i) - 1};
        }
    }
    if(pu == w) return 1;
    return 0;
}
int m, tot = 0;
map<pr, int> id;
vector<int> g[N];
int ce[N], cv[N], dep[N];
vector<int> sum;
void dfs(int u) {
    for(auto v : g[u]) {
        // cout << dep[u] <<" " << dep[v] << endl;
        dfs(v);
        ce[u] += ce[v];
        if(ce[v]) {
            sum.emplace_back(dep[u]);
            sum.emplace_back(dep[v]);
        }
    }
    if(cv[u] && !ce[u]) {
        sum.emplace_back(dep[u]);
        sum.emplace_back(dep[u] - 1);
    }
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> m;
    vector<pair<pr, pr>> path;
    vector<pr> ver;
    FOR(i, 1, m) {
        pr u, v;
        cin >> u.first >> u.second >> v.first >> v.second;
        pr w = lca(u, v);
        // cout << w.first <<" " << w.second << "\n";
        path.emplace_back(u, v);
        ver.emplace_back(u), ver.emplace_back(v);
    }
    stable_sort(ver.begin(), ver.end(), cmp);
    ver.erase(unique(ver.begin(), ver.end()), ver.end());
    int n = sz(ver);
    FOR(i, 0, n - 1) {
        ver.emplace_back(lca(ver[i], ver[(i + 1) % n]));
    }
    stable_sort(ver.begin(), ver.end(), cmp);
    ver.erase(unique(ver.begin(), ver.end()), ver.end());
    for(auto u : ver) id[u] = ++tot, dep[tot] = depth(u);
    FOR(i, 1, sz(ver) - 1) {
        g[id[lca(ver[i - 1], ver[i])]].emplace_back(id[ver[i]]);
    }
    pr rt = ver.front();
    FOR(i, 0, m - 1) {
        auto [u, v] = path[i];
        ce[id[u]]++, ce[id[v]]++;
        ce[id[lca(u, v)]] -= 2;
        cv[id[lca(u, v)]] += 1;
    }
    dfs(id[rt]);
    int ans = 0;
    sort(sum.begin(), sum.end());
    for(int l = 0, r; l < sz(sum); l = r + 1) {
        r = l;
        while(r + 1 < sz(sum) && sum[r + 1] == sum[r]) r++;
        if((r - l + 1) & 1 && (sum[l] >= 0)) ans++;
    }
    cout << ans << "\n";
    return 0;
}