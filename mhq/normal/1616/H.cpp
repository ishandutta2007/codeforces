#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
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
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}


const int maxN = 15 * 10000 + 10;
int pw2[maxN];
int a[maxN];
int k;
int solve_big(int bit, int l1, int r1, int l2, int r2) {
    if (bit == -1 || l1 > r1 || l2 > r2) {
        return sub(mult(pw2[r1 - l1 + 1], pw2[r2 - l2 + 1]), 1);
    }
    int split_1 = l1;
    while (split_1 <= r1 && (!(a[split_1] & (1 << bit)))) split_1++; split_1--;
    int split_2 = l2;
    while (split_2 <= r2 && (!(a[split_2] & (1 << bit)))) split_2++; split_2--;
    if (k & (1 << bit)) {
        return sub(mult(solve_big(bit - 1, l1, split_1, split_2 + 1, r2) + 1, solve_big(bit - 1, split_1 + 1, r1, l2, split_2) + 1), 1);
    }
    else {
        int D = sum(solve_big(bit - 1, l1, split_1, l2, split_2), solve_big(bit - 1, split_1 + 1, r1, split_2 + 1, r2));
        D = sub(D, sub(pw2[split_1 - l1 + 1], 1));
        D = sub(D, sub(pw2[r1 - split_1], 1));
        D = sub(D, sub(pw2[split_2 - l2 + 1], 1));
        D = sub(D, sub(pw2[r2 - split_2], 1));
        D = sum(D, sub(pw2[r1 - l1 + 1], 1));
        D = sum(D, sub(pw2[r2 - l2 + 1], 1));
        return D;
    }
}




int n;
void solve() {
    cin >> n >> k;
    pw2[0] = 1;
    int bt = 30;
    map<int,int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pw2[i] = mult(2, pw2[i - 1]);
        mp[a[i]]++;
    }
    if (k == 0) {
        int ans = 0;
        for (auto& it : mp) ans = sum(ans, sub(pw2[it.second], 1));
        cout << ans << '\n';
        return;
    }

    while (!(k & (1 << bt))) bt--;
    sort(a + 1, a + n + 1);
    int ans = 0;
    int ptr = 1;
    while (ptr <= n) {
        int nptr = ptr;
        while (nptr <= n && ((a[ptr] ^ a[nptr]) < (1 << (bt + 1)))) nptr++; nptr--;
        int ptr2 = ptr;
        while (ptr2 <= nptr && (!(a[ptr2] & (1 << bt)))) ptr2++; ptr2--;
        ans = sum(ans, solve_big(bt, ptr, ptr2, ptr2 + 1, nptr));
        ptr = nptr + 1;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst = 1;
//    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}