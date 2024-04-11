
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

ll lcm(ll a, ll b) {
    return a * (b / gcd(a, b));
}

// let g(i) = how many multiples of lcm(1, 2, ..., i) between 1 and n
// h(i) = how many numbers j in [1, n] have f(j) = i
// g(i) = suffix sum of h(i)
// ans = h(1) 2 + h(2) 3 + ...

const int M = 1e9 + 7;
void solve() {
    ll n;
    cin >> n;
    ll x = 1;
    vector<ll> g(41);
    rep(i, 1, 41) {
        x = lcm(x, i);
        g[i] = n / x;
    }
    ll ans = 0;
    g.push_back(0);
    rep(i, 1, 41) {
        ans = (ans + (g[i] - g[i + 1]) * (i + 1)) % M;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}