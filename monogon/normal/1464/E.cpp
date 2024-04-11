
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

const int N = 1e5 + 5, K = 513, M = 998244353;
vi adj[N];
int g[N], cnt[K];
bool vis[N];

int mex(const vi &ve) {
    int k = sz(ve);
    vector<bool> b(k + 1, false);
    for(int x : ve) {
        if(x <= k) b[x] = true;
    }
    int idx = 0;
    while(b[idx]) idx++;
    return idx;
}

void dfs(int x) {
    vis[x] = true;
    vi ve;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
        }
        ve.push_back(g[y]);
    }
    g[x] = mex(ve);
}

ll powmod(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b /= 2;
    }
    return ans;
}

ll modinv(ll a) {
    return powmod(a, M - 2);
}

void gauss(vector<array<ll, K>> &A) {
    int m = K - 1, n = K;
    for(int i = 0, p = 0; i < m && p < n; p++) {
        int r = i;
        for(int j = i + 1; j < m; j++)
            if(A[j][p] != 0) r = j;
        if(A[r][p] == 0) continue;
        swap(A[i], A[r]);
        ll inv = modinv(A[i][p]);
        rep(k, p, n) {
            A[i][k] = (A[i][k] * inv) % M;
        }
        for(int j = i + 1; j < m; j++) {
            for(int k = n - 1; k >= p; k--) {
                A[j][k] = (A[j][k] - A[j][p] * A[i][k]) % M;
            }
        }
        i++;
    }
    for(int i = m - 1; i >= 0; i--) {
        rep(j, i + 1, n - 1) {
            A[i][n - 1] = (A[i][n - 1] - A[i][j] * A[j][n - 1]) % M;
            A[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    rep(i, 1, n + 1) {
        if(!vis[i]) dfs(i);
        cnt[g[i]]++;
    }
    ll inv = modinv(n + 1);
    // ll ninv = (n * inv) % M;
    vector<array<ll, K>> X(K);
    rep(i, 0, K - 1) {
        rep(j, 0, K - 1) {
            if(i == j) {
                X[i][j] = ((1 - inv * cnt[i ^ j]) % M + M) % M;
            }else {
                X[i][j] = ((- inv * cnt[i ^ j]) % M + M) % M;
            }
        }
    }
    X[0][K - 1] = inv;
    // cout << endl;
    // rep(i, 0, K) {
    //     rep(j, 0, K) {
    //         cout << X[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    gauss(X);
    // rep(i, 0, K) {
    //     rep(j, 0, K) {
    //         cout << X[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << ((1 - X[0][K - 1]) % M + M) % M << '\n';
}