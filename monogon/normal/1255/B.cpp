
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1005;
int t, n, m;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += 2 * a[i];
        }
        if(m < n || n == 2) {
            cout << -1 << endl;
            continue;
        }
        cout << sum << endl;
        for(int i = 0; i < n; i++) {
            int u = i + 1;
            int v = (i + 1) % n + 1;
            cout << u << " " << v << endl;
        }
    }
}