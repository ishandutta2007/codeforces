#include <bits/stdc++.h>

using namespace std;

int n;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int sz = sqrt(n);
    for (int i = 0; i < n; i += sz)
        for (int j = min(sz, n - i); j > 0; --j) cout << i + j << ' ';
    cout << endl;
    return 0;
}