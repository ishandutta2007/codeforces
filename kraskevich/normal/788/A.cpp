#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

ll mabs(ll a) {
    return a > 0 ? a : -a;
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll res = 0;
    vector<ll> b(n - 1);
    for (int i = 0; i < n - 1; i++)
        b[i] = mabs(a[i + 1] - a[i]);
    for (int p = 0; p < 2; p++) {
        ll pref = 0;
        ll cur = 0;
        for (int i = p; i < n - 1; i++) {
            if (i % 2 == p)
                cur += b[i];
            else
                cur -= b[i];
            res = max(res, cur - pref);
            if (i % 2 != p)
                pref = min(pref, cur);
        }
    }
    cout << res << endl;
}