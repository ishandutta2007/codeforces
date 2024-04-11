#include <bits/stdc++.h>

using namespace std;
long long L, R;
int Q;
int meb[70];
set < pair < long long, long long > > pws[70];
const long long inf = 2 * (1e18);
long long mult(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    if (a > (inf / b)) return inf;
    else return a * b;
}
long long pw(long long x, int i) {
    if (i == 0) return 1;
    if (i & 1) return mult(x, pw(x, i - 1));
    long long res = pw(x, i / 2);
    return mult(res, res);
}
long long lim(long long x, int i) {
    if (i == 2) return sqrt(x);
    auto it = pws[i].lower_bound(make_pair(x + 1, -1));
    it--;
    return (*it).second;
}
long long get(long long x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    long long ans = 0;
    for (int i = 2; i <= 64; i++) ans += meb[i] * lim(x, i);
    return ans - 1;
}
void solve() {
    cin >> L >> R;
    //ans += get(R) - get(L - 1);
    //cout << ans;
    cout << get(R) - get(L - 1) << endl;
}
int main() {
    //freopen("input.txt", "r", stdin);
    //calc();
    ios_base::sync_with_stdio(false);
    meb[1] = -1;
    for (int i = 2; i <= 65; i++) {
        bool ok = false;
        for (int j = 2; j * j <= i; j++) {
            if ((i % j) == 0) {
                ok = true;
                int t = (i / j);
                if (t % j == 0) meb[i] = 0;
                else meb[i] = -meb[t];
                break;
            }
        }
        if (ok) continue;
        meb[i] = 1;
    }
    for (int i = 3; i <= 65; i++) {
        for (int j = 1; ; j++) {
            long long p = pw(j, i);
            if (p > ((long long)1e18) + 100) break;
            pws[i].insert(make_pair(p, j));
        }
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) solve();
    return 0;
}