#include <bits/stdc++.h>
using namespace std;
int n, t;
int a[3 * 10000 + 1];
bool used[3 * 10000 + 1];
bool dfs(int v) {
    used[v] = true;
    if (v == t) {
        return true;
    }
    if (!used[v + a[v]]) {
        return dfs(v + a[v]);
    }
    return false;
}
int main() {
    cin >> n >> t;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    if (dfs(1)) cout << "YES";
    else cout << "NO";
    return 0;
}