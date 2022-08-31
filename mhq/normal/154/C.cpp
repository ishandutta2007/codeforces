#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e6 + 100;
const int T = 2;
const int mods[] = {(int)1e9 + 7, (int)1e9 + 9};
int sum(int a, int b, int mod) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b, int mod) {
    return (1LL * a * b) % mod;
}
map < pair < int, int >, int > hsh1, hsh2;
int n, m;
vector < int > g[maxN];
int pw[T][maxN];
int pt[T];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < T; i++) {
        pt[i] = rand() % 228 + 3173;
        pw[i][0] = 1;
        for (int j = 1; j < maxN; j++) pw[i][j] = mult(pw[i][j - 1], pt[i], mods[i]);
    }
    for (int i = 1; i <= n; i++) {
        vector < int > hsh(T, 0);
        for (auto it : g[i]) {
            for (int j = 0; j < T; j++) hsh[j] = sum(hsh[j], pw[j][it], mods[j]);
        }
        hsh1[make_pair(hsh[0], hsh[1])]++;
        for (int j = 0; j < T; j++) hsh[j] = sum(hsh[j], pw[j][i], mods[j]);
        hsh2[make_pair(hsh[0], hsh[1])]++;
    }
    ll ans = 0;
    for (auto it : hsh1) ans += (1LL * it.second * (it.second - 1)) / 2;
    for (auto it : hsh2) ans += (1LL * it.second * (it.second - 1)) / 2;
    cout << ans;
    return 0;
}