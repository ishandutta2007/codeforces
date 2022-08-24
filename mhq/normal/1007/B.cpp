#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 10;
int d[maxN];
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}
ll cnk(int n, int k) {
    if (n < k) return 0;
    ll ans = 1;
    for (int i = n; i >= (n - k + 1); i--) ans *= i;
    for (int i = 1; i <= k; i++) ans /= i;
    return ans;
}
int p[3];
int a[3];
ll f[10];
int st[3];
bool ok[10][10][10];
int bits[20];
bool check(int mask1, int mask2, int mask3) {
    st[0] = mask1;
    st[1] = mask2;
    st[2] = mask3;
    for (int i = 0; i < 3; i++) p[i] = i;
    do{
        bool ok = true;
        for (int j = 0; j < 3; j++) {
            if (st[p[j]] & (1 << j)) {}
            else {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    } while(next_permutation(p, p + 3));
    return false;
}
void solve() {
    for (int i = 0; i < 3; i++) cin >> a[i];
    vector < int > all;
    for (int i = 0; i < 8; i++) f[i] = 0;
    for (int mask = 1; mask < 8; mask++) {
        all.clear();
        int in = -1;
        ll out = -1;
        for (int j = 0; j < 3; j++) {
            if (mask & (1 << j)) {
                if (in != -1) in = gcd(in, a[j]);
                else in = a[j];
            }
            else {
                all.push_back(j);
            }
        }
        for (int mask2 = 0; mask2 < (1 << all.size()); mask2++) {
            int cnt = in;
            for (int i = 0; i < all.size(); i++) {
                if (mask2 & (1 << i)) cnt = gcd(cnt, a[all[i]]);
            }
            if (bits[mask2] % 2 == 0) f[mask] += d[cnt];
            else f[mask] -= d[cnt];
        }
    }
    ll ans = 0;
    for (int mask1 = 1; mask1 < 8; mask1++) {
        for (int mask2 = mask1; mask2 < 8; mask2++) {
            for (int mask3 = mask2; mask3 < 8; mask3++) {
                if (ok[mask1][mask2][mask3]) {
                    ll cur = 1;
                    if (mask1 != mask2) {
                        cur *= f[mask1];
                        if (mask2 != mask3) {
                            cur *= f[mask2];
                            cur *= f[mask3];
                        }
                        else cur *= cnk(f[mask2] + 1, 2);
                    }
                    else if (mask1 != mask3) {
                        cur *= cnk(f[mask1] + 1, 2);
                        cur *= f[mask3];
                    }
                    else cur *= cnk(f[mask1] + 2, 3);
                    ans += cur;
                }
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                ok[i][j][k] = check(i, j, k);
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            if (i & (1 << j)) bits[i]++;
        }
    }
    for (int i = 0; i < 3; i++) p[i] = i;
    int k = 0;
    for (int i = 1; i < maxN; i++) {
        for (int j = i; j < maxN; j += i) d[j]++;
    }
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}