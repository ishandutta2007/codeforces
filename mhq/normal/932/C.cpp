#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> a >> b;
    int x = -1;
    int y = -1;
    for (int i = 0; i * a <= n; i++) {
        if ((n - i * a) % b == 0) {
            x = i;
            y = (n - i * a) / b;
            break;
        }
    }
    if (x == -1) {
        cout << -1;
        return 0;
    }
    //cout << x << " " << y << '\n';
    for (int i = 1; i <= x; i++) {
        for (int j = (i - 1) * a + 1; j <= i * a; j++) {
            if (j != i * a) cout << j + 1 << " ";
            else cout << ((i - 1) * a + 1) << " ";
        }
    }
    //cout << "HERE";
    for (int i = 1; i <= y; i++) {
        for (int j = (i - 1) * b + 1 + x * a; j <= i * b + x * a; j++) {
            if (j != (i * b + x * a)) cout << j + 1 << " ";
            else cout << ((i - 1) * b + 1 + x * a) << " ";
        }
    }
    return 0;
}