
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
    ll x = 0;
    rep(i, 0, n) {
        cin >> a[i];
        x ^= a[i];
    }
    if(x == 0) {
        cout << "YES\n";
        return;
    }
    int idx = 0;
    ll p = 0;
    while(idx < n) {
        p ^= a[idx];
        if(p == x) break;
        idx++;
    }
    int jdx = n - 1;
    ll s = 0;
    while(jdx >= 0) {
        s ^= a[jdx];
        if(s == x) break;
        jdx--;
    }
    cout << (idx + 1 < jdx ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}