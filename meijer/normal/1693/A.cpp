#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int t, n, a[N], r[N], l[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        bool pos = 1;
        while (n != 0 && a[n-1] == 0) n--;
        if (n == 0) {
            cout << "Yes" << endl;
            continue;
        }
        
        r[0] = a[0];
        l[0] = 0;
        int sm = a[0];
        for (int i=1; i<n; i++) {
            sm += a[i];
            l[i] = r[i-1];
            r[i] = a[i] + l[i];
        }
        for (int i=0; i<n; i++) {
            if (l[i] < 0 || r[i] < 0) pos = 0;
            if (r[i] == 0 && i != n-1) pos = 0;
        }

        if (sm != 0) pos = 0;
        cout << (pos ? "Yes" : "No") << endl;
    }
}