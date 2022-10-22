#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int t, n, a[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];
        int tot = 0;
        for (int i=0; i<n; i++)
            tot += a[i];
        bool f = 0;
        for (int i=0; i<n; i++)
            if (a[i] == tot/n)
                f = 1;
        cout << (tot%n == 0 && f ? "YES" : "NO") << endl;
    }
}