
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
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    int x = -1, y = -1;
    rep(i, 0, n) {
        if(a[i] != a[n - i - 1]) {
            x = a[i];
            y = a[n - i - 1];
            break;
        }
    }
    if(x == -1) {
        cout << "YES\n";
        return;
    }
    vi b, c;
    rep(i, 0, n) {
        if(a[i] != x) b.push_back(a[i]);
        if(a[i] != y) c.push_back(a[i]);
    }
    bool ok = true;
    rep(i, 0, sz(b)) {
        if(b[i] != b[sz(b) - i - 1]) ok = false;
    }
    if(ok) {
        cout << "YES\n";
        return;
    }
    ok = true;
    rep(i, 0, sz(c)) {
        if(c[i ]!= c[sz(c) - i  -1]) ok = false;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}