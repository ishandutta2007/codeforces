
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int A = 205;
int t, a, b, q;
ll l, r, f[A * A];

ll pref(ll x) {
    ll ans = f[a * b] * (x / (a * b));
    x %= (a * b);
    return ans + f[x + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> q;
        for(int i = 1; i <= a * b; i++) {
            f[i] = f[i - 1];
            if(((i - 1) % a) % b != ((i - 1) % b) % a) {
                f[i]++;
            }
        }
        while(q--) {
            cin >> l >> r;
            cout << pref(r) - pref(l - 1) << ' ';
        }
        cout << '\n';
    }
}