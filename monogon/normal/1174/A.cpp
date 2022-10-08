
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
    int n;
    cin >> n;
    vector<ll> a(2 * n);
    rep(i, 0, 2 * n) cin >> a[i];
    ll s = 0;
    rep(i, 0, n) s += a[i];
    rep(i, n, 2 * n) s -= a[i];
    if(s == 0) {
        rep(i, 0, n) rep(j, n, 2 * n) {
            if(a[i] != a[j]) {
                swap(a[i], a[j]);
                rep(k, 0, 2 * n) {
                    cout << a[k] << ' ';
                }
                cout << '\n';
                return 0;
            }
        }
        cout << -1 << '\n';
        return 0;
    }
    rep(i, 0, 2 * n) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}