#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    array<int, 2> banned{n, n};
    vector<int> right(n + 1, n);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'L')
            banned[i % 2] = i;
        else
            banned[(i + 1) % 2] = i;
        right[i] = banned[i % 2];
    }

    banned = array<int, 2>{0, 0};
    vector<int> left(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'L')
            banned[(i + 1) % 2] = i;
        else
            banned[i % 2] = i;
        left[i] = banned[i % 2];
    }

    for (int i = 0; i <= n; i++)
        cout << right[i] - left[i] + 1 << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}