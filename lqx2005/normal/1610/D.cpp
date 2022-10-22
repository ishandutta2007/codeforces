#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define node pair<ll, int>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 2e5 + 10, P = 1e9 + 7;
int n, a[N];

int power(int a, int b, int c = 1) {
    for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) c = 1ll * c * a % P;
    return c;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = power(2, n) - 1;
    for(int i = 1; n > 0; i++) {
        int m = 0;
        for(int j = 1; j <= n; j++) if(a[j] % 2 == 0) a[++m] = a[j];
        int cnt = 0;
        for(int j = 1; j <= m; j++) {
            a[j] /= 2;
            if(a[j] & 1) cnt++;
        }
        if(cnt) (ans += P - power(2, m - 1)) %= P;
        n = m;
    }
    cout << ans << endl;
    return;
}

int main() {
    solve();
    // int t;
    // for(cin >> t; t--; solve());
    return 0;
}