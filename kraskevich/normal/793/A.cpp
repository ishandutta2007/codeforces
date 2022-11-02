#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll mn = *min_element(a.begin(), a.end());
    ll res = 0;
    for (ll x : a) {
        x -= mn;
        if (x % k) {
            cout << -1 << endl;
            return 0;
        }
        res += x / k;
    }
    cout << res << endl;
}