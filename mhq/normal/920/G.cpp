#include <bits/stdc++.h>
using namespace std;
int t, x, p, k;
const int maxN = (int)1e6 + 10;
int lp[maxN];
int msk[maxN];
int sgn[maxN];
int sz;
void calc() {
    vector < int > pr;
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i < maxN; j++) {
            lp[i * pr[j]] = pr[j];
        }
    }
}
int get(int x) {
    int ans = 0;
    for (int mask = 0; mask < (1 << sz); mask++) {
        ans += sgn[mask] * (x / msk[mask]);
    }
    return ans;
}
void solve() {
    cin >> x >> p >> k;
    vector < int > pr;
    int prv = -1;
    while (p > 1) {
        int nxt = lp[p];
        p = p / nxt;
        if (nxt == prv) continue;
        pr.push_back(nxt);
        prv = nxt;
    }
    sz = pr.size();
    msk[0] = 1;
    sgn[0] = 1;
    for (int i = 1; i < (1 << sz); i++) {
        for (int j = 0; j < sz; j++) {
            if (i & (1 << j)) {
                msk[i] = msk[i ^ (1 << j)] * pr[j];
                sgn[i] = -sgn[i ^ (1 << j)];
            }
        }
    }
    int t = get(x);
    k = k + t;
    int l = x;
    int r = maxN * 100;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (get(mid) >= k) r = mid;
        else l = mid;
    }
    cout << r << endl;
}
int main() {
    //freopen("input.txt", "r", stdin);
    calc();
    cin >> t;
    //t = 3 * (int)1e4;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}