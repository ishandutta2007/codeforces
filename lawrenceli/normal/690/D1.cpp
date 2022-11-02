#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s;
    int ans = 0, cur = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == 'B') cur = 1;
        else ans += cur, cur = 0;
    }
    ans += cur;
    cout << ans << '\n';
}