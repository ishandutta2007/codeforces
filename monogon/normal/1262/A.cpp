
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
ll a, b, m, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        m = 2e9;
        M = -1;
        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            m = min(m, b);
            M = max(M, a);
        }
        cout << max(0LL, M - m) << endl;
    }
}