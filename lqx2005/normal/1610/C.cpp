#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define node pair<ll, int>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 2e5 + 10, P1 = 1e9 + 7, P2 = 1e9 + 9;
int n, a[N], b[N], c[N];

int check(int cnt) {
    int ans = 0;
    for(int i = 1; i <= n; i++) if(ans <= b[i] && cnt - ans - 1 <= a[i]) ans++;
    return ans >= cnt;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    int l = 0, r = n, best = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) best = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << best << endl;
    return;
}

int main() {
    int t;
    for(cin >> t; t--; solve());
    return 0;
}