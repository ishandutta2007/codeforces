
#pragma GCC optimize("Ofast")
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

const int X = 2e7 + 5;
int pr[X];

void solve() {
    ll c, d, x;
    cin >> c >> d >> x;
    ll ans = 0;
    auto check = [&](ll g) {
        ll p = x / g + d;
        if(p % c != 0) return;
        p /= c;
        ans += (1LL << pr[p]);
    };
    for(ll i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            check(i);
            if(i * i != x) check(x / i);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i, 2, X) {
        if(pr[i] == 0) {
            for(int j = i; j < X; j += i) {
                pr[j]++;
            }
        }
    }

    int te;
    cin >> te;
    while(te--) solve();
}