#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define sz(a) int((a).size())
#define ll long long
#define db double
#define vi vector<int>
using namespace std;
const int N = 1e5 + 10;
int n, siz[N], l[N], r[N], fa[N], cnt[N], dfn[N], dfntot = 0;
ll k, L, R;
vector<int> e[N], s[N];
vector<pair<int, int>> ans;
void dfs1(int u, int fa) {
    dfn[++dfntot] = u;
    ::fa[u] = fa;
    siz[u] = 1;
    for(auto v : e[u]) if(v != fa) {
        dfs1(v, u), siz[u] += siz[v];
    }
    l[u] = siz[u] & 1, r[u] = min(siz[u], n - siz[u]);
}
priority_queue<pair<int, int>> pq;
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    FOR(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v), e[v].emplace_back(u);
    }
    dfs1(1, 0);
    FOR(u, 1, n) L += l[u], R += r[u];
    if(k < L || R < k) {
        cout << "NO\n";
        return 0;
    }
    k -= L;
    if(k & 1) {
        cout << "NO\n";
        return 0;
    }
    int l = 1, r = n, best = 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        ll sum = 0;
        FOR(u, 2, n) sum += (min(mid, ::r[u]) - ::l[u]) / 2 * 2;
        if(sum <= k) best = mid, l = mid + 1;
        else r = mid - 1;
    }
    FOR(u, 2, n) cnt[u] = (min(best, ::r[u]) - ::l[u]) / 2 * 2, k -= cnt[u], cnt[u] += ::l[u];
    FOR(u, 2, n) {
        if(cnt[u] + 2 == best + 1 && cnt[u] + 2 <= ::r[u] && k) {
            k -= 2;
            cnt[u] += 2;
        } 
    }
    ROF(i, n, 1) {
        int u = dfn[i];
        s[u].emplace_back(u);
        pq.emplace(sz(s[u]), u);
        int sum = 1;
        for(auto v : e[u]) if(v != fa[u] && sz(s[v])) pq.emplace(sz(s[v]), v), sum += cnt[v];
        sum -= cnt[u];
        // cout << u <<" " << cnt << endl;
        while(sz(pq) >= 2 && sum) {
            sum -= 2;
            auto [su, u] = pq.top();
            pq.pop();
            auto [sv, v] = pq.top();
            pq.pop();
            su--, sv--;
            int x = s[u].back();
            s[u].pop_back();
            int y = s[v].back();
            s[v].pop_back();
            ans.emplace_back(x, y);
            // cout << su <<" " << sv <<" " << x <<" " << y << endl;
            if(su) pq.emplace(su, u);
            if(sv) pq.emplace(sv, v);
        }
        while(!pq.empty()) {
            auto [sv, v] = pq.top();
            pq.pop();
            if(v == u) continue;
            if(sz(s[u]) < sz(s[v])) s[u].swap(s[v]);
            s[u].insert(s[u].end(), s[v].begin(), s[v].end());
        }
    }
    cout << "YES\n";
    for(auto [u, v] : ans) cout << u <<" " << v << "\n";
    return 0;
}