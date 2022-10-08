
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
    vi a;
    dsu(int n) {
        a.assign(n, -1);
    }
    int trace(int x) {
        return a[x] < 0 ? x : a[x] = trace(a[x]);
    }
    void join(int x, int y) {
        if((x = trace(x)) == (y = trace(y))) return;
        if(a[x] > a[y]) swap(x, y);
        a[x] += a[y];
        a[y] = x;
    }
};

void solve() {
    int n; string s;
    cin >> n >> s;
    dsu D(2 * (n + 1));
    rep(i, 0, n) {
        if(s[i] == 'L') {
            D.join(n + 1 + i, i + 1);
        }else {
            D.join(i, n + 1 + i + 1);
        }
    }
    rep(i, 0, n + 1) {
        cout << -D.a[D.trace(i)] << ' ';
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