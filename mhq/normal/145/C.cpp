#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = (int)1e5 + 100;
int fact[maxN], invfact[maxN], inv[maxN];
map < int, int > mp;
int n, k;
bool lucky(int x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) return false;
        x /= 10;
    }
    return true;
}
int cnk(int a, int b) {
    return mult(fact[a], mult(invfact[b], invfact[a - b]));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    fact[0] = invfact[0] = fact[1] = inv[1] = invfact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
        fact[i] = mult(i, fact[i - 1]);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    cin >> n >> k;
    int bad = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (lucky(x)) mp[x]++;
        else bad++;
    }
    vector < int > f;
    for (auto it : mp) f.push_back(it.second);
    vector < int > g(f.size() + 1);
    g[0] = 1;
    for (int v : f) {
        vector < int > ng(f.size() + 1, 0);
        for (int j = 0; j < g.size(); j++) {
            ng[j] = sum(ng[j], g[j]);
            if (j + 1 < g.size()) ng[j + 1] = sum(ng[j + 1], mult(g[j], v));
        }
        swap(g, ng);
    }
    int ans = 0;
    for (int i = 0; i < g.size(); i++) {
        if (i > k) break;
        int le = k - i;
        if (le > bad) continue;
        ans = sum(ans, mult(g[i], cnk(bad, le)));
    }
    cout << ans;
    return 0;
}