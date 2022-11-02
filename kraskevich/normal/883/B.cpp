#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 200 * 1000 + 10;

vector<int> g[N];
vector<int> gr[N];
int col[N];
int init_rank[N];
int ans_rank[N];
int L[N];
int R[N];
bool is_covered[N];
bool has_cyc;

void dfs_cyc(int v) {
    col[v] = 1;
    for (int to : g[v]) {
        if (col[to] == 0) {
            dfs_cyc(to);
            continue;
        }
        if (col[to] == 1)
            has_cyc = true;
    }
    col[v] = 2;
}

int calc_dp(int v) {
    if (col[v])
        return L[v];
    col[v] = 1;
    for (int to : g[v])
        L[v] = max(L[v], calc_dp(to) + 1);
    return L[v];
}

int calc_dp_rev(int v) {
    if (col[v])
        return R[v];
    col[v] = 1;
    for (int to : gr[v])
        R[v] = min(R[v], calc_dp_rev(to) - 1);
    return R[v];
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> init_rank[i];
        is_covered[init_rank[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        gr[y].push_back(x);
    }
    fill(L, L + n, 1);
    fill(R, R + n, k);
    for (int i = 0; i < n; i++)
        if (init_rank[i])
            L[i] = R[i] = init_rank[i];

    for (int i = 0; i < n; i++) 
        if (col[i] == 0) 
            dfs_cyc(i);
    if (has_cyc) {
        cout << -1 << endl;
        return 0;
    }

    //cerr << "NO CYC" << endl;

    fill(col, col + n, 0);
    for (int i = 0; i < n; i++)
        calc_dp(i);
    fill(col, col + n, 0);
    for (int i = 0; i < n; i++)
        calc_dp_rev(i);

    /*
    for (int i = 0; i < n; i++)
        cerr << L[i] << " ";
    cerr << endl;
    for (int i = 0; i < n; i++)
        cerr << R[i] << " ";
    cerr << endl;
    */

    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (L[i] > R[i])
            ok = false;
    }
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
        ans_rank[i] = init_rank[i] ? init_rank[i] : R[i];
    
    set<pii> open;
    vector<vector<pii>> open_at(k + 1);
    vector<vector<pii>> close_at(k + 1);
    for (int i = 0; i < n; i++) {
        open_at[L[i]].emplace_back(R[i], i);
        close_at[R[i]].emplace_back(R[i], i);
    }
    
    for (int i = 1; i <= k; i++) {
        for (auto p : open_at[i])
            open.insert(p);
        if (!is_covered[i]) {
            if (open.empty()) {
                cout << -1 << endl;
                return 0;
            }
            auto it = open.begin();
            ans_rank[it->second] = i;
            open.erase(it);
        }
        for (auto p : close_at[i])
            open.erase(p);
    }
    for (int i = 0; i < n; i++)
        cout << ans_rank[i] << " ";
    cout << endl;
}