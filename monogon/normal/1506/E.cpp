
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
    vi q(n), pmin(n), pmax(n);
    rep(i, 0, n) cin >> q[i];
    vector<bool> used(n + 1, false);
    int id = 1;
    rep(i, 0, n) {
        if(i == 0 || q[i] > q[i - 1]) {
            used[q[i]] = true;
            pmin[i] = q[i];
        }else {
            while(used[id]) id++;
            used[id] = true;
            pmin[i] = id;
        }
    }

    vi nxt(n + 1, 0), prv(n + 1, 0);
    rep(i, 0, n + 1) nxt[i] = max(0, i - 1);
    rep(i, 0, n + 1) prv[i] = min(i + 1, n);
    int val = 1;
    rep(i, 0, n) {
        if(i == 0 || q[i] > q[i - 1]) {
            pmax[i] = q[i];
            val = nxt[q[i]];
        }else {
            pmax[i] = val;
            val = nxt[val];
        }
        nxt[prv[pmax[i]]] = nxt[pmax[i]];
        prv[nxt[pmax[i]]] = prv[pmax[i]];
    }

    rep(i, 0, n) cout << pmin[i] << ' ';
    cout << '\n';
    rep(i, 0, n) cout << pmax[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}