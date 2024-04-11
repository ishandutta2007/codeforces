
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
    vector<ll> h(n);
    rep(i, 0, n) cin >> h[i];
    sort(all(h));
    int idx = 0;
    rep(i, 0, n - 1) {
        if(h[i + 1] - h[i] < h[idx + 1] - h[idx]) {
            idx = i;
        }
    }
    rotate(h.begin(), h.begin() + idx + 1, h.end());
    if(n == 2) swap(h[0], h[1]);
    for(int x : h) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}