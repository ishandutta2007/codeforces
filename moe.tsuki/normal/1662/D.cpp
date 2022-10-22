#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        int cba = 0, cbb = 0;
        for (auto c : a) cba += c == 'B';
        for (auto c : b) cbb += c == 'B';
        if (cba % 2 != cbb % 2) {
            cout << "NO\n";
            continue;
        }
        string sa, sb;
        for (auto c : a) {
            if (c == 'B') continue;
            if (not sa.empty() and sa.back() == c)
                sa.pop_back();
            else sa.push_back(c);
        }
        for (auto c : b) {
            if (c == 'B') continue;
            if (not sb.empty() and sb.back() == c)
                sb.pop_back();
            else sb.push_back(c);
        }
        if (sa == sb) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}