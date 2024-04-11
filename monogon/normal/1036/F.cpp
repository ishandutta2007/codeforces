
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
ll l = 2, r;
int p[62];

inline ll kthroot(ll x, ll k) {
    ll v = powl(x, ((long double) 1.0) / k) + 1;
    while(powl(v, k) > x) {
        v--;
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    p[1] = 0;
    for(int i = 2; i <= 61; i++) {
        p[i] = -1;
        int x = i;
        for(int j = 2; j * j <= x; j++) {
            if(i % j == 0) {
                x /= j;
                p[i] = -p[i];
                while(x % j == 0) {
                    p[i] = 0;
                    x /= j;
                }
            }
        }
        if(x > 0) {
            p[i] = -p[i];
        }
    }
    while(q--) {
        cin >> r;
        ll ans = 0;
        if(l == 1) {
            ans++;
            l++;
        }
        for(int k = 2; k <= 61; k++) {
            ll dif = kthroot(r, k) - kthroot(l - 1, k);
            ans += p[k] * dif;
        }
        cout << (r - 1 - ans) << '\n';
    }
}