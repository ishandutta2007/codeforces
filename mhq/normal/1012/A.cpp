#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 10;
int n;
vector < int > s;
int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    s.resize(2 * n);
    for (int i = 0; i < s.size(); i++) cin >> s[i];
    sort(s.begin(), s.end());
    ll ans = (1LL * s[n - 1] - s[0]) * (s[2 * n - 1] - s[n]);
    for (int i = 0; i + n < 2 * n - 1; i++) {
        ans = min(ans, 1LL * (1LL * s[2 * n - 1] - s[0]) * (s[i + n] - s[i + 1]));
    }
    cout << ans;
    return 0;
}