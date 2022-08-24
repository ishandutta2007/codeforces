#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2 * (int)1e5 + 10;
ll f[maxN];
int a[maxN];
int n;
map < ll, int > all;
int k;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    ll val = (1LL << (k)) - 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] ^ a[i];
    }
    for (int i = 0; i <= n; i++) {
        ll x = f[i];
        if (x < (val ^ x)) all[x]++;
        else all[val ^ x]++;
    }
    ll oth_ans = 0;
    ll ans = 0;
    for (auto t : all) {
        oth_ans += (1LL * t.second * (n + 1 - t.second));
        ans += (1LL * (t.second / 2)) * ((t.second + 1) / 2);
    }
    cout << (oth_ans / 2) + ans;
    return 0;
}