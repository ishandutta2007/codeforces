#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 998244353;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

//int inv(int x) {
//    return bp(x, mod - 2);
//}

int n;
const int maxN = 2e5 + 10;
int lp[maxN];
vector<int> pr[maxN];
vector<int> who[maxN];
int A[maxN];
vector<int> g[maxN];
const int LOG = 20;
int up[LOG][maxN];
int h[maxN];
int timer = 0;
int tin[maxN];
int tout[maxN];
bool byTin(int a, int b) {
    return tin[a] < tin[b];
}
void dfs(int v, int p) {
    tin[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        h[to] = h[v] + 1;
        up[0][to] = v;
        dfs(to, v);
    }
    tout[v] = timer++;
}
int lca(int x, int y) {
    if (h[x] < h[y]) swap(x, y);
    for (int k = LOG - 1; k >= 0; k--) {
        if (h[x] - (1 << k) >= h[y]) {
            x = up[k][x];
        }
    }
    if (x == y) return x;
    for (int k = LOG - 1; k >= 0; k--) {
        if (up[k][x] != up[k][y]) {
            x = up[k][x];
            y = up[k][y];
        }
    }
    return up[0][x];
}
int ACTIVE = 0;
vector<pair<int,int>> ed[maxN];
bool act[maxN];
const int inv6 = pw(6, mod - 2);
int c3(int x) {
    return mult(x, mult(x - 1, mult(x - 2, inv6)));
}
int sz[maxN];

int ANS = 0;
void calc(int v) {
    sz[v] = (act[v] == true);
    for (auto& it : ed[v]) {
        calc(it.first);
        sz[v] += sz[it.first];
        ANS = sum(ANS, mult(it.second, sub(c3(ACTIVE), sum(c3(sz[it.first]), c3(ACTIVE - sz[it.first])))));
//        cout << " COEF " << mult(it.second, sub(c3(ACTIVE), sum(c3(sz[it.first]), c3(ACTIVE - sz[it.first])))) << endl;
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        who[A[i]].emplace_back(i);
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    dfs(1, -1);
    for (int k = 0; k + 1 < LOG; k++) {
        for (int i = 1; i <= n; i++) {
            up[k + 1][i] = up[k][up[k][i]];
        }
    }
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == i) {
            vector<int> vr;
            ACTIVE = 0;
            for (int all : pr[i]) {
                for (int id : who[all]) {
                    vr.emplace_back(id);
                    ACTIVE++;
                    act[id] = true;
                }
            }
            if (vr.empty()) continue;
            sort(vr.begin(), vr.end(), byTin);
            int m = vr.size();
            for (int it = 0; it + 1 < m; it++) {
                vr.emplace_back(lca(vr[it], vr[it + 1]));
            }
            sort(vr.begin(), vr.end(), byTin);
            vr.erase(unique(vr.begin(), vr.end()), vr.end());
            vector < int > st;
            st.push_back(vr[0]);
//            cout << " EDD " << i << endl;
            for (int it = 1; it < vr.size(); it++) {
                int x = vr[it];
                while (tout[st.back()] < tin[x]) st.pop_back();
                int y = st.back();
                ed[y].emplace_back(x, h[x] - h[y]);
//                cout << y << " -> " << x << " " << h[x] - h[y] << endl;
                st.push_back(x);
            }

            int root = vr[0];
            calc(root);
            for (int u : vr) {
                ed[u].clear();
                act[u] = false;
                sz[u] = 0;
            }
//            cout << i << " " << ANS << " HI " << endl;
        }
    }
    cout << ANS << '\n';
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            for (int j = i; j < maxN; j += i) {
                lp[j] = i;
                pr[i].emplace_back(j);
            }
        }
    }
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}