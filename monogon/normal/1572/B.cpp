
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
    vi a(n + 1);
    int p = 0;
    rep(i, 1, n + 1) {
        cin >> a[i];
        a[i] ^= a[i - 1];
        if(i % 2 == 1 && a[i] == 0) p = i;
    }
    if(a[n] != 0 || p == 0) {
        cout << "NO\n";
        return;
    }
    vi op;
    for(int i = 1; i + 2 <= p; i += 2) op.push_back(i);
    for(int i = p - 2; i >= 1; i -= 2) op.push_back(i);
    for(int i = p + 1; i + 2 <= n; i += 2) op.push_back(i);
    for(int i = n - 2; i >= p + 1; i -= 2) op.push_back(i);
    cout << "YES\n";
    cout << sz(op) << '\n';
    for(int x : op) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}