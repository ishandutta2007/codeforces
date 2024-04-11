#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

ll calc(ll n, ll k) {
    ll r = n % k;
    ll x = n / k;
    return r * (x + 1) * (x + 1) + (k - r) * x * x;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n), c(n, 1);
    multiset<pair<ll, int>> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        q.insert({calc(a[i], c[i] + 1) - calc(a[i], c[i]), i});
    }

    for (int iter = 0; iter < k - n; iter++) {
        auto [_, i] = *q.begin();
        q.erase(q.begin());
        c[i]++;
        q.insert({calc(a[i], c[i] + 1) - calc(a[i], c[i]), i});
    }

    ll res = 0;
    for (int i = 0; i < n; i++)
        res += calc(a[i], c[i]);

    cout << res << "\n";

    return 0;
}