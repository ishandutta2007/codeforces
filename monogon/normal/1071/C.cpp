
#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x),end()
#define sz(x) ((int) (x).size())
#define pii pair<int, int>
#define vi vector<int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)

using namespace std;

vector<tuple<int, int, int>> ve;
const int N = 1LL << 15, M = 1e5 + 5;
vi adj[N];
int dist[N], par[N];
bool vis[N];

void build(int n, bool b) {
    ve.clear();
    rep(i, 0, n) rep(j, i + 1, n) rep(k, j + 1, n) {
        if(j - i == k - j) {
            ve.emplace_back(i, j, k);
        }
    }
    rep(mask, 0, 1LL << n) {
        adj[mask].clear();
        for(auto &pa : ve) {
            int mask2 = mask;
            int i, j, k;
            tie(i, j, k) = pa;
            mask2 ^= (1 << i) ^ (1 << j) ^ (1 << k);
            adj[mask].push_back(mask2);
        }
    }
    queue<int> Q;
    fill(vis, vis + (1 << n), false);
    fill(dist, dist + (1 << n), INT_MAX);
    if(b) {
        Q.push(0);
        dist[0] = 0;
        vis[0] = true;
    }else {
        rep(i, 0, 1LL << (n / 2)) {
            int mask = i;//(i << (n / 2));
            Q.push(mask);
            dist[mask] = 0;
            vis[mask] = true;
        }
    }
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int y : adj[x]) {
            if(!vis[y]) {
                par[y] = x;
                vis[y] = true;
                dist[y] = dist[x] + 1;
                Q.push(y);
            }
        }
    }
}

int a[M];

vector<array<int, 3>> ops;

void print() {
    cout << sz(ops) << '\n';
    for(auto &pa : ops) {
        cout << pa[0] << ' ' << pa[1] << ' ' << pa[2] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    build(12, false);
    while(n > 15) {
        int mask = 0;
        rep(i, 0, 12) {
            mask ^= (a[n - 12 + i] << i);
        }
        assert(dist[mask] != INT_MAX);
        while(dist[mask] != 0) {
            array<int, 3> arr = {0, 0, 0};
            int idx = 0;
            rep(i, 0, 12) {
                if(((mask ^ par[mask]) >> i) & 1) {
                    arr[idx++] = n - 12 + i + 1;
                    a[n - 12 + i] = 1 - a[n - 12 + i];
                }
            }
            mask = par[mask];
            ops.push_back(arr);
        }
        n -= 6;
    }
    build(n, true);
    int mask = 0;
    rep(i, 0, n) {
        if(a[i] == 1) mask ^= (1 << i);
    }
    if(dist[mask] == INT_MAX) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    while(mask != 0) {
        int idx = 0;
        array<int, 3> arr = {0, 0, 0};
        rep(i, 0, n) {
            if(((mask ^ par[mask]) >> i) & 1) {
                arr[idx++] = i + 1;
            }
        }
        mask = par[mask];
        ops.push_back(arr);
    }
    print();
}