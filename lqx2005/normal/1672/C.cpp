#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10;
int n, a[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 0;
    for(int i = 2; i <= n; i++) if(a[i] == a[i - 1]) cnt++;
    if(cnt <= 1) {
        cout << 0 << "\n";
        return;
    }
    int l, r;
    for(int i = 2; i <= n; i++) if(a[i] == a[i - 1]) r = i;
    for(int i = n; i >= 2; i--) if(a[i] == a[i - 1]) l = i;
    r--;
    cout << max(1, r - l) << "\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}