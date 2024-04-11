#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] - '0') % 2 == 0) ans += (i + 1);
    }
    cout << ans;
    return 0;
}