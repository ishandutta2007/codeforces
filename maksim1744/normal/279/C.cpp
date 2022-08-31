#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& k : a)
        cin >> k;

    vector<int> tor(n), tol(n);
    iota(tol.begin(), tol.end(), 0);
    iota(tor.begin(), tor.end(), 0);

    tol[0] = 0;
    for (int i = 1; i < n; ++i)
        if (a[i - 1] >= a[i])
            tol[i] = tol[i - 1];

    tor[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i)
        if (a[i] <= a[i + 1])
            tor[i] = tor[i + 1];

    while (m--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        cout << (tol[r] <= tor[l] ? "Yes" : "No") << '\n';
    }

    return 0;
}