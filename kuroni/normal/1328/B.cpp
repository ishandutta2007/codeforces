#include <bits/stdc++.h>
using namespace std;

int t, n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k; --k;
        string s;
        for (int i = 0; i < n; i++) {
            s += 'a';
        }
        for (int i = n - 2; i >= 0; i--) {
            if (k >= n - 1 - i) {
                k -= n - 1 - i;
            } else {
                s[i] = s[n - 1 - k] = 'b';
                break;
            }
        }
        cout << s << '\n';
    }
}