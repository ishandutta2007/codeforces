#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            cin >> a[i];
        }
        sort(a, a + m);
        for(int i = 1; i < m; i++) {
            b[i] = a[i] - a[i - 1] - 1;
        }
        b[0] = a[0] + n - a[m - 1] - 1;
        sort(b, b + m);
        int k = 0, cnt = 0;
        for(int i = m - 1; i >= 0; i--) {
            if (b[i] <= k) break;
            if (b[i] - k >= 3) {
                cnt += b[i] - k - 1;
                k += 4;
            }
            else {
                cnt += 1;
                k += 2;
            }
        }
        cout << n - cnt << endl;
    }
    return 0;
}