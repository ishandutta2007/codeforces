#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (n == 2) {
            if (a || b) cout << -1 << endl;
            else cout << 1 << ' ' << 2 << endl;
            continue;
        }
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        int l = 0, r = n - 1;
        if (a - b == 1) {
            swap(v[n-1], v[n-2]);
            --a;
            --r;
        }
        if (b - a == 1) {
            swap(v[0], v[1]);
            --b;
            ++l;
        }
        if (a != b) {
            cout << -1 << endl;
            continue;
        }
        for (int i = l + 1; i + 1 < r; i += 2) if (a) {
            swap(v[i], v[i+1]);
            --a; --b;
        }
        if (a) {
            cout << -1 << endl;
            continue;
        }
        for (auto x: v) cout << x << ' '; cout << endl;
    }
    return 0;
}