#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    array<string, 2> a;
    cin >> n >> a[0] >> a[1];

    int answer = 0;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && (a[0][j] == '1' && a[1][j] == '1'))
            j++;

        if (j == n)
            break;

        bool one = false;
        for (; i <= j; i++)
            one |= a[0][i] == '1' || a[1][i] == '1';

        if (!one && i < n && (a[0][i] == '1' && a[1][i] == '1')) {
            i++;
            one = true;
        }

        answer += 1 + one;
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}