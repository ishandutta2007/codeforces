#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &s : a)
        cin >> s;

    for (auto &s : a)
        if (s == string(s.rbegin(), s.rend())) {
            cout << "YES\n";
            return;
        }

    for (int rot : {0, 1}) {
        set<string> good;
        for (auto &s : a) {
            if (good.count(s)) {
                cout << "YES\n";
                return;
            }

            good.insert(string(s.rbegin(), s.rend()));
            if (len(s) == 3) {
                string tmp;
                tmp += s[1];
                tmp += s[0];
                good.insert(tmp);
            }
        }

        reverse(all(a));
        for (auto &s : a)
            reverse(all(s));
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}