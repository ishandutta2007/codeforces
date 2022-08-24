#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 10;
int c[maxN], a[maxN], n;
int color[maxN];
int ans = 0;
void dfs(int v) {
    //cout << "HERE " << " " << v << endl;
    //for (int i = 1; i <= 5; i++) cout << color[i] << " ";
    //cout << endl;
    if (color[v] == 1) {
        int mn = c[v];
        int x = a[v];
        while (x != v) {
            mn = min(mn, c[x]);
            color[x] = 2;
            x = a[x];
        }
       // cout << v << " " << mn << endl;
        ans += mn;
        color[v] = 2;
        return ;
    }
    if (color[v] == 2) return ;
    color[v] = 1;
    dfs(a[v]);
    color[v] = 2;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) dfs(i);
    }
    cout << ans;
    return 0;
}