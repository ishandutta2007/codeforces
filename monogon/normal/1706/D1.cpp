
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
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    int cost = INT_MAX;
    rep(mi, 0, 3001) {
        // a / p >= mi
        // a >= mi p
        // p <= a / mi
        int mx = 0;
        bool bad = false;
        rep(i, 0, n) {
            int p = mi == 0 ? k : min(k, a[i] / mi);
            if(p == 0) {
                bad = true;
                break;
            }
            mx = max(mx, a[i] / p);
        }
        if(bad) continue;
        cost = min(cost, mx - mi);
    }
    cout << cost << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}