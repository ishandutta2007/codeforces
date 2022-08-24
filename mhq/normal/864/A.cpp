#include <bits/stdc++.h>
using namespace std;
int f[101];
int main() {
    //freopen("jellous.in", "r", stdin);
    //freopen("jellous.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int n, x;
    cin >> n;
    for ( int i = 1; i <= n; i++) {
        cin >> x;
        f[x]++;
    }
    int cur = 0;
    for ( int i = 1; i <= 100; i++) {
        if ( f[i] * 2 == n) {
            cur++;
        }
    }
    if (cur == 2) {
        cout << "YES" << endl;
        for ( int i = 1; i <= 100; i++) {
            if (f[i] * 2 == n) cout << i << endl;
        }
    }
    else cout << "NO";
    return 0;
}