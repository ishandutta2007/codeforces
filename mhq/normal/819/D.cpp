#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int mod;
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
void reduce(pair < ll, ll >& t, ll a, ll b) {
    ll shift = (-t.first) / b;
    t.first += shift * b;
    t.second -= shift * a;
}
pair < ll, ll > euclid(ll a, ll b) {
    if (a == 0) return make_pair(0, 1);
    else if (b == 0) return make_pair(1, 0);
    else {
        if (a < b) {
            auto t = euclid(b, a);
            return make_pair(t.second, t.first);
        }
        else {
            auto t = euclid(a % b, b);
            t.second -= t.first * (a / b);
            reduce(t, a, b);
            return t;
        }
    }
}
ll find_inv(ll a, ll mod) {
    auto t = euclid(a, mod);
    reduce(t, a, mod);
    while (t.first < mod) t.first += mod;
    while (t.first >= mod) t.first -= mod;
    return t.first;
}
const int maxN = 2 * (int)1e5 + 10;
int n;
int a[maxN];
int b[maxN];
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
int d, S;
int ans[maxN];
void solve(vector < int > all) {
    //cout << "solving " << all.size() << endl;
    int coef = S / d;
    vector < int > uni;
    map < int, bool > mp;
    for (int v : all) {
        b[v] /= d;
        b[v] %= mod;
        if (mp.count(b[v])) continue;
        mp[b[v]] = true;
        uni.push_back(v);
    }
    all = uni;
    /*for (int v : all) {
        cout << v << " " << b[v] << endl;
    }*/
    int m = all.size();
    //cout << m << endl;
    if (m == 1) {
        ans[all[0]] = mod;
        return ;
    }
    vector < pair < int, int > > delta(m);
    delta[0] = make_pair(0, all[0]);
    int inv_s = find_inv(coef, mod);
    //cout << "deltas " << endl;
    for (int i = 1; i < m; i++) {
        int ind = all[i];
        b[ind] = sub(b[ind], b[all[0]]);
        int t = sub(0, b[ind]);
        delta[i] = make_pair(mult(t, inv_s), ind);
    }
    sort(delta.begin(), delta.end());

    for (int i = 0; i < mod; i++) {
        int val = (i + 15) % mod;
        bool ok = true;
        for (int j = 0; j < m; j++) {
            int x = (delta[j].first + i) % mod;
            if (x < val) {
                ok = false;
                break;
            }
        }
     //   if (ok) cout << i << " HERE" << endl;
    }
    for (int i = 0; i < m; i++) {
     //   cout << delta[i].first << " " << delta[i].second << endl;
        int lim = mod - 1;
        if (i != m - 1) {
            lim = min(lim, sub(delta[i].first, delta[m - 1].first) - 1);
        }
        if (i != 0) {
            lim = min(lim, sub(delta[i].first, delta[i - 1].first) - 1);
        }
        if (lim >= 0) ans[delta[i].second] = lim + 1;
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> mod >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1];
        if (i >= 2) b[i] = sum(b[i], a[i] % mod);
    }
    S = sum(b[n], a[1] % mod);
    vector < pair < int, int > > all;
    d = gcd(S, mod);
    mod /= d;
    for (int i = 1; i <= n; i++) {
        all.push_back(make_pair(b[i] % d, i));
    }
    sort(all.begin(), all.end());
    int i = 0;
    while (i < all.size()) {
        vector < int > cur;
        int j = i;
        while (j < all.size() && all[j].first == all[i].first) j++; j--;
        for (int k = i; k <= j; k++) {
            cur.push_back(all[k].second);
        }
        solve(cur);
        i = j + 1;
    }
    for (int it = 1; it <= n; it++) cout << ans[it] << " ";
    return 0;
}