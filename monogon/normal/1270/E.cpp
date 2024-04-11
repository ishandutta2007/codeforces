
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// Define the parity of a point (x, y) as (x + y) mod 2.
// Suppose we color points by their parity.
// Square distance between two points is:
// (x2 - x1)^2 + (y2 - y1)^2 mod 2 = x2 + y2 + x1 + y1 mod 2
// So, same parity <=> even.

// But the sets must be nonempty. What if all points have the same parity?
// If all points have odd parity: Move to the left by 1, reduced to even parity case
// If all points have even parity: change coordinates to ((x + y) / 2, (x - y) / 2).
// Repeat until two points have different parity.

const int N = 1005;
int n;
ll x[N], y[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    while(true) {
        int e = 0, o = 0;
        for(int i = 0; i < n; i++) {
            ((x[i] + y[i]) % 2 ? o : e)++;
        }
        if(o > 0 && e > 0) {
            cout << e << endl;
            for(int i = 0; i < n; i++) {
                if((x[i] + y[i]) % 2 == 0) cout << (i + 1) << " ";
            }
            cout << endl;
            return 0;
        }
        for(int i = 0; i < n; i++) {
            if(e == 0) x[i]--;
            ll X = (x[i] + y[i]) / 2;
            ll Y = (x[i] - y[i]) / 2;
            x[i] = X;
            y[i] = Y;
        }
    }
}