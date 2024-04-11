#include <bits/stdc++.h>

using namespace std;

int n;
long long x, y;
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> x >> y >> s;
    s = '1' + s;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) if (s[i] == '0' && s[i-1] == '1') ++cnt;
    long long ans = 0;
    if (cnt) ans += y, --cnt;
    ans += cnt * min(x, y);
    cout << ans << endl;
    return 0;
}