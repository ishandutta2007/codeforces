#include <bits/stdc++.h>

typedef long long ll;

const int INF = 2e9;
const int mod = 1e9 + 7;

using namespace std;

ll pw(ll n, ll d) {
    ll ans = 1;
    for(int i = 30; i >= 0; --i) {
        ans *= ans, ans %= mod;
        if((1 << i) & d)
            ans *= n, ans %= mod;
    }
    return ans;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if(k > n) {
        printf("%I64d\n", pw(m, n));
        return;
    }
    if(k == 1) {
        printf("%I64d", pw(m, n));
        return;
    }
    if(n == 1) {
        printf("%d", m);
        return;
    }
    if(k == n) {
        cout << pw(m, (n + 1) / 2);
        return;
    }
    if(k % 2 == 0) {
        printf("%d", m);
        return;
    }
    printf("%I64d", pw(m, 2));
}

int main() {
    solve();
    return 0;
}