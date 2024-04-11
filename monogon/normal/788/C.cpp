
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

const int N = 1005;
int n, k, a;
vi adj[4 * N];
int dist[4 * N];
bool vis[4 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    set<int> s;
    bool b[2] = {false, false};
    rep(i, 0, k) {
        cin >> a;
        b[0] |= (a <= n);
        b[1] |= (a >= n);
        s.insert(a - n);
    }
    if(!b[0] || !b[1]) {
        cout << "-1\n";
        return 0;
    }
    rep(i, 0, 4 * n + 1) {
        for(int x : s) {
            if(i + x >= 0 && i + x <= 4 * n) {
                adj[i].push_back(i + x);
            }
        }
    }
    queue<int> Q;
    Q.push(2 * n);
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        if(x == 2 * n && dist[x] > 0) {
            cout << dist[x] << '\n';
            return 0;
        }
        for(int y : adj[x]) {
            if(!vis[y]) {
                vis[y] = true;
                dist[y] = 1 + dist[x];
                Q.push(y);
            }
        }
    }
    assert(false);
}