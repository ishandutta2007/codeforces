
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 105;

int q, n;
ll k;
ll a[MAX_N];

int main() {
    cin >> q;
    while(q--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll m = *min_element(a, a + n);
        ll M = *max_element(a, a + n);
        if(M - m <= 2 * k) {
            cout << m + k << endl;
        }else cout << -1 << endl;
    }
}