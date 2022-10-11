#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    if (k >= n * (n - 1) / 2) {
        return cout << "no solution", 0;
    }
    for (int i = 1; i <= n; i++) {
        cout << "0 " << i << '\n';
    }
}