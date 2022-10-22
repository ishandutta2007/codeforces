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
int cnta[N], cntb[N];
int k;
string s;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 0;
    cin >> tests;
    while (tests--) {
        cin >> n >> m;
        for (int i=0; i<n; i++) cin >> a[i];
        cin >> k;
        for (int i=0; i<k; i++) cin >> b[i];

        int sma = 0;
        for (int i=0; i<n; i++) {
            sma += a[i];
        }
        int smb = 0;
        for (int i=0; i<k; i++) {
            smb += b[i];
        }

        if (sma != smb) {
            cout << "No" << endl;
            continue;
        }

        for (int i=0; i<n; i++) {
            cnta[i] = 1;
            while (a[i] % m == 0) {
                a[i] /= m;
                cnta[i] *= m;
            } 
        }
        for (int i=0; i<k; i++) {
            cntb[i] = 1;
            while (b[i] % m == 0) {
                b[i] /= m;
                cntb[i] *= m;
            } 
        }

        bool pos = 1;
        int x = 0, y = 0;
        while (x < n) {
            if (a[x] != b[y]) {
                pos = 0;
                break;
            }
            if (cnta[x] == cntb[y]) {
                x++;
                y++;
            } else if (cnta[x] < cntb[y]) {
                cntb[y] -= cnta[x];
                x++;
            } else {
                cnta[x] -= cntb[y];
                y++;
            }
        }

        cout << (pos ? "Yes" : "No") << endl;
    }
}