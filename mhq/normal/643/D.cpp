#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, q;
const int maxN = (int)1e5 + 100;
ll t[maxN];
int f[maxN];
set < pair < ll, int > > all_in[maxN];
int deg[maxN];
ll cur_cost[maxN];
ll cur_val[maxN];

// ne menyaem deg
void update_son(int v, int d) {
    ll was = (t[v] / (deg[v] + 2));
    cur_cost[f[v]] += d * was;
}
void update_self(int v, int d) {
    ll le = t[v] - (deg[v] + 1) * (t[v] / (deg[v] + 2));
    cur_cost[v] -= le;
    deg[v] += d;
    le = t[v] - (deg[v] + 1) * (t[v] / (deg[v] + 2));
    cur_cost[v] += le;
    deg[v] -= d;
}
bool is_inter[maxN];
//
int tp[maxN], a[maxN], b[maxN];
int nf[maxN];
const int block = 1000;
set < int > need_see;
bool see[maxN];
ll ansmn[maxN], ansmx[maxN];
set < int > need_inter;
void rebuild(int l, int r) {
    need_see.clear();
    need_inter.clear();
    memset(see, 0, sizeof see);
    memset(deg, 0, sizeof deg);
    memset(cur_cost, 0, sizeof cur_cost);
    memset(cur_val, 0, sizeof cur_val);

    for (int i = 1; i <= n; i++) {
        deg[f[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        ll le = t[i] - (deg[i] + 1) * (t[i] / (deg[i] + 2));
        cur_cost[i] += le;
        cur_val[i] += le;
        ll le2 = t[f[i]] / (deg[f[i]] + 2);
        cur_val[i] += le2;
        ll le3 = (t[i]) / (deg[i] + 2);
        cur_cost[f[i]] += le3;
        cur_val[f[i]] += le3;
    }
    memset(is_inter, 0, sizeof is_inter);
    for (int i = 1; i <= n; i++) {
        nf[i] = f[i];
    }
    for (int i = l; i <= r; i++) {
        if (tp[i] == 1) {
            is_inter[b[i]] = is_inter[nf[a[i]]] = true;
            see[nf[nf[a[i]]]] = true;
            see[nf[b[i]]] = true;
            need_see.insert(nf[nf[a[i]]]);
            need_see.insert(nf[b[i]]);
            need_see.insert(a[i]);
            need_see.insert(b[i]);
            need_see.insert(nf[a[i]]);
            nf[a[i]] = b[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (is_inter[i]) need_inter.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        nf[i] = f[i];
        if (is_inter[nf[i]]) see[i] = true;
    }
    ll mn = LONG_LONG_MAX;
    ll mx = LONG_LONG_MIN;
    for (int i = 1; i <= n; i++) {
        if (!see[i] && !need_see.count(i)) {
            mn = min(mn, cur_val[i]);
            mx = max(mx, cur_val[i]);
        }
        all_in[i].clear();
    }
    for (int i = l; i <= r; i++) {
        if (tp[i] == 3) {
            ansmn[i] = min(ansmn[i], mn);
            ansmx[i] = max(ansmx[i], mx);
        }
    }
    for (int i = 1; i <= n; i++) {
        all_in[f[i]].insert(make_pair(cur_cost[i], i));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }

    for (int i = 1; i <= q; i++) {
        ansmn[i] = LONG_LONG_MAX;
        ansmx[i] = LONG_LONG_MIN;
        cin >> tp[i];
        if (tp[i] == 1) cin >> a[i] >> b[i];
        else if (tp[i] == 2) cin >> a[i];
    }
    ll mxx = -1;
    ll mnx = -1;
    bool was_first = true;
    for (int i = 1; ; i++) {
        int l = (i - 1) * block + 1;
        int r = min(i * block, q);
        if (l > r) break;
        rebuild(l, r);
        for (int j = l; j <= r; j++) {
            if (tp[j] == 2) {
                int v = a[j];
                ll val = cur_cost[v] + (t[f[v]] / (deg[f[v]] + 2));
                cout << val << '\n';
            }
            else if (tp[j] == 1) {
                was_first = true;
                int from = a[j];
                int to = b[j];
                int bef = f[from];
                all_in[bef].erase(make_pair(cur_cost[from], from));
                all_in[f[bef]].erase(make_pair(cur_cost[bef], bef));
                all_in[f[to]].erase(make_pair(cur_cost[to], to));
                all_in[f[f[bef]]].erase(make_pair(cur_cost[f[bef]], f[bef]));
                all_in[f[f[to]]].erase(make_pair(cur_cost[f[to]], f[to]));
                update_son(from, -1);
                update_self(bef, -1);
                update_son(bef, -1);
                deg[bef]--;
                update_son(bef, 1);
                update_self(to, 1);
                update_son(to, -1);
                deg[to]++;
                update_son(to, 1);
                f[from] = to;
                update_son(from, 1);
                all_in[to].insert(make_pair(cur_cost[from], from));
                all_in[f[bef]].insert(make_pair(cur_cost[bef], bef));
                all_in[f[to]].insert(make_pair(cur_cost[to], to));
            }
            else {
                ll mx = ansmx[j];
                ll mn = ansmn[j];
                if (!was_first) {
                    cout << mnx << " " << mxx << '\n';
                    continue;
                }
                was_first = false;
                for (int v : need_see) {
                    ll val = cur_cost[v] + (t[f[v]] / (deg[f[v]] + 2));
                    mn = min(mn, val);
                    mx = max(mx, val);
                }
                for (int v : need_inter) {
                    ll upd_cost = (t[v] / (deg[v] + 2));
                    if (all_in[v].empty()) continue;
                    auto it1 = all_in[v].begin();
                    mn = min(mn, (*it1).first + upd_cost);
                    auto it2 = (--all_in[v].end());
                    mx = max(mx, (*it2).first + upd_cost);
                }
                mnx = mn;
                mxx = mx;
                cout << mn << " " << mx << '\n';
            }
        }
    }
}