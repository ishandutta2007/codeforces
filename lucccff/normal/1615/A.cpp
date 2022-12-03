#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, ans;
    cin >> t;
    while(t--) {
        cin >> n;
        int k;
        ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> k;
            ans += k;
        }
        if (ans % n == 0) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
    }
}