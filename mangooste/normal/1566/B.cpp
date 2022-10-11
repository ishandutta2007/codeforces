#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

void solve() {
    string s;
    cin >> s;
    int zero = 0;
    while (zero < len(s) && s[zero] != '0')
        zero++;

    if (zero == len(s)) {
        cout << "0\n";
        return;
    }

    int last_zero = len(s) - 1;
    while (s[last_zero] != '0')
        last_zero--;

    for (int i = zero; i <= last_zero; i++)
        if (s[i] != '0') {
            cout << "2\n";
            return;
        }

    cout << "1\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}