
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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a), greater<>());
    ll s = 0;
    rep(i, 0, n) {
        if(i % 2 == 0) {
            s += a[i] * a[i];
        }else {
            s -= a[i] * a[i];
        }
    }
    using ftype = long double;
    const ftype pi = acosl(-1);
    cout << fixed << setprecision(10);
    cout << pi * s << '\n';
}