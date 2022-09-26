#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, c[N], a[N];
bool f1[N], f2[N], g[N];
int mn, ans = 0;;
bool have;
int to;

void dfs(int u) {
    if(f1[u]) {
        if(g[u]) {
            mn = 0;
            have = true;
            return;
        }
        have = false;
        to = u;
        return;
    }
    f1[u] = true;
    dfs(a[u]);
    g[u] = true;
    if(have) return;
    mn = min(mn, c[u]);
    if(u == to) have = true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) if(!f1[i]) {
        mn = 10007;
        dfs(i);
	     ans += mn;
   }
    cout << ans;
}