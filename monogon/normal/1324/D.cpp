
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        a[i] -= b[i];
    }
    sort(a, a + n);
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        int j = upper_bound(a, a + i, -a[i]) - a;
        ans += i - j;
    }
    cout << ans << endl;
}