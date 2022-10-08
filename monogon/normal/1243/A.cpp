
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1005;
int t, n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        ll m = 0;
        for(int i = 0; i < n; i++) {
            m = max(m, min(a[i], (ll) n - i));
        }
        cout << m << endl;
    }
}