
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;
int n, m, t[N];
vi adj[N];
int dsu[N];
int ans = 0;

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}

void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(sz(adj[x]) < sz(adj[y])) swap(x, y);
    for(int z : adj[y]) {
        if(trace(z) == x) ans--;
        else adj[x].push_back(z);
    }
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    rep(i, 0, m) {
        cin >> t[i];
        if(i > 0 && t[i] != t[i - 1]) {
            adj[t[i - 1]].push_back(t[i]);
            adj[t[i]].push_back(t[i - 1]);
            ans++;
        }
    }
    fill(dsu, dsu + N, -1);
    cout << ans << '\n';
    rep(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        join(a, b);
        cout << ans << '\n';
    }
}