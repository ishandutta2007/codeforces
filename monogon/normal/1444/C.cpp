
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 5e5 + 5;
int n, m, k;
int dsu[N], c[N];
stack<pii> st;
bool col[N], bad[N];

int trace(int x) {
    return dsu[x] < 0 ? x : trace(dsu[x]);
}
bool color(int x) {
    return col[x] ^ (dsu[x] < 0 ? false : color(dsu[x]));
}
bool join(int x, int y) {
    bool c1 = color(x), c2 = color(y);
    if((x = trace(x)) == (y = trace(y))) {
        return c1 != c2;
    }
    if(dsu[x] > dsu[y]) swap(x, y);
    col[y] ^= (c1 == c2) ^ col[x];
    st.emplace(y, dsu[y]);
    dsu[x] += dsu[y];
    dsu[y] = x;
    return true;
}
void oops() {
    assert(!st.empty());
    int y, val;
    tie(y, val) = st.top(); st.pop();
    dsu[trace(y)] -= val;
    dsu[y] = val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    rep(i, 1, n + 1) {
        cin >> c[i];
    }
    fill(dsu, dsu + N, -1);
    map<pii, vector<pii>> ma;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        if(c[u] == c[v]) {
            if(!join(u, v)) {
                bad[c[u]] = true;
            }
        }else {
            if(c[u] > c[v]) swap(u, v);
            ma[{c[u], c[v]}].emplace_back(u, v);
        }
    }
    ll numgood = k;
    rep(i, 1, k + 1) numgood -= bad[i];
    ll ans = numgood * (numgood - 1) / 2;
    for(auto &pg : ma) {
        int g1, g2;
        tie(g1, g2) = pg.first;
        int ops = sz(st);
        if(bad[g1] || bad[g2]) continue;
        for(auto &pa : pg.second) {
            int u, v;
            tie(u, v) = pa;
            if(!join(u, v)) {
                ans--;
                goto hell;
            }
        }
        hell:;
        while(sz(st) > ops) oops();
    }
    cout << ans << '\n';
}