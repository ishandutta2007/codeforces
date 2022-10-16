#include <bits/stdc++.h>

using namespace std;

int n;
long long a[200005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) a[i] = ((a[i] + i) % n + n) % n;
        set <int> s;
        for (int i = 0; i < n; ++i) s.insert(a[i]);
        if (s.size() == n) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}