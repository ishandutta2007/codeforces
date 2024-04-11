#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;

    int cnt = n - count(all(s), c);
    if (cnt == 0) {
        cout << "0\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        int current = 0;
        for (int j = i; j <= n; j += i)
            current += s[j - 1] != c;

        if (current == 0) {
            cout << "1\n";
            cout << i << '\n';
            return;
        }
    }

    cout << "2\n" << n - 1 << ' ' << n << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}