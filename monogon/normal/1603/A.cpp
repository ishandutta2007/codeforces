
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
    rep(i, 0, n) {
        cin >> a[i];
    }
    int mx = min(25, n);
    rep(i, 0, mx) {
        bool ok = false;
        rep(j, 0, min(mx, i + 1)) {
            if((a[i] % (j + 2)) != 0)
            {
                ok = true;
            }
        }
        if(!ok) {
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