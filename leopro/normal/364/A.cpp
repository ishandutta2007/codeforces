#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

#define answer(ans) do { cout << (ans) << '\n'; exit(0); } while(0)

void solve() {
    int a;
    cin >> a;
    string s;
    cin >> s;
    vector<int> cnt(sqrt(a) + 2);
    ll n = s.size();
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += s[j] - '0';
            if (sum * 1LL * sum <= a) cnt[sum]++;
        }
    }
    if (a == 0) {
        cout << (n * (n + 1) / 2) * (n * (n + 1) / 2) - (n * (n + 1) / 2 - cnt[0]) * (n * (n + 1) / 2 - cnt[0]) << '\n';
        return;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += s[j] - '0';
            if (sum == 0) continue;
            if (a % sum == 0 && sum * 1LL * sum > a) ans += cnt[a / sum];
        }
    }
    ans *= 2;
    for (int s = sqrt(a) - 1; s <= sqrt(a) + 1; ++s) {
        if (s * s == a) ans += cnt[s] * 1LL * cnt[s];
    }
    cout << ans << '\n';
}