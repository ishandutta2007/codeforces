
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, m, a[N], p[N];

// - - - - -
// [   ]
//   [   ]
//       [ ]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    ll sum = 0;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum < n) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < m; i++) {
        if(i + a[i] > n) {
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 0; i < m; i++) {
        cout << max((ll) i + 1, n - sum + 1) << " ";
        sum -= a[i];
    }
    cout << endl;
}