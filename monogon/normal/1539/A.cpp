
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

/*
i: next floor(t/x) participants start
sum_i min(n - i, floor(t/x))

sum_{i <= n - floor(t/x)} floor(t/x)
sum_{ floor(t/x) > n - i >= 0}  n - i
*/

void solve() {
    ll n, x, t;
    cin >> n >> x >> t;
    ll ans = 0;
    ans += (t / x) * max(0LL, n - (t / x));
    ll b = max(0LL, (t / x) - 1);
    b = min(b, n - 1);
    ans += b * (b + 1) / 2;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}