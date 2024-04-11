
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
    vi nxt(n);
    rep(i, 0, n) cin >> a[i];
    queue<int> Q;
    rep(i, 0, n) {
        nxt[i] = (i + 1) % n;
        Q.push(i);
    }
    vector<bool> del(n, false);
    vi ans;
    while(!Q.empty()) {
        int i = Q.front(); Q.pop();
        if(del[i]) continue;
        if(gcd(a[i], a[nxt[i]]) == 1) {
            ans.push_back(nxt[i] + 1);
            Q.push(i);
            del[nxt[i]] = true;
            nxt[i] = nxt[nxt[i]];
        }
    }
    cout << sz(ans);
    for(int x : ans) cout << ' ' << x;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}