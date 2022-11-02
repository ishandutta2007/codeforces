#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;
const int maxk = 2005;

int n, k, p;
int a[maxn], b[maxk];

int main() {
    cin >> n >> k >> p;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + k);
    
    int ans = 2e9;
    for (int i = 0; i + n <= k; i++) {
        int ma = 0;
        for (int j = 0; j < n; j++)
            ma = max(ma, abs(a[j] - b[i + j]) + abs(b[i + j] - p));
        ans = min(ans, ma);
    }

    cout << ans << endl;
}