
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
    ll s = 0;
    rep(i, 0, n) {
        cin >> a[i];
        s += a[i];
    }
    if(s % n != 0) {
        cout << -1 << "\n";
        return;
    }
    s /= n;
    int cnt = 0;
    rep(i, 0, n) if(a[i] > s) cnt++;
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}