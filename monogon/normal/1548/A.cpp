
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
    int n, m;
    cin >> n >> m;
    vi cnt(n + 1, 0);
    int ans = n;
    auto add = [&](int u, int v) {
        if(u > v) swap(u, v);
        if(cnt[u] == 0) ans--;
        cnt[u]++;
    };
    auto rem = [&](int u, int v) {
        if(u > v) swap(u, v);
        cnt[u]--;
        if(cnt[u] == 0) ans++;
    };
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    int q; cin >> q;
    while(q--) {
        int ty, u, v;
        cin >> ty;
        if(ty == 1) {
            cin >> u >> v;
            add(u, v);
        }else if(ty == 2) {
            cin >> u >> v;
            rem(u, v);
        }else {
            cout << ans << '\n';
        }
    }
}