#include <bits/stdc++.h>
using namespace std;
int n;
int a[102];
int b[102][102];
bool c[1000000 + 2];
int ans[102];
void solve() {
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    cout << "YES" << endl;
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            b[i][j] = a[i] - a[j];
        }
    }
    ans[0] = 1;
    for ( int t = 0; t < n; t++) {
        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < n; j++) {
                if ( ans[t] + b[i][j] <= 0) continue;
                c[ans[t] + b[i][j]] = true;
            }
        }
        for (int r = ans[t] + 1; r <= 1000000; r++) {
            if ( !c[r] ) {
                ans[t+1] = r;
                break;
            }
        }
      }
   for ( int i = 0; i < n; i++) {
    cout << ans[i] << " ";
   }
   cout << endl;
   for ( int i = 1; i <= 1000000; i++) {
        c[i] = false;
   }
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (; t >= 1; t--) {
        solve();
    }
}