#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, m;
long long a[N];
__int128 b[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    __int128 mx;
    while (t--) {
        mx = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            __int128 ans = 0;
            for(int j = 0; j < m; j++) {
                cin >> a[j];
                ans += a[j] * j;
            }
            b[i] = ans;
            mx = max(ans, mx);
        }
        for(int i = 0; i < n; i++) {
            if (b[i] == mx) {
                cout << i + 1 << ' ';
                if (i > 0) {
                    long long cnt = b[i] - b[i - 1];
                    cout << cnt << endl;
                }
                else {
                    long long cnt = b[i] - b[i + 1];
                    cout << cnt << endl;
                }
            }
        }
    }
    return 0;
}