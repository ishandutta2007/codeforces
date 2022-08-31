#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = 2 * (int)1e5 + 100;
int a[maxN];
ll pref[maxN];
const int maxK = 70;
ll all[maxK];
int bit_for[maxK];
int sz = 0;
bool try_to_add(ll x) {
    if (x == 0) return false;
    ll cop = x;
    for (int j = 0; j < sz; j++) {
        if (cop & (1LL << bit_for[j])) {
            cop ^= all[j];
        }
    }
    if (cop == 0) return false;
    for (int j = 0; j <= 62; j++) {
        if (cop & (1LL << j)) {
            bit_for[sz] = j;
            break;
        }
    }
    all[sz] = cop;
    for (int j = 0; j < sz; j++) {
        if (all[j] & (1LL << bit_for[sz])) {
            all[j] ^= all[sz];
        }
    }
    sz++;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pref[i] = pref[i - 1] ^ x;
    }
    if (pref[n] == 0) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        if (try_to_add(pref[i])) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}