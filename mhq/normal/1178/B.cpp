#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e6 + 100;
int bef[maxN];
int aft[maxN];
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        bef[i + 1] = bef[i];
        if (i > 0 && s[i] == 'v' && s[i - 1] == 'v') bef[i + 1]++;
    }
    int n = s.size();
    aft[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        aft[i] = aft[i + 1];
        if (i + 1 < n && s[i] == 'v' && s[i + 1] == 'v') aft[i]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') ans += 1LL * bef[i] * aft[i + 1];
    }
    cout << ans;
    return 0;
}