#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int t, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 4; i <= n + 1; i *= 2) {
            if (n % (i - 1) == 0) {
                cout << n / (i - 1) << '\n';
                break;
            }
        }
    }
}