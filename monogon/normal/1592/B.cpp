
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = (a); i < (b); i++)

void solve() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    vi b(all(a));
    sort(all(b));
    rep(i, 0, n) {
        if(a[i] != b[i] && i - x < 0 && i + x >= n) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int te;
    cin >> te;
    while(te--) solve();
}