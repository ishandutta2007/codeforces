#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int n, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        sort(a,a+n);
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (i >= 2 && a[i-1] == a[i] && a[i-2] == a[i])
                continue;
            ans++;
        }
        for (int i=0; i<n; i++) {
            if ((i == 0 || a[i] != a[i-1]) && (i == n-1 || a[i] != a[i+1])) {
                ans++;
                break;
            }
        }
        cout << ans/2 << endl;
    }
}