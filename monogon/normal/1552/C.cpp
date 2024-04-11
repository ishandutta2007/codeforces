
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
    vector<pii> ve;
    vi vis(2 * n, 0);
    rep(i, 0, k) {
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        a--; b--;
        vis[a] = i + 1;
        vis[b] = i + 1;
        ve.push_back({a, b});
    }
    vi pos;
    rep(i, 0, 2 * n) if(!vis[i]) pos.push_back(i);
    int K = sz(pos);
    rep(i, 0, K / 2) {
        int a = pos[i], b = pos[i + K / 2];
        vis[a] = vis[b] = k + i + 1;
        ve.push_back({a, b});
    }
    int cnt = 0;
    vector<bool> s(n + 1, false);
    rep(i, 0, sz(ve)) {
        int a, b;
        tie(a, b) = ve[i];
        int j = (a + 1) % (2 * n);
        fill(all(s), false);
        while(j != b) {
            s[vis[j]] = !s[vis[j]];
            j = (j + 1) % (2 * n);
        }
        int num = 0;
        rep(j, 1, n + 1) num += s[j];
        cnt += num;
    }
    cout << cnt / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}