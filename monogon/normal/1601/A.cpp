
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

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vi cnt(31, 0);
    rep(i, 0, n) {
        cin >> a[i];
        rep(j, 0, 31) {
            if(a[i] >> j & 1) {
                cnt[j]++;
            }
        }
    }
    ll g = 0;
    rep(i, 0, 31) g = gcd(g, (ll) cnt[i]);
    rep(i, 1, n + 1) {
        if(i <= n && g % i == 0) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}