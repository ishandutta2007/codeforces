#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
string s;
const int maxN = (int)1e5 + 100;
int cnt[26];
int b[26];
int ans[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    int odd = 0;
    int TOT = 0;
    for (int i = 0; i < n; i++) {
        cin >> cnt[i];
        odd += (cnt[i] % 2);
        TOT += cnt[i];
    }
    if (odd != TOT % 2) {
        int who = 0;
        cout << 0 << '\n';
        for (int i = 0; i < TOT; i++) {
            while (!cnt[who]) who++;
            cout << (char)('a' + who);
            cnt[who]--;
        }
        return 0;
    }
    for (int d = 1; d <= TOT; d++) {
        if (TOT % d) continue;
        bool ok = true;
        for (int j = 0; j < 26; j++) {
            if (cnt[j] % (TOT / d)) {
                ok = false;
                break;
            }
            b[j] = cnt[j] / (TOT / d);
        }
        // i i + 1         2i + 1 
        //
        if (!ok) continue;
        int odd = 0;
        for (int i = 0; i < n; i++) {
            odd += (b[i] % 2);
        }
        if (odd != d % 2) continue;
        cout << (TOT / d) * (!(d % 2) + 1) << '\n';
        int l = 0;
        int r = d - 1;
        if (d % 2) {
            for (int j = 0; j < n; j++) {
                if (b[j] % 2) {
                    b[j]--;
                    ans[l] = j;
                    l = 1;
                    break;
                }
            }
        }
        int who = 0;
        while (l < r) {
            while (!b[who]) who++;
            b[who] -= 2;
            ans[l] = ans[r] = who;
            l++;
            r--;
        }
        for (int j = 0; j < TOT; j++) {
            cout << (char)('a' + ans[j % d]);
        }
        return 0;
    }
    return 0;
}