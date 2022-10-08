
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q, n;
ll m, t, l, h, L, R, t0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n >> m;
        L = R = m;
        t0 = 0;
        bool flag = true;
        for(int i = 0; i < n; i++) {
            cin >> t >> l >> h;
            L = max(L - (t - t0), l);
            R = min(R + (t - t0), h);
            if(R < L) flag = false;
            t0 = t;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}