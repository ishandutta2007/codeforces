#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5;

int n, u, ans = N, pr[N], di[N], dst[N], par[N];
bool chk[N];
queue<int> q;
vector<int> ve, adj[N];

void init() {
    fill(pr + 1, pr + N, 1);
    for (int i = 2; i < N; i++) {
        if (di[i] == 0) {
            for (int j = i; j < N; j += i) {
                if (pr[j / i] % i != 0) {
                    pr[j] *= i;
                }
                di[j] = i;
            }
        }
    }
    for (int i = 1; i < N; i++) {
        if (pr[i] == i) {
            ve.push_back(i);
        }
    }
}

void solve(int st) {
    for (int &v : ve) {
        dst[v] = N;
        par[v] = -1;
    }
    for (q.push(st), dst[st] = 0; !q.empty(); q.pop()) {
        int u = q.front();
        for (int &v : adj[u]) {
            if (dst[v] == N) {
                dst[v] = dst[u] + 1;
                par[v] = u;
                q.push(v);
            } else if (par[u] != v && par[v] != u) {
                ans = min(ans, dst[u] + dst[v] + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> u; u = pr[u];
        if (u == 1) {
            return cout << 1, 0;
        } else if (!chk[u]) {
            chk[u] = true;
            int d = di[u];
            adj[d].push_back(u / d); adj[u / d].push_back(d);
        } else {
            ans = 2;
        }
    }
    if (ans == 2) {
        return cout << 2, 0;
    }
    for (int i = 1; 1LL * i * i < N; i++) {
        if (!adj[i].empty()) {
            solve(i);
        }
    }
    cout << (ans == N ? -1 : ans);
}