#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()
#define ar array

const int MOD = int(1e9) + 7;

inline int add(int a, int b) {
    a += b;
    return a - MOD * (a >= MOD);
}

inline int sub(int a, int b) {
    a -= b;
    return a + MOD * (a < 0);
}

void solve() {
    int n;
    cin >> n;
    vec<int> b(n);
    for (auto &x : b)
        cin >> x;
    vec<ll> pref(n, b[0]);
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + b[i];

    int sum = 1;
    map<ll, int> bad;
    bad[0]++;
    for (int i = 1; i < n; i++) {
        int cur = sum;
        sum = sub(sum, bad[b[i] - pref[i]]);
        bad[b[i] - pref[i]] = cur;
        sum = add(sum, cur);
    }
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}