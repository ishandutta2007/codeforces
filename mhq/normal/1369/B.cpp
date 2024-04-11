#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans;
        int l = 0;
        while (l < s.size() && s[l] == '0') l++; l--;
        int r = s.size() - 1;
        while (r >= 0 && s[r] == '1') r--; r++;
        ans += string(l + 1, '0');
        if (l + 1 <= r - 1) ans += '0';
        ans += string(s.size() - r, '1');
        cout << ans << '\n';
    }
    return 0;
}