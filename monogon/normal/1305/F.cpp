
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5, K = 500;
int n;
ll a[N];
mt19937 mt(98238932);

ll solve(ll p) {
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < p) cnt += p - a[i];
        else cnt += min(a[i] % p, p - (a[i] % p));
    }
    return cnt;
}

int rand(int l, int r) {
    uniform_int_distribution<int> uni(l, r);
    return uni(mt);
}

ll solve2(ll x) {
    ll ans = n;
    for(ll j = 2; j * j <= x; j++) {
        if(x % j == 0) {
            ans = min(ans, solve(j));
            while(x % j == 0) x /= j;
        }
    }
    if(x > 1) {
        ans = min(ans, solve(x));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = n;
    for(int k = 0; k < 30; k++) {
        int i = rand(0, n - 1);
        ll x = a[i];
        ans = min(ans, solve2(x));
        ans = min(ans, solve2(x + 1));
        if(x > 1) ans = min(ans, solve2(x - 1));
    }
    cout << ans << endl;
}