#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const long long INF = 1E10 + 5;

int a, b, h, w, n, x[N];
bool chk[N];
vector<long long> ve;

bool check(int u, long long a, long long b, long long h, long long w) {
    if (a >= h) {
        if (b >= w) {
            return true;
        }
        for (int i = 1; i <= u; i++) {
            b *= x[i];
            if (b >= w) {
                return true;
            }
        }
        return false;
    }
    else {
        long long mi = INF;
        fill(chk, chk + h, false);
        chk[a] = true; ve = {a};
        for (int i = 1; i <= u; i++) {
            int sz = ve.size();
            for (int j = 0; j < sz; j++) {
                long long v = ve[j];
                if (v * x[i] >= h) {
                    mi = min(mi, v * x[i]);
                } else if (!chk[v * x[i]]) {
                    ve.push_back(v * x[i]);
                    chk[v * x[i]] = true;
                }
            }
        }
        if (mi == INF) {
            return false;
        } else {
            mi /= a;
            if (b >= w) {
                return true;
            }
            long long cur = 1, th = (w - 1) / b + 1;
            for (int i = 1; i <= u; i++) {
                cur *= x[i];
                if (th <= cur / mi) {
                    return true;
                }
            }
            return false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> h >> w >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1, greater<int>());
    int le = 0, ri = min(n, 34), ans = -1;
    while (le <= ri) {
        int mi = (le + ri) / 2;
        if (check(mi, h, w, a, b) || check(mi, h, w, b, a)) {
            ans = mi;
            ri = mi - 1;
        } else {
            le = mi + 1;
        }
    }
    cout << ans;
}