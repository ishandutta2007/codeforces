#include <bits/stdc++.h>
#define pii pair<int, string>
#define par pair<pii, int>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 1e5 + 10;
const ll oo = 0x3f3f3f3f3f3f3f3f;
int t, n, x, a[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    for(int i = 1; i <= n; i++) a[i] -= x;
    ll mn = oo;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(mn + a[i] < 0) {
            cnt++;
            mn = oo;
        } else {
            mn = min(mn, 0ll) + a[i];
        }
    }
    cout << n - cnt << endl;
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; solve());
    return 0;
}