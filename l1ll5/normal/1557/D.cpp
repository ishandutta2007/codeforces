#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 600000 + 5;
constexpr int mod = 1000000000 + 7;
int n, m;
vector<pair<int, int> > v[maxn];
pair<int, int> Tmx[maxn << 2], Tag[maxn << 2];
#define ls (x << 1)
#define rs (x << 1 | 1)
#define fi first
#define se second
void pushdown(int x) {
    if (Tag[x] != make_pair(0, 0)) {
        Tmx[ls] = max(Tag[x], Tmx[ls]);
        Tmx[rs] = max(Tag[x], Tmx[rs]);
        Tag[ls] = max(Tag[x], Tag[ls]);
        Tag[rs] = max(Tag[x], Tag[rs]);
        Tag[x] = make_pair(0, 0);
    }
}
void upd(int x, int l, int r, int L, int R, pair<int, int> v) {
    if (l >= L && r <= R) {
        Tmx[x] = max(Tmx[x], v);
        Tag[x] = max(Tag[x], v);
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(x);
    if (L <= mid) upd(ls, l, mid, L, R, v);
    if (R > mid)  upd(rs, mid + 1, r, L, R, v);
    Tmx[x] = max(Tmx[ls], Tmx[rs]);
}
pair<int, int> ask(int x, int l, int r, int L, int R) {
    if (l >= L && r <= R) {
        return Tmx[x];
    }
    int mid = (l + r) >> 1;
    pushdown(x);
    pair<int, int> ret = make_pair(0, 0);
    if (L <= mid) ret = max(ret, ask(ls, l, mid, L, R));
    if (R > mid)  ret = max(ret, ask(rs, mid + 1, r, L, R));
    return ret;
}
map<int, int> mp;
int pre[maxn], vis[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<int> ref;
    for (int i = 1; i <= m; i += 1) {
        int x, l, r;
        cin >> x >> l >> r;
        ref.push_back(l), ref.push_back(r);
        v[x].push_back(make_pair(l, r));
    }
    sort(ref.begin(), ref.end());
    int SZ = 0;
    for (auto x : ref) {
        if (mp[x] == 0) mp[x] = ++SZ;
    }
    for (int i = 1; i <= n; i += 1) {
        pair<int, int> mx = make_pair(0, 0);
        for (auto x : v[i]) {
            int L = x.first, R = x.second;
            mx = max(mx, ask(1, 1, SZ, mp[L], mp[R]));
        }
        pre[i] = mx.second;
        mx.first++;
        mx.second = i;
        for (auto x : v[i]) {
            int L = x.first, R = x.second;
            upd(1, 1, SZ, mp[L], mp[R], mx);
        }
    }
    int cur = Tmx[1].second;
    while (cur) {
        vis[cur] = 1;
        cur = pre[cur];
    }
    vector<int> ans;
    for (int i = 1; i <= n; i += 1) {
        if (!vis[i]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }
}