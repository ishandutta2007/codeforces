#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
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

const int MX = 1024 + 10;
int fac[MX], invf[MX] ;
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

int n, x, pos;
int gt;
int ls;

void bs(int n, int pos, int x) {
    int l = 0, r = n;

    while (l < r) {
        int mid = l + r >> 1;
       // printf("%d %d\n", l, r);

        if (mid == pos) {
            l = mid + 1;
            continue;
        }

        if (mid + 1 > pos) {
            ++ gt;
            r = mid;
        } else {
            ++ ls;
            l = mid + 1;
        }
    }
   // swap(ls, gt);
}
/**
    I HATE 0-INDEX BINARY SEARCHHHH
*/

int main() {
    prefact();
    scanf("%d %d %d", &n, &x, &pos);
    bs(n, pos, x);

  ///  printf("ls gt %d %d\n", ls, gt);

 /*   for (int ls = 0 ; ls <= 10 ; ++ ls)
    for (int gt = 0 ; gt <= 10 ; ++ gt)
    {
 //   puts("WAT");
*/
    int ans = mul(ncr(n - x, gt), fac[gt]);
    ans = mul(ans, mul(ncr(x - 1, ls), fac[ls]));
    ans = mul(ans, fac[n - 1 - gt - ls]);

  /*  if (ans == 824071958) {
        printf("%d %d\n", ls, gt);
        return 0;
    }
    */
    printf("%d\n", ans);

   // assert(false);

}