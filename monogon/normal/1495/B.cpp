
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi p(n);
    rep(i, 0, n) cin >> p[i];
    vector<bool> vis(n, false);
    vi le(n, 0), ri(n, 0);
    function<void(int)> dfs = [&](int x) {
        vis[x] = true;
        if(x > 0 && !vis[x - 1] && p[x - 1] < p[x]) {
            dfs(x - 1);
        }
        if(x > 0 && p[x - 1] < p[x]) le[x] = 1 + le[x - 1];
        if(x < n - 1 && !vis[x + 1] && p[x + 1] < p[x]) {
            dfs(x + 1);
        }
        if(x < n - 1 && p[x + 1] < p[x]) ri[x] = 1 + ri[x + 1];
    };
    rep(i, 0, n) {
        if(!vis[i]) dfs(i);
    }
    // rep(i, 0, n) {
    //     cout << le[i] << ' ' << ri[i] << "\n";
    // }
    int idx = max_element(all(le)) - le.begin();
    int jdx = max_element(all(ri)) - ri.begin();
    if(ri[jdx] > le[idx]) idx = jdx;
    rep(i, 0, n) {
        if(i == idx) continue;
        if(max(le[i], ri[i]) >= max(le[idx], ri[idx])) {
            cout << 0 << '\n';
            return 0;
        }
    }
    int a = le[idx], b = ri[idx];
    if(a > b) swap(a, b);
    if(b % 2 == 1 || b > a) {
        cout << 0 << '\n';
    }else {
        cout << 1 << '\n';
    }
}