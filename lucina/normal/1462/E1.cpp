#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
const int M = 102;
const int MOD = 1e9 + 7;
void plusle(int64_t &a, int64_t b) {
    a += b;
}
void minun(int64_t &a, int64_t b) {
    a -= b;
}
int64_t sub(int64_t a, int64_t b) {
    a -= b;
    return a;
}
int64_t mul(int64_t a, int64_t b) {
    return int64_t(a) * b;
}
int64_t ncr(int N, int R) {
    if (N < R) return 0;
    assert(R == 3);
    int64_t ans = 1;
    ans = mul(ans, N);
    ans = mul(ans, N - 1);
    ans = mul(ans, N - 2);
    return ans / 6;
}


int n, m, k;
int a[nax];

void solve() {
    cin >> n;
    m = 3, k = 2;
    vector <int> s;
    map <int, int> f;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        f[a[i]] += 1;
        s.push_back(a[i]);
    }
    sort(a + 1, a + 1 + n);
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    int cur = s[0];

    int j = 1;
    while (j <= n && a[j] - cur <= k) ++ j;
    -- j;
    int64_t ans = 0;

    plusle(ans, sub(ncr(j, m), ncr(j - f[cur], m)));

    int from = 1;

    for (int i = 1 ; i < s.size() ; ++ i) {
        while (a[from] == cur) ++ from;
        cur = s[i];
        while (j <= n && a[j] - cur <= k) ++ j;
        -- j;
        int len = j - from + 1;
        int fre = f[cur];
        plusle(ans, sub(ncr(len, m), ncr(len - fre, m)));


    }

    cout << ans << '\n';

}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }

}