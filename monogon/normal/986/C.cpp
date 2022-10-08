
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

const int N = 23;
int n, m, a[1 << N];
bool vis[1 << N], valid[1 << N];

void dfs(int x) {
    vis[x] = true;
    if((x >> n) & 1) {
        // dfs on subsets
        rep(i, 0, n) {
            if(((x >> i) & 1) && !vis[x ^ (1 << i)]) {
                dfs(x ^ (1 << i));
            }
        }
        if(valid[x ^ (1 << n)] && !vis[x ^ (1 << n)]) {
            dfs(x ^ (1 << n));
        }
    }else {
        // dfs on complement
        int y = ((1 << (n + 1)) - 1) ^ x;
        if(!vis[y]) dfs(y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int cnt = 0;
    rep(i, 0, m) {
        cin >> a[i];
        valid[a[i]] = true;
    }
    rep(i, 0, m) {
        if(!vis[a[i]]) {
            dfs(a[i]);
            cnt++;
        }
    }
    cout << cnt << '\n';
}