#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ll n, m, k;
    cin >> n >> m >> k;
    ll x, s;
    cin >> x >> s;
    ll res = x * n;
    vector<ll> a(m);
    vector<ll> b(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (b[i] <= s)
            res = min(res, a[i] * n);
    }
    vector<ll> c(k);
    vector<ll> d(k);
    for (int i = 0; i < k; i++) 
        cin >> c[i];
    for (int i = 0; i < k; i++) {
        cin >> d[i];
        if (d[i] <= s)
            res = min(res, x * (n - c[i]));    
    }
    for (int i = 0; i < m; i++) {
        if (d[0] > s - b[i])      
            continue;
        int pos = upper_bound(d.begin(), d.end(), s - b[i]) - d.begin() - 1;
        res = min(res, (n - c[pos]) * a[i]); 
    }
    cout << res << endl;
}