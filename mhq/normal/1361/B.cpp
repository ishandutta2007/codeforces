#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int tst;
int n, p;
const int mod = (int)1e9 + 7;
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int BUBEN = 22;
const int maxN = 1e7 + 10;
int cnt[maxN];
int val[maxN];
int SZ = 0;
void solve() {
    cin >> n >> p;
    vector < int > vals;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vals.emplace_back(x);
    }
    sort(vals.begin(), vals.end());
    if (p == 1) {
        cout << (int)vals.size() % 2 << '\n';
        return;
    }
    reverse(vals.begin(), vals.end());
    int lst = -1;
    int to_sub = 0;
    int cur_val = 0;
    SZ  = 0;
    for (int i = 0; i < vals.size(); i++) {
        int c = vals[i];
        if (lst == -1) {
            val[SZ] = c;
            cnt[SZ] = 1;
            SZ++;
            lst = c;
            cur_val = 1;
        }
        else {
            assert(lst >= c);
            int coef = pw(p, lst - c);
            to_sub = mult(to_sub, coef);
            cur_val = mult(cur_val, coef);
            lst = c;
            //need_sub 1
            if (SZ == 0) {
                assert(cur_val == 0);
                cur_val = 1;
                val[SZ] = c;
                cnt[SZ] = 1;
                SZ++;
                continue;
            }
            else {
                if (val[SZ - 1] >= BUBEN + c) {
                    to_sub = sum(to_sub, 1);
                    continue;
                }
                int D = val[SZ - 1];
                cnt[SZ - 1]--;
                if (cnt[SZ - 1] == 0) SZ--;
                cur_val = sub(cur_val, 1);
                for (int t = D - 1; t >= c; t--) {
                    val[SZ] = t;
                    cnt[SZ] = p - 1;
                    SZ++;
                }
            }
        }
    }
    assert(lst != -1);
    int T = pw(p, lst);
    cur_val = mult(cur_val, T);
    to_sub = mult(to_sub, T);
    cout << sub(cur_val, to_sub) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}