#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
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
    if (b < 0) return 0;
    int res = 1;
    for (; b > 0 ; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}
const int nax = 2e5 + 10;
int n;
char s[nax];
int a;
int ab;
int ans;
int num_a;

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);

    int cur_qs = 0;

    int bar = 1;

    for (int i = 1 ; i <= n; ++ i) {
        if (s[i] == 'a') {
            a = add(a, bar);
        } else if (s[i] == 'b') {
            ab = add(ab, a);
        } else if (s[i] == 'c') {
            ans = add(ans, ab);
        } else {
            ans = mul(ans, 3);
            ans = add(ans, ab);
            ab = mul(ab, 3);
            plusle(ab, a);
            a = mul(a, 3);
            a = add(a, bar);
            bar = mul(bar, 3);
        }
    }

    printf("%d\n", ans);
}
/**
6
ac?b?c

number of ways to assign only something in the left
a   a   a   a   a
        a       b
*/