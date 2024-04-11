
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, c[N], a[N], vis[N];
ll ans = 0;
vector<int> cyc;

bool dfs(int x) {
    vis[x] = 1;
    if(vis[a[x]] == 0) {
        dfs(a[x]);
    }else if(vis[a[x]] == 1) {
        cyc.push_back(a[x]);
    }
    vis[x] = 2;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            dfs(i);
        }
    }
    fill(vis, vis + n, 0);
    for(int x : cyc) {
        int y = x;
        int m = c[x];
        y = a[y];
        while(y != x) {
            m = min(m, c[y]);
            y = a[y];
        }
        ans += m;
    }
    cout << ans << endl;
}