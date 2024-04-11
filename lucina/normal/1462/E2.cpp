#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
const int M = 102;
const int MOD = 1e9 + 7;
void plusle(int &a, int b) {
    a += b;
    while (a >= MOD) a -= MOD;
}
void minun(int &a, int b) {
    a -= b;
    while (a < 0) a += MOD;
}
int add(int a, int b) {
    a += b;
    while (a >= MOD) a -= MOD;
    return a;
}
int sub(int a, int b) {
    a -= b;
    while (a < 0) a += MOD;
    return a;
}
int mul(int a, int b) {
    return int64_t(a) * b % MOD;
}
int power(int a, int64_t b) {
    int res = 1;
    for (; b > 0 ; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}

const int MX = 2e5 + 10;
int fac[MX], invf[MX] ;
void prefact() {
    fac[0] = 1 ;
    for (int i = 1 ; i < MX ; i ++) {
        fac[i] = mul(fac[i - 1], i);
    }
    invf[MX - 1] = power (fac[MX - 1], MOD - 2);
    for (int i = MX - 2 ; i >= 0 ; i --) {
        invf[i] = mul(invf[i + 1], i + 1);
    }
}

int ncr(int N, int R) {
    if (R > N) return 0;
    if (R == 0 || R == N) return 1;
    return mul (fac[N], mul(invf[N - R], invf[R]));
}


int n, m, k;
int a[nax];

void solve() {
    cin >> n >> m >> k;
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
    int ans = 0;

    plusle(ans, sub(ncr(j, m), ncr(j - f[cur], m)));

  //  fprintf(stderr, "NCR(%d %d) - NCR(%d %d)\n", j, m, j - f[cur], m);

    int from = 1;

    for (int i = 1 ; i < s.size() ; ++ i) {
        while (a[from] == cur) ++ from;
        cur = s[i];
        while (j <= n && a[j] - cur <= k) ++ j;
        -- j;
        int len = j - from + 1;
        int fre = f[cur];
        plusle(ans, sub(ncr(len, m), ncr(len - fre, m)));
      //  fprintf(stderr, "NCR(%d %d) - NCR(%d %d)\n", len, m, len - fre, m);


    }

    cout << ans << '\n';

}


int main() {
    prefact();
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }

}