
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

// if a node has exactly one of the edges traversed once, it must be starting/end node.
// suppose the two edges do not share a vertex. Then four different nodes must be starting/ending, which is impossible.
// If we choose an arbitrary pair of edges that share a vertex, we can find a spanning tree containing this pair
// then do traversal to count every other edge twice.

// Now, what about self loops?
// Any pair of self loops can be done.
// what about a self loop and another edge? Can always be done.

const int N = 1e6 + 5;
int n, m, u[N], v[N], deg[N], dsu[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}

void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    fill(dsu + 1, dsu + n + 1, -1);
    int loops = 0;
    rep(i, 0, m) {
        cin >> u[i] >> v[i];
        if(u[i] == v[i]) {
            loops++;
        }else {
            join(u[i], v[i]);
            deg[u[i]]++;
            deg[v[i]]++;
        }
    }
    int cmp = trace(u[0]);
    rep(i, 1, m) {
        if(trace(u[i]) != cmp) {
            cout << "0\n";
            return 0;
        }
    }
    ll ans = 1LL * loops * (loops - 1) / 2 + 1LL * loops * (m - loops);
    rep(i, 1, n + 1) {
        ans += 1LL * deg[i] * (deg[i] - 1) / 2;
    }
    cout << ans << '\n';
}