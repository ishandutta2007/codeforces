#include <bits/stdc++.h>
using namespace std;
const int maxN = 1005;
int n, m;
int c[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        c[x]++;
    }
    int mn = c[1];
    for (int i = 1; i <= n; i++) mn = min(mn, c[i]);
    cout << mn;
    return 0;
}