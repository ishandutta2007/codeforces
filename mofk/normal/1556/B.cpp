#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> a, vector<int> b) {
    int ret = 0, j = 0;
    for (int i = 1; i < a.size(); ++i) if (a[i]) {
        while (!b[j]) ++j;
        ret += abs(i - j);
        ++j;
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        int s = 0;
        for (int i = 1; i <= n; ++i) cin >> a[i], a[i] %= 2, s += a[i];
        int t = n - s;
        if (abs(s - t) > 1) {
            cout << -1 << '\n';
            continue;
        }

        if (s == t) {
            vector<int> b(n + 1, 0);
            for (int i = 1; i <= n; i += 2) b[i] = 1;
            vector<int> c(n + 1, 0);
            for (int i = 2; i <= n; i += 2) c[i] = 1;
            cout << min(solve(a, b), solve(a, c)) << '\n';
        }

        else if (s > t) {
            vector<int> b(n + 1, 0);
            for (int i = 1; i <= n; i += 2) b[i] = 1;
            cout << solve(a, b) << '\n';
        }

        else {
            vector<int> b(n + 1, 0);
            for (int i = 2; i <= n; i += 2) b[i] = 1;
            cout << solve(a, b) << '\n';
        }
    }
    return 0;
}