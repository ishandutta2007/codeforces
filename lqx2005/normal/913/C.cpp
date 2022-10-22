#include <bits/stdc++.h>
#define par pair<int, int>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 1e3 + 10;
int n, c[N], L;
ll d[N];
void solve() {
    cin >> n >> L;
    vector<int> stk;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        d[i] = ll(c[i]) << (n - i);
        if(stk.empty()) stk.push_back(i);
        else if(d[stk.back()] > d[i]) stk.push_back(i);
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    ll sum = 0;
    for(int i = sz(stk) - 1; i >= 0; i--) {
        sum += 1ll * (L >> stk[i]) * c[stk[i]];
        L %= 1 << stk[i];
        if(L == 0) ans = min(ans, sum);
        else ans = min(ans, sum + c[stk[i]]);
    }
    cout << ans << endl;
    return;
}
int main() {
    int t;
    for(t = 1; t--; solve());
    return 0;
}