#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 10;
const int maxK = 22;
ll ans = 0;
int n;
int a[maxN];
vector < int > g[maxN];
bool used[maxN];
int bits[maxN][maxK][2];
int big[maxN];
int sz[maxN];
void first_dfs(int v, int p) {
    sz[v] = 1;
    big[v] = -1;
    for (int to : g[v]) {
        if (to == p || used[to]) continue;
        first_dfs(to, v);
        sz[v] += sz[to];
        if (big[v] == -1 || sz[big[v]] < sz[to]) {
            big[v] = to;
        }
    }
}
void xor_dfs(int v, int p) {
    for (int i = 0; i < maxK; i++) {
        bits[v][i][0] = bits[v][i][1] = 0;
        bits[v][i][0]++;
    }
    for (int to : g[v]) {
        if (to == p || used[to]) continue;
        xor_dfs(to, v);
        for (int i = 0; i < maxK; i++) {
            for (int j = 0; j < 2; j++) {
                bits[v][i][j] += bits[to][i][j];
            }
        }
    }
    for (int i = 0; i < maxK; i++) {
        if (a[v] & (1 << i)) {
            swap(bits[v][i][0], bits[v][i][1]);
        }
    }
}
ll total_sum[maxK][2];
void build_cd(int root) {
    first_dfs(root, -1);
    int cur_v = root;
    int n = sz[cur_v];
    while (big[cur_v] != -1 && sz[big[cur_v]] > (n / 2)) {
        cur_v = big[cur_v];
    }
    // n^2
    // x   0, y   1; 0
    // x   1, y   0 , 1
    //
    //   0
    // x * y - (a, b)
    xor_dfs(cur_v, -1);
    memset(total_sum, 0, sizeof total_sum);
    for (int to : g[cur_v]) {
        if (used[to]) continue;
        for (int i = 0; i < maxK; i++) {
            for (int j = 0; j < 2; j++) {
                total_sum[i][j] += bits[to][i][j];
            }
        }
    }
    // 0, 0
    ll cur_add = 0;
    // 0, 1
    ll other_add = 0;
    for (int to : g[cur_v]) {
        if (used[to]) continue;
        for (int i = 0; i < maxK; i++) {
            if (!(a[cur_v] & (1 << i))) {
                cur_add += (1 << i) * (bits[to][i][0] * (total_sum[i][1] - bits[to][i][1]) + bits[to][i][1] * (total_sum[i][0] - bits[to][i][0]));
                other_add += 1LL * (1 << i) * (bits[to][i][1]);
            }
            else {
                cur_add += (1 << i) * (bits[to][i][0] * (total_sum[i][0] - bits[to][i][0]) + bits[to][i][1] * (total_sum[i][1] - bits[to][i][1]));
                other_add += 1LL * (1 << i) * (bits[to][i][0]);
            }
        }
    }
    cur_add /= 2;
    ans += cur_add + a[cur_v] + other_add;
    used[cur_v] = true;
    for (int to : g[cur_v]) {
        if (used[to]) continue;
        build_cd(to);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    build_cd(1);
    cout << ans;
    return 0;
}