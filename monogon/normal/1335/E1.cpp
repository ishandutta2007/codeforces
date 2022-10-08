
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5, A = 205;
int t, n, a[N], pref[N][A], occ[A];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            for(int j = 1; j < A; j++) {
                pref[i][j] = pref[i - 1][j];
            }
            pref[i][a[i]]++;
        }
        int ans = 0;
        for(int v = 1; v < A; v++) {
            fill(occ, occ + A, 0);
            int x = 0, i = 0, j = n;
            while(i <= j) {
                x++;
                while(i < n && pref[i][v] < x) i++;
                while(j > 0 && pref[n][v] - pref[j][v] < x) j--;
            }
            int mx = 0;
            for(; x >= 0; x--) {
                while(i > 0 && pref[i - 1][v] >= x) {
                    if(i <= j) {
                        occ[a[i]]++;
                        mx = max(mx, occ[a[i]]);
                    }
                    i--;
                }
                while(j < n && pref[n][v] - pref[j + 1][v] >= x) {
                    j++;
                    if(j > i) {
                        occ[a[j]]++;
                        mx = max(mx, occ[a[j]]);
                    }
                }
                if(i <= j) {
                    ans = max(ans, 2 * x + mx);
                }
            }
        }
        cout << ans << '\n';
    }
}