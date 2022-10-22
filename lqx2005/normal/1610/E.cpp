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
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int p = upper_bound(a + 1, a + n + 1, a[i]) - a;
        int cnt = p - i;
        for(; p <= n; ) {
            cnt++;
            p = lower_bound(a + 1, a + n + 1, a[p] * 2 - a[i]) - a;
        }
        ans = max(ans, cnt);
    }
    cout << n - ans << endl;
    return;
}

int main() {
    int t;
    for(cin >> t; t--; solve());
    return 0;
}