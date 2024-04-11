
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
    ll k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i, 0, n) cin >> h[i];
    while(k > 0) {
        int idx = 0;
        while(idx < n - 1 && h[idx] >= h[idx + 1]) {
            idx++;
        }
        if(idx == n - 1) {
            cout << -1 << '\n';
            return;
        }
        k--;
        h[idx]++;
        if(k == 0) {
            cout << idx + 1 << '\n';
            return;
        }
    }
    assert(false);
    // cout << (1 + (n - k) % n) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}