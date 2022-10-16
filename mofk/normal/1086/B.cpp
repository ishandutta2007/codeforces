#include <bits/stdc++.h>

using namespace std;

int n, s;
int deg[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        ++deg[u], ++deg[v];
    }
    int p = 0;
    for (int i = 1; i <= n; ++i) p += (deg[i] == 1);
    cout << setprecision(12) << fixed << s * 2.0 / p << endl;
    return 0;
}