#include <bits/stdc++.h>

using namespace std;

signed main() {
    int N, D;
    cin >> N >> D;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = N - 1, j = 0; i >= j; i--) {
        int s = a[i];
        // cerr << a[i] << ';';
        while (j < i && s <= D) {
            // cerr << a[j] << ',';
            ++j;
            s += a[i];
        }
        // cerr << endl;
        if (s > D)
            ++ans;
    }
    cout << ans << '\n';
}