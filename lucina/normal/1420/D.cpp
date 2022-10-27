#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int MOD = 998244353;
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
void plusle(int &a, int b) {
    a += b;
    while (a >= MOD) a -= MOD;
}
void minun(int &a, int b) {
    a -= b;
    while (a < 0) a += MOD;
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
const int MX = 3e5 + 10;
int fac[MX], invf[MX];
void prefact () {
    fac[0] = 1 ;
    for (int i = 1 ; i < MX ; i ++) {
        fac[i] = mul(fac[i - 1], i);
    }
    invf[MX - 1] = power (fac[MX - 1], MOD - 2);
    for (int i = MX - 2 ; i >= 0 ; i --) {
        invf[i] = mul(invf[i + 1], i + 1);
    }
}

int ncr (int N, int R) {
    if (R > N) return 0;
    if (R == 0 || R == N) return 1;
    return mul (fac[N], mul(invf[N - R], invf[R]));
}



int n, k;
int l[nax];
int r[nax];
map <int, int> in;
map <int, int> out;
set <int> foo;

int main() {
    prefact();
    scanf("%d %d", &n, &k);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d %d", l + i, r + i);
        in[l[i]] += 1;
        out[r[i] + 1] += 1;
        foo.insert(l[i]);
        foo.insert(r[i] + 1);
    }

    int cur = 0;
    int ans = 0;

    for (int i : foo) {
        int from = cur;
        from -= out[i];
        minun(ans, ncr(from, k));
        cur += in[i];
        cur -= out[i];
        plusle(ans, ncr(cur, k));
    }

    printf("%d\n", ans);

}