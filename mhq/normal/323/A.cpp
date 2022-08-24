#include <bits/stdc++.h>
using namespace std;
int k;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> k;
    if (k % 2 == 1) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            for (int p = 1; p <= k; p++) {
                if (((j - 1) / 2) % 2 == ((p - 1) / 2) % 2) {
                    if (i % 2 == 1) cout << "b";
                    else cout << "w";
                }
                else {
                    if (i % 2 == 1) cout << "w";
                    else cout << "b";
                }
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}