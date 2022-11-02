#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int n, a;
int t[maxn];

int main() {
    cin >> n >> a; a--;
    for (int i = 0; i < n; i++) cin >> t[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) ans += t[a];
        else {
            int l = a - i, r = a + i;
            int sum = (l >= 0 ? t[l] : 0) + (r < n ? t[r] : 0);
            if (l < 0 || r >= n) ans += sum;
            else if (sum == 2) ans += sum;
        }
    }

    cout << ans << endl;
}