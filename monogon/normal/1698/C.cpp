
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
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    if(a[2] < 0 || a[n - 3] > 0) {
        cout << "NO\n";
        return;
    }
    int e = 0;
    rep(i, 0, n) {
        if(i < 2 || a[i] != 0 || a[i - 2] != 0) {
            a[e++] = a[i];
        }
    }
    a.erase(e + all(a));
    n = sz(a);
    rep(i, 0, n) rep(j, i + 1, n) rep(k, j + 1, n) {
        if(!binary_search(all(a), a[i] + a[j] + a[k])) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}