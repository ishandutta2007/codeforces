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

const int N = 1e5 + 5;
int n, m, u, v, deg[N], ti[N];
vi adj[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, m) {
        cin >> u >> v;
        adj[v].push_back(u);
        deg[u]++;
    }
    priority_queue<int> Q;
    rep(i, 1, n + 1) {
        if(deg[i] == 0) Q.push(i);
    }
    int t = n;
    while(!Q.empty()) {
        int x = Q.top(); Q.pop();
        ti[x] = t--;
        for(int y : adj[x]) {
            deg[y]--;
            if(deg[y] == 0) {
                Q.push(y);
            }
        }
    }
    rep(i, 1, n + 1) {
        cout << ti[i] << ' ';
    }
    cout << '\n';
}