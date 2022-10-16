#include <bits/stdc++.h>

using namespace std;

int n;
int a[300005];
int p[300005];
multiset <int> s;

int cal(int x) {
    int l = 0, r = 1 << 30;
    for (int i = 29; i >= 0; --i) {
        int bit = x >> i & 1;
        int m = l + r >> 1;
        if (bit) {
            if (s.lower_bound(m) == s.lower_bound(r)) r = m;
            else l = m;
        }
        else {
            if (s.lower_bound(m) == s.lower_bound(l)) l = m;
            else r = m;
        }
    }
    return l;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) s.insert(p[i]);
    for (int i = 1; i <= n; ++i) {
        int r = cal(a[i]);
        a[i] ^= r;
        s.erase(s.find(r));
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << endl;
}