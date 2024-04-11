#include <bits/stdc++.h>

using namespace std;

int n, m;
string s[25], t[25];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < m; ++i) cin >> t[i];
    int q;
    cin >> q;
    while (q--) {
        int x; cin >> x;
        --x;
        cout << s[x%n] << t[x%m] << '\n';
    }
    return 0;
}