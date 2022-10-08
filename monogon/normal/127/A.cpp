
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

using ftype = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n);
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
    }
    ftype ans = 0;
    rep(i, 1, n) {
        ans += hypotl(x[i] - x[i - 1], y[i] - y[i - 1]);
    }
    cout << fixed << setprecision(8);
    cout << (ans * k / 50) << '\n';
}