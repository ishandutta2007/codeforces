#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tot;
    cin >> tot;
    vector<int> a(tot);
    for (auto &x : a)
        cin >> x;

    sort(all(a));

    vector<int> freq(tot);
    for (auto x : a)
        freq[x]++;

    if (freq[0] != 1) {
        cout << "-1\n";
        return 0;
    }

    if (tot == 1) {
        cout << "1 1\n1 1\n";
        return 0;
    }

    int sum_xy = a.back(), n_minus_x = -1;

    for (int i = 1; i < tot; i++)
        if (freq[i] != 4 * i) {
            n_minus_x = i;
            break;
        }

    if (n_minus_x == -1) {
        cout << "-1\n";
        return 0;
    }

    vector<int> check(tot);

    auto try_solve = [&](int n, int m) {
        int x = n - n_minus_x, y = sum_xy - x;
        // cout << "try_solve " << n << ' ' << m << ", " << x << ' ' << y << endl;
        if (x < 0 || x >= n || y < 0 || y >= m)
            return;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                check[i * m + j] = abs(i - x) + abs(j - y);

        sort(all(check));
        if (check == a) {
            cout << n << ' ' << m << '\n';
            cout << x + 1 << ' ' << y + 1 << '\n';
            exit(0);
        }
    };

    for (int n = 1; n * n <= tot; n++)
        if (tot % n == 0) {
            try_solve(n, tot / n);
            if (n * n != tot)
                try_solve(tot / n, n);
        }

    cout << "-1\n";
}