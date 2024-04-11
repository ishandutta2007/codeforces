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
int t, n, a[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = max(0, n - 2);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            int cnt = 0;
            // (a[i] - a[j]) / (i - j) * (k - j) + a[j]
            for(int k = 1; k <= n; k++) {
                if(k == i || k == j) continue;
                int delta = a[k] - a[j];
                if(delta * (i - j) == (a[i] - a[j]) * (k - j)) {
                    continue;
                } 
                cnt++;
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; solve());
    return 0;
}