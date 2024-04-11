#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    if (n < 6) {
        cout << -1 << '\n';
    }
    else {
        for (int i = 5; i <= n; i++) cout << 1 << " " << i << '\n';
        cout << 1 << " " << 2 << '\n';
        cout << 2 << " " << 3 << '\n';
        cout << 2 << " " << 4 << '\n';
    }
    for (int i = 1; i < n; i++) cout << i << " " << i + 1 << '\n';
    //1 - verno
    // 2 - verno
    // 3 - verno
    // 4 - verno
    // 5
    return 0;
}