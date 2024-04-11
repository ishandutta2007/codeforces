#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
typedef double db;
map<ll, int> cnt;
void solve() {
    cnt.clear();
    int n, x;
    cin >> n >> x;
    for(int i = 1, a; i <= n; i++) {
        cin >> a;
        cnt[a]++;
    }
    int ans = 0;
    for(; !cnt.empty(); ) {
        int v = cnt.begin() -> x;
        cnt[v]--;
        if(cnt[v] == 0) cnt.erase(v);
        ll u = 1ll * v * x;
        if(cnt.count(u)) {
            cnt[u]--;
            if(cnt[u] == 0) cnt.erase(u);
        } else ans++;
    }
    cout << ans << endl;
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; solve());
    return 0;
}