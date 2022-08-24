#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 505;
const int maxM = (int)1e5 + 100;
string s;
int k, L, R;
int l[maxN], r[maxN];
int c[maxN];
int pref[maxM][26];
int ptrL[maxN];
int ptrR[maxN];
int val[maxM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            pref[i + 1][j] = pref[i][j] + ((s[i] - 'a') == j);
        }
    }
    cin >> k >> L >> R;
    for (int i = 1; i <= k; i++) {
        char tp;
        cin >> tp;
        cin >> l[i] >> r[i];
        c[i] = tp - 'a';
        ptrL[i] = n + 1;
    }
    memset(ptrR, -1, sizeof ptrR);
    int cur_cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int cnt = pref[i][c[j]];
            if (cnt >= l[j]) {
                if (ptrL[j] == n + 1) ptrL[j] = i;
            }
            if (cnt <= r[j]) {
                ptrR[j] = i;
            }
            if (cnt >= l[j] && cnt <= r[j]) val[i]++;
        }
        if (val[i] >= L && val[i] <= R) cur_cnt++;
    }
    ll ans = cur_cnt;
    auto upd = [&](int x, int d){
        if (x <= 0) return;
        if (L <= val[x] && val[x] <= R) {
            cur_cnt--;
        }
        val[x] += d;
        if (L <= val[x] && val[x] <= R) {
            cur_cnt++;
        }
    };
    for (int i = 2; i <= n; i++) {
        if (val[i - 1] >= L && val[i - 1] <= R) cur_cnt--;
        for (int j = 1; j <= k; j++) {
            if (ptrL[j] == n + 1) continue;
            ptrL[j] = max(ptrL[j], i);
            ptrR[j] = max(ptrR[j], i - 1);
            while (ptrL[j] <= n && pref[ptrL[j]][c[j]] - pref[i - 1][c[j]] < l[j]) {
                upd(ptrL[j], -1);
                ptrL[j]++;
            }
            while (ptrR[j] + 1 <= n && (pref[ptrR[j] + 1][c[j]] - pref[i - 1][c[j]] <= r[j])) {
                ptrR[j]++;
                upd(ptrR[j], 1);
            }
        }
        ans += cur_cnt;
    }
    cout << ans;
    return 0;
}