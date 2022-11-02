#include<bits/stdc++.h>
using namespace std;
const int N = 300000 + 5;
constexpr int mod = 998244353;
using LL = long long;
int n;
int a[N], deg[N], ans[N];
int vis[N];
vector<pair<int, int> > v;
void dfs(int x) {
    int cur = x;
    while (1) {
        vis[cur] = 1;
        if (vis[a[cur]]) {
            v.push_back(make_pair(x, cur));
            break;
        }
        ans[cur] = a[cur];
        cur = a[cur];
    }
}
void cal() {
    for (int i = 1; i <= n; i += 1) ans[i] = a[i];
    int tot = v.size();
    for (int i = 0; i < v.size(); i += 1) {
        int tp = (i + 1) % tot;
        ans[v[i].second] = v[tp].first;
    }
}
void output() {
    int k = 0;
    for (int i = 1; i <= n; i += 1)
        if (a[i] == ans[i]) k++;
    cout << k << '\n';
    for (int i = 1; i <= n; i += 1)
        cout << ans[i] << ' ';
    cout << '\n';
}
void clear() {
    for (int i = 1; i <= n; i += 1) deg[i] = 0, vis[i] = 0;
    v.clear();
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i += 1)
            cin >> a[i];
        for (int i = 1; i <= n; i += 1) deg[a[i]] ++;

        for (int i = 1; i <= n; i += 1) {
            if (deg[i] == 0) {
                dfs(i);
            }
        }
        cal();
        output();
        clear();
    }
}
/*

*/