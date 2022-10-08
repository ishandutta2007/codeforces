
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
    vi b(n + 1), p(n + 1);
    rep(i, 1, n + 1) cin >> b[i];
    rep(i, 1, n + 1) cin >> p[i];

    vector<bool> vis(n + 1, false);
    vector<ll> w(n + 1);

    if(b[p[1]] != p[1]) {
        cout << -1 << '\n';
        return;
    }
    vis[p[1]] = true;
    vi dist(n + 1);
    dist[p[1]] = 0;
    rep(i, 2, n + 1) {
        if(!vis[b[p[i]]]) {
            cout << -1 << '\n';
            return;
        }
        w[p[i]] = i - dist[b[p[i]]];
        dist[p[i]] = i;
        vis[p[i]] = true;
    }

    rep(i, 1, n + 1) {
        cout << w[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}