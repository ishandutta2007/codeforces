#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
int ask(int w) {
    cout << "? " << w << endl;
    int hw;
    cin >> hw;
    return hw;
}
void solve() {
    int n;
    cin >> n;
    int l = 1, r = 8e6, best = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(ask(mid) == 1) best = mid, r = mid - 1;
        else l = mid + 1;
    }
    best++;
    int ans = best - 1;
    for(int i = 2; i <= n; i++) {
        if(ask((best + i - 1) / i - 1) == i) {
            ans = min(ans, ((best + i - 1) / i - 1) * i);
        }
    }
    cout << "! " << ans << endl;
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(t = 1; t--; ) solve();
    return 0;
}