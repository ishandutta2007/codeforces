#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld INF = 1e12;
const ld eps = 1e-9;
const ld EPS = 1e-5;
long long a[105];
long long b[105];
int n;
ld dp[105][105];
int gr = 0;
ld val = 0;
bool cmp(int i, int j) {
    return (((ld)b[i] * val - a[i]) + eps < ((ld)b[j] * val - a[j]));
}
ld pref[150];
bool ok(ld x) {
    val = x;
    for (int i = 0; i <= gr; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    int l = 1;
    int r = 1;
    for (int i = 0; i < gr; i++) {
        r = l;
        while (a[r] == a[l]) r++; r--;
        vector < int > t;
        for (int j = l; j <= r; j++) t.push_back(j);
        sort(t.begin(), t.end(), cmp);
        reverse(t.begin(), t.end());
        pref[0] = 0.0;
        for (int i = 0; i < t.size(); i++) {
            pref[i + 1] = pref[i] + ((ld)b[t[i]] * x - a[t[i]]);
        }
        for (int open = 0; open <= n; open++) {
            for (int cnt = 0; cnt <= r - l + 1; cnt++) {
                if (open < cnt) continue;
                dp[i + 1][open - cnt + (r - l + 1) - cnt] = max(dp[i + 1][open - cnt + (r - l + 1) - cnt],
                                            dp[i][open] + pref[(r - l + 1) - cnt]);
            }
        }
        l = r + 1;
    }
    for (int i = 0; i <= n; i++) {
        if (dp[gr][i] >= -eps) return true;
    }
    return false;
}
set < long long > s;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (int j = 1; j <= n; j++) {
        cin >> b[j];
    }
    gr = s.size();
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
        }
    }
    ld l = 0;
    ld r = 1e8;
    for (int iter = 0; iter < 200; iter++) {
        if ((r - l) < eps) break;
        ld mid = (l + r) / 2;
        if (ok(mid)) r = mid;
        else l = mid;
    }
    cout << (long long)(1000 * (r - EPS) + 1);
    return 0;
}