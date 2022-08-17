#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;


vector<ll> del(ll n) {
    vector<ll> ans;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ans.PB(i);
            n /= i;
            --i;
        }
    }
    return ans;
}

ll maxdel(ll n) {
    ll ans = -1;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ans = max(ans, i);
            n /= i;
            --i;
        }
    }
    ans = max(ans, n);
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int maxd = maxdel(n);
    //cout << maxd << endl;
    ll ans = n + 10;
    for (int prev = n - maxd + 1; prev <= n; ++prev) {
        ll prev1 = maxdel(prev);
        if (prev1 == prev) continue;
        ans = min(ans, prev - prev1 + 1);
    }
    cout << ans;
    return 0;
}