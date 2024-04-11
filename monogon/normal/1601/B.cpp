
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
        a.resize(n);
        rep(i, 0, n) a[i] = i;
    }
    int find(int x) {
        return (a[x] == x ? x : a[x] = find(a[x]));
    }
    void join(int x, int y) {
        if((x = find(x)) == (y = find(y))) return;
        a[x] = y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    rep(i, 1, n + 1) {
        cin >> b[i];
    }
    dsu D(n + 2);
    queue<int> Q;
    vi dist(n + 1, -1);
    vi par(n + 1, 0);
    Q.push(n);
    dist[n] = 0;
    D.join(n, n + 1);
    while(!Q.empty()) {
        int i = Q.front(); Q.pop();
        if(i == 0) break;
        int l = i + b[i] - a[i + b[i]];
        int r = i + b[i] + b[i + b[i]];
        while(true) {
            l = D.find(l);
            if(l > r) break;
            dist[l] = 1 + dist[i];
            par[l] = i;
            Q.push(l);
            D.join(l, l + 1);
        }
    }
    if(dist[0] == -1) {
        cout << -1 << '\n';
        return 0;
    }
    cout << dist[0] << '\n';
    vi ve;
    int x = 0;
    while(x != n) {
        ve.push_back(x);
        x = par[x];
    }
    reverse(all(ve));
    for(int x : ve) cout << x << ' ';
    cout << '\n';
}