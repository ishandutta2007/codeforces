
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

const int N = 1e5 + 5;
int n;
ll p[N], h[N];
ll dp[N], bad[N];
vi adj[N];
bool flag;

void dfs(int x, int pa) {
    dp[x] = p[x];
    ll sumbad = 0;
    for(int y : adj[x]) {
        if(y != pa) {
            dfs(y, x);
            dp[x] += dp[y];
            sumbad += bad[y];
        }
    }
    // good + bad = dp
    // good - bad = h
    // dp - h = 2 * bad
    if((dp[x] - h[x]) % 2 != 0 || (dp[x] - h[x] < 0) || dp[x] + h[x] < 0) {
        flag = true;
    }
    bad[x] = (dp[x] - h[x]) / 2;
    if(bad[x] - sumbad > p[x]) {
        flag = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        ll m;
        cin >> n >> m;
        rep(i, 1, n + 1) {
            adj[i].clear();
            cin >> p[i];
        }
        rep(i, 1, n + 1) {
            cin >> h[i];
        }
        rep(i, 0, n - 1) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        flag = false;
        dfs(1, -1);
        if(flag) {
            cout << "NO\n";
        }else {
            cout << "YES\n";
        }
    }
}