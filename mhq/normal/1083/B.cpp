#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k;
string s, t;
const ll LIMIT = (ll)1e18;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> n >> k;
    cin >> s >> t;
    bool flag = false;
    ll cnt = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (cnt >= k) {
            ans += k;
            continue;
        }
        if (flag) {
            cnt = (cnt - 2) * 2;
            if (s[i] == 'a') cnt += 2;
            else cnt += 1;
            if (t[i] == 'b') cnt += 2;
            else cnt += 1;
        }
        else if (s[i] != t[i]) {
            if (s[i] != t[i]) flag = true;
            cnt = 2;
        }
        else {
            cnt = 1;
        }
        ans += min(cnt, k);
    }
    cout << ans;
    return 0;
}