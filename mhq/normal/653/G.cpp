#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
const int maxN = 3 * (int)1e5 + 10;
int t[maxN];
int fact[maxN], invfact[maxN];
int inv[maxN];
vector < int > primes[maxN];
vector < int > all_primes;
bool used[maxN];
const int maxLOG = 21;
int cnt[maxN][maxLOG];
void init() {
    fact[0] = 1;
    invfact[0] = 1;
    fact[1] = 1;
    invfact[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    for (int i = 2; i < maxN; i++) {
        if (!used[i]) {
            all_primes.push_back(i);
            for (int j = i; j < maxN; j += i) {
                primes[j].push_back(i);
                used[j] = true;
            }
        }
    }
}
int n;
int cnk(int n, int k) {
    if (n < k) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
int c[maxN];
int get_val[maxN];
int pref[maxN];
int ans = 0;
void solve(int p) {
    cnt[p][0] = n;
    for (int i = 1; i < maxLOG; i++) {
        cnt[p][0] -= cnt[p][i];
    }
    //if (n != cnt[p][0]) cout << p << " HER" << endl;
    int before = 0;
    for (int i = 0; i < maxLOG; i++) {
        int from = before + 1;
        int to = cnt[p][i] + before;
        if (to >= from) {
            ans = sum(ans, mult(i, sub(pref[to], pref[from - 1])));
           // cout << ans << endl;
        }
        before += cnt[p][i];
        if (before == n) return ;
    }
}
int pw2[maxN];
int pref_c[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n;
    pw2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pref_c[i] = sum(pref_c[i - 1], cnk(n - 1, i - 1));
        //cout << i << " " << c[i] << endl;
    }
    for (int i = 1; i <= n; i++) {
        get_val[i] = sub(pref_c[i], pref_c[n + 1 - i]);
        //cout << get_val[i] << " " << i << " " << endl;
        //if (get_val[i] < mod / 2) cout << get_val[i] << " " << i << endl;
        //else cout << get_val[i] - mod << " " << i << endl;
        pref[i] = sum(pref[i - 1], get_val[i]);
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        while (x > 1) {
            int t = primes[x][0];
            int exp = 0;
            while (x % t == 0) {
                exp++;
                x /= t;
            }
            cnt[t][exp]++;
        }
    }
    for (int v : all_primes) {
        solve(v);
    }
    cout << ans;
    return 0;
}