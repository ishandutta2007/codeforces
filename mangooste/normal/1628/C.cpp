#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int answer = 0;
    for (int rot : {0, 1}) {
        for (int st = 1; st < n; st += 4)
            for (int i = 0, j = st; j < n; i += 2, j += 2)
                answer ^= a[i][j];

        for (int st = 3; st < n; st += 4)
            for (int i = st, j = 0; i < n; i += 2, j += 2)
                answer ^= a[i][j];

        for (auto &v : a)
            reverse(all(v));
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