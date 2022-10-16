#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
int n;
int dad[200005];
vector <int> child[200005];
long long f[200005][3];

void dfs(int u) {
    if (child[u].empty()) {
        f[u][2] = 1;
        f[u][0] = f[u][1] = 0;
        return;
    }
    long long all1 = 1, all2 = 1;
    vector <long long> pref;
    pref.push_back(all1);
    for (auto v: child[u]) {
        dfs(v);
        all1 = all1 * (f[v][0] + f[v][2]) % mod;
        all2 = all2 * ((f[v][0] + f[v][1] + f[v][2] * 2) % mod) % mod;
        pref.push_back(all1);
    }
    f[u][0] = all1;
    long long suff = 1;
    for (int i = child[u].size() - 1; i >= 0; --i) {
        int v = child[u][i];
        f[u][1] = (f[u][1] + pref[i] * (f[v][1] + f[v][2]) % mod * suff) % mod;
        suff = suff * (f[v][0] + f[v][2]) % mod;
    }
    f[u][2] = (all2 + mod - all1) % mod;
    f[u][2] = (f[u][2] + mod - f[u][1]) % mod;
    //cout << u << ' ' << f[u][0] << ' ' << f[u][1] << ' ' << f[u][2] << endl;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 2; i <= n; ++i) cin >> dad[i], child[dad[i]].push_back(i);
    dfs(1);
    cout << (f[1][0] + f[1][2]) % mod << endl;
    return 0;
}