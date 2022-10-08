
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

struct dsu {
    vector<int> a;
    dsu(int n) {
        a.assign(n, -1);
    }
    int find(int x) {
        return a[x] < 0 ? x : a[x] = find(a[x]);
    }
    int size(int x) {
        return -a[find(x)];
    }
    bool join(int x, int y) {
        if((x = find(x)) == (y = find(y))) return false;
        if(a[x] > a[y]) swap(x, y);
        a[x] += a[y];
        a[y] = x;
        return true;
    }
};
const int M = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    dsu D(n + 1);
    vi a(n + 1);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) {
        int b;
        cin >> b;
        D.join(a[i], b);
    }
    ll ans = 1;
    rep(i, 1, n + 1) if(D.find(i) == i) {
        ans = (2 * ans) % M;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te = 1;
    cin >> te;
    while(te--) solve();
}