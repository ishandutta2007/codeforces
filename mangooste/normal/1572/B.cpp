#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    int tot_xor = 0;
    for (auto x : a)
        tot_xor ^= x;

    if (tot_xor != 0) {
        cout << "NO\n";
        return;
    }

    vector<int> ops;

    auto do_operation = [&](int pos) {
        assert(0 <= pos && pos + 2 < n);
        int x = a[pos] ^ a[pos + 1] ^ a[pos + 2];
        a[pos] = a[pos + 1] = a[pos + 2] = x;
        ops.push_back(pos);
    };

    if (n % 2 == 1) {
        for (int i = 0; i + 2 < n; i += 2)
            do_operation(i);

        for (int i = n - 5; i >= 0; i -= 2)
            do_operation(i);
    } else {
        int cur = a[0];
        bool any = false;

        for (int i = 1; i < n; i += 2) {
            if (cur == 0) {
                for (int j = 0; j + 2 < i; j += 2)
                    do_operation(j);

                for (int j = i - 5; j >= 0; j -= 2)
                    do_operation(j);

                for (int j = i; j + 2 < n; j += 2)
                    do_operation(j);

                for (int j = n - 5; j >= i; j -= 2)
                    do_operation(j);

                any = true;
                break;
            }

            if (i + 1 < n)
                cur ^= a[i] ^ a[i + 1];
        }

        if (!any) {
            cout << "NO\n";
            return;
        }
    }

    assert(len(ops) <= n);
    assert(a == vector<int>(n));

    cout << "YES\n";
    cout << len(ops) << '\n';
    for (int i = 0; i < len(ops); i++)
        cout << ops[i] + 1 << " \n"[i == len(ops) - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}