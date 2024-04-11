#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3005;
int n, m;
vector<int> g[maxN];
int deg[maxN];
int has[maxN][maxN];
int ROOT = -1;
int take[maxN];
int cur_deg[maxN];
bool used[maxN];
int C = 0;

void dfs(int v) {
    used[v] = true;
    ++C;
    for (int to : g[v]) {
        if (used[to]) continue;
        if (v == ROOT && !take[to]) continue;
        dfs(to);
    }
}

bool was[maxN][maxN];

vector<int> go(int from) {
    vector<int> ptr(n + 1, 1);
    vector<int> st;
    st.push_back(from);
    vector<int> res;
    while (!st.empty()) {
        auto it = st.back();
        while (ptr[it] <= n) {
            if (was[it][ptr[it]]) ptr[it]++;
            else if (!has[it][ptr[it]]) ptr[it]++;
            else if (it == ROOT && !take[ptr[it]]) ptr[it]++;
            else if (ptr[it] == ROOT && !take[it]) ptr[it]++;
            else break;
        }
        if (ptr[it] == n + 1) {
            res.emplace_back(it);
            st.pop_back();
        } else {
            st.push_back(ptr[it]);
            was[it][ptr[it]] = was[ptr[it]][it] = true;
            ptr[it]++;
        }
    }
//    reverse(res.begin(), res.end());
//    for (int v : res) cout << v << " ";
//    cout << endl;
//    cout << " ZHIOPA " << endl;
    return res;
}

void check() {
    int f = 0;
    memset(cur_deg, 0, sizeof cur_deg);
    for (int i = 1; i <= n; i++) {
        cur_deg[i] += deg[i];
        if (has[ROOT][i] && !take[i]) {
            cur_deg[i]--;
            cur_deg[ROOT]--;
        }
    }
    C = 0;
    for (int i = 1; i <= n; i++) {
        if (cur_deg[i] & 1) {
            f++;
        }
        if (i != ROOT && cur_deg[i] == 0) C++;
    }
//    if (ROOT == 2) {
//        cout << C << " HI " << endl;
//    }
    if (f > 2 || (f == 2 && cur_deg[ROOT] % 2 == 0)) return;
    memset(used, 0, sizeof used);
    dfs(ROOT);
    if (C != n) return;
    vector<int> vec;
    if (f == 0) {
        vec = go(ROOT);

    } else {
        int x = 0;
        for (int i = 1; i <= n; i++) {
            if (i != ROOT && cur_deg[i] % 2 == 1) x = i;
        }
        vec = go(x);
    }
    reverse(vec.begin(), vec.end());
    assert(vec.back() == ROOT);
    vec.emplace_back(-1);
    for (int i = 1; i <= n; i++) {
        if (has[ROOT][i] && !take[i]) {
            vec.emplace_back(i);
            vec.emplace_back(ROOT);
        }
    }
    cout << vec.size() << '\n';
    for (int v : vec) {
        cout << v << " ";
    }
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        deg[a]++;
        deg[b]++;
        has[b][a] = has[a][b] = 1;
    }
    vector<int> odd;
    for (int i = 1; i <= n; i++) {
        if (deg[i] & 1) odd.emplace_back(i);
    }
    if (odd.size() <= 2) {
        vector<int> vec;
        if (odd.empty()) {
            vec = go(1);
        } else {
            vec = go(odd[0]);
        }
        cout << vec.size() << '\n';
        for (int v : vec) cout << v << " ";
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        int f = 0;
        for (int j = 1; j <= n; j++) {
            if (i != j && !has[i][j] && deg[j] % 2 == 1) f++;
        }
        if (f >= 2) continue;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
        }
        ROOT = i;
        for (int x = 1; x <= n; x++) {
            if (i == x) continue;
            if (has[i][x]) {
                if (deg[x] % 2 == 1) {
                    take[x] = 0;
                } else {
                    take[x] = 1;
                }
            }
        }
        check();
        for (int u = 1; u <= n; u++) {
            if (has[i][u]) {
                take[u] ^= 1;
                check();
                take[u] ^= 1;
            }
        }
    }
    cout << 0;
    return 0;
}