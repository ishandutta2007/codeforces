#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    ll suffix = pow(9, s.size() - 1);
    ll prefix = 1;
    ll ans = suffix;
    for (int i = 0; i < s.size(); ++i) {
        int cur = s[i] - '0';
        if (cur == 0) break;
        ans = max(ans, prefix * (cur - 1) * suffix);
        prefix *= cur;
        suffix /= 9;
    }
    ans = max(ans, prefix);
    cout << ans << endl;
    return 0;
}