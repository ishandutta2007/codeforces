#include <bits/stdc++.h>

using namespace std;

signed main() {
    int64_t n;
    cin >> n;
    if (n <= 3) {
        int64_t a[] = {-1, 3, 5, 7};
        cout << a[n] << '\n';
    } else {
        --n;
        int64_t a[3] = {0, 1, 3};
        cout << (n/3+1) * 4 + a[n%3] << '\n';
    }
}