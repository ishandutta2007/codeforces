#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

ll a[N];
ll n, k, boost;
ll w[N];

priority_queue<ll> pq;
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> boost;

    for(int i = 1; i <= n; i++) cin >> w[i];

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        pq.push(-w[i]);
        while (!pq.empty() && k < a[i]) {
            k += boost;
            ans += -pq.top();
            pq.pop();
        }
        if (k < a[i]) {
            cout << -1;
            return 0;
        }
        //cout << k << " " << ans << " " << a[i] << '\n';
    }
    cout << ans;
}