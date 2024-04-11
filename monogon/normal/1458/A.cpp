
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    ll g = 0;
    rep(i, 0, n) {
        cin >> a[i];
        if(i > 0) {
            g = gcd(g, a[i] - a[0]);
        }
    }
    rep(i, 0, m) {
        cin >> b[i];
        cout << gcd(g, a[0] + b[i]) << ' ';
    }
    cout << '\n';
}