#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> v[5005];
int d[5005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) d[i] = n;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        v[a].push_back(b);
        d[a] = min(d[a], (b - a + n) % n);
    }
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = 0; j < n; ++j) if (v[j].size()) ans = max(ans, (j - i + n) % n + (int)(v[j].size() - 1) * n + d[j]);
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}