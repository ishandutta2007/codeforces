#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 5e4 + 10;
int tp[maxN];
ll l[maxN], r[maxN];
vector<pair<ll,ll>> segs;
void rec(int bit, ll l, ll r) {
    ll all = (1LL << (bit + 1)) - 1;
    ll msk1 = l & all;
    ll msk2 = r & all;
    if (msk1 == 0 && msk2 == all) {
        segs.emplace_back(l, r);
        return;
    }
    if (msk1 >= (1LL << bit)) {
        rec(bit - 1, l, r);
    }
    else if (msk2 < (1LL << bit)) {
        rec(bit - 1, l, r);
    }
    else {
        ll f = l | ((1LL << bit) - 1);
        assert(l <= f && f + 1 <= r);
        rec(bit - 1, l, f);
        rec(bit - 1, f + 1, r);
    }
}
vector<pair<int,int>> to_add[maxN];
const int maxK = 2e6;
int p[maxK];
int sz[maxK];
int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}
void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return ;
    if (sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
}
bool ans[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    vector<pair<ll,ll>> f;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        if (s == "ask") tp[i] = 0;
        else tp[i] = 1;
        cin >> l[i] >> r[i];
        if (tp[i] == 1) f.emplace_back(l[i], r[i]);
    }
    sort(f.begin(), f.end());
    if (f.empty()) {
        f.emplace_back(0, (1LL << n) - 1);
    }
    vector<pair<ll,ll>> nf;
    if (f[0].first != 0) {
        nf.emplace_back(0, f[0].first - 1);
    }
    for (int i = 0; i < f.size(); i++) {
        nf.emplace_back(f[i]);
        if (i + 1 < f.size() && f[i].second + 1 <= f[i + 1].first - 1) nf.emplace_back(f[i].second + 1, f[i + 1].first - 1);
    }
    if (f.back().second + 1 <= (1LL << n) - 1) {
        nf.emplace_back(f.back().second + 1, (1LL << n) - 1);
    }
    for (auto& it : nf) {
        rec(n - 1, it.first, it.second);
    }
    vector<int> ti(segs.size(), -1);
    for (int i = 1; i <= m; i++) {
        if (tp[i] == 1) {
            int pos1 = lower_bound(segs.begin(), segs.end(), make_pair(l[i], -1LL)) - segs.begin();
            int pos2 = lower_bound(segs.begin(), segs.end(), make_pair(r[i] + 1, -1LL)) - segs.begin();
            for (int z = pos1; z < pos2; z++) {
                ti[z] = i;
            }
        }
    }
    for (int i = 0; i < segs.size(); i++) {
        if (ti[i] == -1) {
            ti[i] = m;
        }
    }
    for (int bit = 0; bit < n; bit++) {
        vector<int> group[2];
        for (int id = 0; id < segs.size(); id++) {
            ll l = segs[id].first;
            ll r = segs[id].second;
            if (r - l + 1 <= (1LL << bit)) {
                assert((l & (1LL << bit)) == (r & (1LL << bit)));
                group[(l >> bit) & 1].emplace_back(id);
            }
        }
        for (int z = 0; z < 2; z++) {
            int ptr = 0;
            for (int p : group[z]) {
                ll f = segs[p].first ^ (1LL << bit);
                while (segs[ptr].second < f) ptr++;
                if (segs[ptr].second - segs[ptr].first >= segs[p].second - segs[p].first) {
                    to_add[min(ti[ptr], ti[p])].emplace_back(ptr, p);
                }
            }
        }
    }
    assert(segs.size() < maxK);
    for (int i = 0; i < segs.size(); i++) {
        p[i] = i;
        sz[i] = 1;
    }
    for (int i = m; i >= 1; i--) {
        for (auto& it : to_add[i]) {
            unite(it.first, it.second);
        }
        if (tp[i] == 0) {
            int p1 = upper_bound(segs.begin(), segs.end(), make_pair(l[i] + 1, -1LL)) - segs.begin() - 1;
            int p2 = upper_bound(segs.begin(), segs.end(), make_pair(r[i] + 1, -1LL)) - segs.begin() - 1;
            if (get(p1) == get(p2)) {
                ans[i] = true;
            }
            else {
                ans[i] = false;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (tp[i] == 0) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}