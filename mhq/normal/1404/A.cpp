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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool ok = true;
        for (int i = k; i < n; i++) {
            if (s[i] == '?' || s[i - k] == '?' || s[i] == s[i - k]) {
                continue;
            }
            ok = false;
        }
        for (int i = k; i < n; i++) {
            if (s[i] != '?') {
                if (s[i % k] != '?' && s[i % k] != s[i]) ok = false;
                s[i % k] = s[i];
            }
        }
        int cnt0 = 0;
        int cnt1 = 0;
        int cntq = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == '0') cnt0++;
            else if (s[i] == '1') cnt1++;
            else cntq++;
        }
        if (max(cnt0, cnt1) > min(cnt0, cnt1) + cntq) ok = false;
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}