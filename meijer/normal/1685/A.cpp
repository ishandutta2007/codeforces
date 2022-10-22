#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int t, n;
int a[N], b[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        sort(a,a+n);
        if (n % 2) {
            cout << "NO" << endl;
            continue;
        }
        for (int i=0; i<n; i++) {
            b[i*2 >= n ? i*2%n+1 : i*2] = a[i];
        }
        bool res = 1;
        for (int i=0; i<n; i++) {
            bool f = 0;
            if (b[i] > b[(i+n-1)%n] && b[i] > b[(i+1)%n])
                f = 1;
            if (b[i] < b[(i+n-1)%n] && b[i] < b[(i+1)%n])
                f = 1;
            if (!f)
                res = 0;
        }
        if (!res) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i=0; i<n; i++) {
            cout << (i==0?"":" ") << b[i];
        }
        cout << endl;
    }
}