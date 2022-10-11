#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;

    int up = 0, down = 0, left = 0, right = 0;
    for (auto c : s)
        if (c == 'U')
            up++;
        else if (c == 'D')
            down++;
        else if (c == 'L')
            left++;
        else
            right++;

    bool ok = true;
    if (x < 0)
        ok &= left >= -x;
    else
        ok &= right >= x;
    if (y < 0)
        ok &= down >= -y;
    else
        ok &= up >= y;
    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}