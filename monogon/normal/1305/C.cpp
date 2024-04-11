
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, m;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    if(n >= m + 1) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            (ans *= abs(a[i] - a[j])) %= m;
        }
    }
    cout << ans << endl;
}