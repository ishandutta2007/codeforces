#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> b(n);
    vector<ll> c(n);
    for (int i = 0; i < n; i++) 
        cin >> b[i]; 
    for (int i = 0; i < n; i++) 
        cin >> c[i];
    ll tot = (accumulate(b.begin(), b.end(), 0ll) + accumulate(c.begin(), c.end(), 0ll)) / (2 * n);        
    vector<ll> a(n);
    vector<ll> at_bit(31);
    for (int i = 0; i < n; i++) {
        a[i] = max(0ll, (b[i] + c[i] - tot) / n);
        for (int j = 0; j < 31; j++)
            at_bit[j] += (a[i] & (1ll << j));
    }
    for (int i = 0; i < n; i++) {
        ll cur_b = 0;
        ll cur_c = 0;
        for (int j = 0; j < 31; j++)
            if (a[i] & (1ll << j)) {
                cur_b += at_bit[j];
                cur_c += n * (1ll << j);           
            } else {
                cur_c += at_bit[j];
            }
        if (b[i] != cur_b || c[i] != cur_c) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int x : a)
        cout << x << " ";
    cout << endl;
}