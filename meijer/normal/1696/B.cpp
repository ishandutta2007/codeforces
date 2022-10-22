#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int n, m, a[N], b[N];
string s;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 0;
    cin >> tests;
    while (tests--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        int l=0, r=n-1;
        while (l < n && a[l] == 0) l++;
        if (l == n) {
            cout << 0 << endl;
            continue;
        }
        while (r >= 0 && a[r] == 0) r--;
        bool f= 0;
        for (int i=l; i<=r; i++) {
            if (a[i] == 0) {
                f = 1;
            }
        }
        cout << (f ? 2 : 1) << endl;
    }
}