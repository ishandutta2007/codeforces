#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
const int LG = 20;
int n, k;
vector < int > g[maxN];
struct DistanceSolver{
    int ti = 0;
    vector < int > fi;
    vector < int > lg;
    vector < int > h;
    vector < vector < int > > up;

    void init() {
        lg.resize(2 * n + 1);
        fi.resize(n);
        h.resize(n);
        lg[1] = 0;
        for (int i = 2; i <= 2 * n; i++) {
            lg[i] = lg[i - 1];
            if (!(i & (i - 1))) lg[i]++;
        }
        up.resize(LG);
        dfs(0, -1);
        for (int i = 1; i < LG; i++) {
            up[i].resize(up[0].size());
        }
        for (int i = 0; i + 1 < LG; i++) {
            for (int j = 0; j + (1 << (i + 1)) - 1 < up[0].size(); j++) {
                up[i + 1][j] = min(up[i][j], up[i][j + (1 << i)]);
            }
        }
    }

    void dfs(int v, int p) {
        fi[v] = ti;
        up[0].push_back(h[v]);
        ti++;
        for (int to : g[v]) {
            if (to == p) continue;
            up[0].push_back(h[v]);
            ti++;
            h[to] = h[v] + 1;
            dfs(to, v);
        }
    }

    int getDist(int u, int v) {
        //cout << u << " " << v << " " << endl;
        if (u == v) return 0;
        int l = fi[u]; int r = fi[v];
        if (l > r) swap(l, r);
        int k = lg[r - l + 1];
        int h_lca = min(up[k][l], up[k][r - (1 << k) + 1]);
        return h[u] + h[v] - 2 * h_lca;
    }

}DS;


int ti = 0;
int tin[maxN];
int tout[maxN];
void start_dfs(int v, int p) {
    tin[v] = ti++;
    for (int to : g[v]) {
        if (to == p) continue;
        start_dfs(to, v);
    }
    tout[v] = ti++;
}

void bad() {
    cout << "No";
    exit(0);
}

bool on_diam[maxN];
int clr[maxN];
int mx[maxN];
void calc(int v, int p) {
    mx[v] = 0;
    for (int to : g[v]) {
        if (to == p) continue;
        calc(to, v);
        mx[v] = max(mx[v], mx[to] + 1);
    }
}

void process(int v, int p, int clr_now, int add) {
    clr[v] = clr_now;
    for (int to : g[v]) {
        if (to == p) continue;
        process(to, v, (clr_now + add) % k, add);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DS.init();
    if (k == 2) {
        cout << "Yes" << '\n';
        for (int i = 0; i < n; i++) {
            cout << DS.getDist(0, i) % 2 + 1 << " ";
        }
        return 0;
    }
    pair < int, int > best = make_pair(-1, -1);
    for (int i = 0; i < n; i++) {
        best = max(best, make_pair(DS.getDist(0, i), i));
    }
    int A = best.second;
    assert(A != -1);
    best = make_pair(-1, -1);
    for (int i = 0; i < n; i++) {
        best = max(best, make_pair(DS.getDist(A, i), i));
    }
    int B = best.second;
    assert(best.second != -1);
    start_dfs(A, -1);
    memset(clr, -1, sizeof clr);
    for (int i = 0; i < n; i++) {
        if (tin[i] <= tin[B] && tout[B] <= tout[i]) {
            on_diam[i] = true;
            clr[i] = DS.getDist(A, i) % k;
        }
    }
    for (int i = 0; i < n; i++) {
        if (on_diam[i]) {
            for (int to : g[i]) {
                if (!on_diam[to]) {
                    calc(to, i);
                    if (mx[to] + min(DS.getDist(A, to), DS.getDist(B, to)) + 1 >= k) {
                        bad();
                    }
                    if (mx[to] + max(DS.getDist(A, to), DS.getDist(B, to)) + 1 < k) {
                        // all colors are good
                        continue;
                    }
                    if (mx[to] + DS.getDist(A, to) + 1 >= k) {
                        process(to, i, (clr[i] + 1) % k, 1);
                    }
                    else {
                        process(to, i, (clr[i] + k - 1) % k, k - 1);
                    }
                }
            }
        }
    }
    cout << "Yes" << '\n';
    for (int i = 0; i < n; i++) {
        if (clr[i] == -1) clr[i] = 0;
        cout << clr[i] + 1 << " ";
    }
    return 0;
}