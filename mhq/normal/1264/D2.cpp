#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int n;
const int maxN = (int)1e6 + 100;
string s;
int invfact[maxN];
int fact[maxN];
int inv[maxN];
int cnk(int a, int b) {
    if (a < b || b < 0) return 0;
    return mult(fact[a], mult(invfact[b], invfact[a - b]));
}
int tp[maxN];
int cnt0[maxN], cnt1[maxN];
int c_pref[maxN];
int c_2[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    inv[1] = fact[0] = fact[1] = invfact[0] = invfact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    cin >> s;
    n = s.size();
    int que = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') tp[i + 1] = 1;
        else if (s[i] == ')') tp[i + 1] = 0;
        else tp[i + 1] = 2;
        que += tp[i + 1] == 2;
    }
    cnt1[0] = 0;
    for (int i = 1; i <= n; i++) {
        cnt1[i] = cnt1[i - 1] + (tp[i] == 1);
    }
    cnt0[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        cnt0[i] = cnt0[i + 1] + (tp[i] == 0);
    }
    c_pref[que + 1] = 0;
    for (int i = que; i >= 0; i--) {
        c_pref[i] = sum(c_pref[i + 1], cnk(que, i));
    }
    c_2[que] = 0;
    for (int i = que - 1; i >= 0; i--) {
        c_2[i] = sum(c_2[i + 1], cnk(que - 1, i));
    }
    int val = 0;
    int que1 = 0;
    for (int pref = 1; pref < n; pref++) {
        if (tp[pref] == 0) continue;
        if (tp[pref] == 1) {
            int at_most = min(que + 1, que1 + 1 + cnt1[pref - 1] - cnt0[pref + 1]);
            at_most = max(at_most, 0);
//            cout << cnt1[pref - 1] << " " << cnt0[pref + 1] << endl;
            val = sum(val, c_pref[at_most]);
            que1 += (tp[pref] == 2);
        }
        else {
            int at_most = min(que + 1, que1 + 1 + cnt1[pref - 1] - cnt0[pref + 1]);
            at_most = max(at_most, 0);
//            cout << cnt1[pref - 1] << " " << cnt0[pref + 1] << endl;
            val = sum(val, c_2[at_most]);
            que1 += (tp[pref] == 2);
        }
    }
    cout << val;
    return 0;
}