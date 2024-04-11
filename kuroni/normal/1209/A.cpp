#include <bits/stdc++.h>
using namespace std;

int n, ans = 0, a[105];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        bool chk = false;
        for (int j = 1; j < i; j++) {
            if (a[i] % a[j] == 0) {
                chk = true;
            }
        }
        if (!chk) {
            ans++;
        }
    }
    cout << ans;
}