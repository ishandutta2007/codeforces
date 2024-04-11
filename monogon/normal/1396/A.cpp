
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
    vector<ll> a(n + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << "1 1 " << '\n' << -a[1] << '\n';
        cout << "1 1 " << '\n' << a[1] << '\n';
        cout << "1 1 " << '\n' << -a[1] << '\n';
        return 0;
    }
    cout << 1 << ' ' << n - 1 << '\n';
    rep(i, 1, n) {
        cout << a[i] * (n - 1) << ' ';
    }
    cout << '\n';
    cout << 2 << ' ' << n << '\n';
    rep(i, 2, n) {
        cout << 0 << ' ';
    }
    cout << a[n] * (n - 1) << '\n';
    cout << 1 << ' ' << n << '\n';
    rep(i, 1, n + 1) {
        cout << -a[i] * n << ' ';
    }
    cout << '\n';
}