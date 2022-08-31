#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxN = (int)1e5 + 10;
vector < int > g[maxN];
int a[maxN];
int id[maxN];
bool win[maxN];
void dfs(int v) {
    bool ok = false;
    for (int to : g[v]) {
        if (!win[to]) {
            ok = true;
            break;
        }
    }
    win[v] = ok;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        id[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        int p = a[i];
        for (int j = i - p; j > 0; j -= p) {
            if (a[j] > a[i]) g[i].push_back(j);
        }
        for (int j = i + p; j <= n; j += p) {
            if (a[j] > a[i]) g[i].push_back(j);
        }
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--) {
        dfs(id[a[i]]);
    }
    for (int i = 1; i <= n; i++) {
        if (win[i]) cout << "A";
        else cout << "B";
    }
}