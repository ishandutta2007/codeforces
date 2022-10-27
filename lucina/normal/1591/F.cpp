#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int n;
const int maxN = 5e5 + 10;
int a[maxN];
int dp[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 1;
    vector<pair<int,int>> st;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        int to_add = 0;
        while (!st.empty() && a[st.back().first] >= a[i]) {
            int was_sum = mult(st.back().second, a[st.back().first] % mod);
            cur = sub(cur, was_sum);
            to_add = sum(to_add, st.back().second);
            st.pop_back();
        }
        int p = dp[i - 1];
        if ((i - 1) % 2 == 1) p = sub(0, p);
        to_add = sum(to_add, p);
        cur = sum(cur, mult(to_add, a[i] % mod));
        st.emplace_back(i, to_add);
        if (i % 2 == 1) {
            dp[i] = cur;
        }
        else {
            dp[i] = sub(0, cur);
        }
//        cout << i << " " << dp[i] << " Hi " << endl;
    }
    cout << dp[n];
    return 0;
}