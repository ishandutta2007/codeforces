#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = (ll) 2e18;
const int N = (int) 2e5 + 10;

int n, k;
ll B, C;
ll a[N];
multiset<ll> q;
ll curSum = 0;

void init() {
    curSum = 0;
    q.clear();
}

void add(ll x) {    
    q.insert(-x);
    curSum += x;
    auto it = q.end();
    if (q.size() > k) {
        it--;
        curSum += *it;
        q.erase(it);
    }
}

ll solve(ll rem) {
    ll res = INF;
    vector<pll> values(n);
    for (int i = 0; i < n; i++) {
        ll r = ((rem - a[i]) % 5 + 5) % 5;
        ll q = a[i] + r;
        assert (q >= a[i] && q - 5 < a[i] && (rem - q) % 5 == 0);
        values[i] = pll(q, q * B - C * r * 5);
    }
    sort(values.begin(), values.end());
    init();
    for (int i = 0; i < values.size(); i++) {
        add(values[i].second);
        ll ans = values[i].first;
        if (q.size() == k)
            res = min(res, k * B * ans - curSum);
    }                       
    assert (res % 5 == 0);
    return res / 5;
}

ll solve0() {
    ll res = INF;
    sort(a, a + n);
    init();
    for (int i = 0; i < n; i++) {
        add(C * a[i]);
        if (q.size() == k)
            res = min(res, k * C * a[i] - curSum); 
    }    
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> B >> C;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll res = solve0();
    //cerr << res << endl;
    for (int r = 0; r < 5; r++)
        res = min(res, solve(r));
    cout << res << endl;
    return 0;
}