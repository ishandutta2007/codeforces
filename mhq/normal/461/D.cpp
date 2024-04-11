#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) {
        return mult(a, pw(a, b - 1));
    }
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = (int)1e5 + 100;
int n, k;
int a[maxN], b[maxN];
int c[maxN];
vector < pair < int, int > > g[2 * maxN];
void add(int l, int r, int val) {
    // r >= l >= 2
    // r <= n + 1
    g[r].emplace_back(l - 2, val);
    g[l - 2].emplace_back(r, val);
}
bool used[maxN];
bool ALL_OK = true;
int clr[maxN];
void dfs(int v) {
    used[v] = true;
    for (auto to : g[v]) {
        if (!used[to.first]) {
            clr[to.first] = clr[v] ^ to.second;
            dfs(to.first);
        }
        else {
            if (clr[to.first] != clr[v] ^ to.second) {
                ALL_OK = false;
                break;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i] >> b[i];
        char cc;
        cin >> cc;
        if (cc == 'o') c[i] = 1;
        else c[i] = 0;
        b[i] = n + 1 - b[i];
        int s = a[i] + b[i];
        int p = a[i] - b[i];
        p = abs(p);
        if (s > n + 1) {
            s = 2 * n + 2 - s;
        }
        a[i] = (s + p) / 2;
        b[i] = (s - p) / 2;
        add(p + 2, s, c[i]);
    }
    int cmp = 0;
    for (int i = 0; i <= n + 1; i++) {
        if (!used[i]) {
            cmp++;
            dfs(i);
        }
    }
    if (!ALL_OK) {
        cout << 0;
        return 0;
    }
    cout << pw(2, cmp - 2);
    return 0;
}