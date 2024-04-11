
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

// bfs from each police station
// delete edges covered by different police stations
// ignore multiple police stations in the same city

const int N = 3e5 + 5;
int n, k, d, p[N], u[N], v[N], station[N];
vi adj[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> d;
    queue<int> Q;
    rep(i, 0, k) {
        cin >> p[i];
        if(!station[p[i]]) {
            station[p[i]] = p[i];
            Q.push(p[i]);
        }
    }
    int cnt = sz(Q);
    rep(i, 0, n - 1) {
        cin >> u[i] >> v[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int y : adj[x]) {
            if(!station[y]) {
                station[y] = station[x];
                Q.push(y);
            }
        }
    }
    cout << cnt - 1 << '\n';
    rep(i, 0, n - 1) {
        if(station[u[i]] != station[v[i]]) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
}