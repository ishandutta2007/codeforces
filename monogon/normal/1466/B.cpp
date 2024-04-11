
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
    vector<int> a(n);
    vector<bool> vis(2 * n + 5);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    int cnt = 0;
    rep(i, 0, n) {
        if(vis[a[i]]) {
            a[i]++;
        }
        if(!vis[a[i]]) cnt++;
        vis[a[i]] = true;
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}