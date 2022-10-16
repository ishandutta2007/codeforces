#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;
int ft[100005], in[100005];

int pw(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = 1ll * r * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return r;
}

int comb(int a, int b) {
    return 1ll * ft[a+b] * in[a] % mod * in[b] % mod;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ft[0] = 1;
    for (int i = 1; i <= 100000; ++i) ft[i] = 1ll * i * ft[i-1] % mod;
    in[100000] = pw(ft[100000], mod - 2);
    for (int i = 100000; i >= 1; --i) in[i-1] = 1ll * i * in[i] % mod;

    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1), s(n + 1, 0);
        for (int i = 1; i <= n; ++i) cin >> a[i], s[i] = s[i-1] + a[i];
        long long sum = s[n];
        map<long long, int> cnt;
        for (int i = 1; i < n; ++i) ++cnt[s[i]];
        int ans = 1;
        for (auto x: cnt) if (x.first < sum - x.first && cnt.find(sum - x.first) != cnt.end()) {
            ans = 1ll * ans * comb(x.second, cnt[sum - x.first]) % mod;
        }
        if (sum % 2 == 0 && cnt.find(sum / 2) != cnt.end()) {
            ans = 1ll * ans * pw(2, cnt[sum / 2]) % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}