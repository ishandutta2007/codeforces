#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10;
int n, a[N], b[N], cnt[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cnt[i] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    int now = n;
    for(int r = n, l; r >= 1; r--) {
        l = r;
        while(l - 1 >= 1 && b[l] == b[l - 1]) l--;
        while(now >= 1 && a[now] != b[r]) {
            if(cnt[a[now]] == 0) {
                cout << "NO\n";
                return;
            }
            cnt[a[now]]--;
            now--;
        }
        if(now <= 0) {
            cout << "NO\n";
            return;
        }
        now--;
        cnt[b[r]] += r - l;
        r = l;
    }
    cout << "YES\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}