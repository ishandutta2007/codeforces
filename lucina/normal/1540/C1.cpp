#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void plusle(int &a, int b){a+=b;while(a>=MOD)a-=MOD;}
void minun(int &a, int b){a-=b;while(a<0)a+=MOD;}
int add(int a, int b){a+=b;while(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;while (a<0)a+=MOD;return a;}
int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}
const int M = 1e5 + 15;
const int N = 128;
int sum_c[N];
int b[N];
int c[N];
int n;
int pref_b[N];
int sum[N];
int ans[N];
int dp[M];
int tmp_dp[M];

int solve(int x) {
    fill(dp, dp + M, 0);
    dp[0] = 1;
    for (int i = 1 ; i <= n ; ++ i) {
        const int X = sum_c[i];
        int C = c[i];
        tmp_dp[0] = dp[0];
        for (int j = 1 ; j <= X ; ++ j) {
            tmp_dp[j] = dp[j];
            plusle(dp[j], dp[j - 1]);
            if (j > C) minun(dp[j], tmp_dp[j - C - 1]);
        }
        int lb = x * i + sum[i];
        if (lb > 0) fill(dp, dp + lb, 0);
    }
    return accumulate(dp, dp + 10010, 0LL) % MOD;
}

int main() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> c[i], sum_c[i] = c[i] + sum_c[i - 1];
    for (int i = 1 ; i < n ; ++ i)
        cin >> b[i];
    for (int i = 1, sum = 0 ; i < n ; ++ i) {
        sum += b[i];
        pref_b[i] = sum;
    }


    int L_first = 1e7 + 15;
    for (int i = 2 ; i <= n ; ++ i) {
        for (int j = 1 ; j < i ; ++ j)
            sum[i] += pref_b[j];
        L_first = min(L_first, - sum[i] / i);
    }

    int R = L_first + 101;
    for (int x = L_first, t = 0 ; x < R ; ++ x) {
        ans[t++] = solve(x);
    }
    int prod = 1;
    for (int i = 1 ; i <= n ; ++ i)
        prod = mul(prod, c[i] + 1);

    int q;
    cin >> q;
    while (q --) {
        int x;
        cin >> x;
        int final_ans = 0;
        if (x < L_first) final_ans = prod;
        else if (x < R) final_ans = ans[x-L_first];
        cout << final_ans << '\n';

    }
}



/**
    First thing first, when everything "fit" (f(i) + b(i) = f(i + 1))
    f1 + (f1 + b1) + (f1 + b1 + b2) + ...
    i * f1 + (sb_i) = sa_i,
    sb_i = b1 + (b1 + b2) + (b1 + b2 + b3) + ...
    sa_i = a1 + a2 + ... + ai
    f1 = (sa_i - sb_i) / i >= X
    sa_i - sb_i >= X * i -> This condition must true for every i.
    Imagine some "underfit" array -> it will converge to fit_array and condition is true
    for "overfit" the condition above is still true (meaning that sa_i is too much for some indexes with should not be a problem.)
    So the brute force solution is just run dp[i][X] number of arrays with prefix_sum = X...
    O(n^3)
    next, when the answer is 0 and when the answer is simply product of (c[i] + 1)
    When the answer is product(c[i] + 1)
    (sa_i - sb_i) / i >= X
    sa_i >= X * i + sb
    if x * i + sb_i <= 0, the answer is product(c[i] + 1)
    sa_i < X * i + sb_i, answer is 0
    n * M < x * n + s_n
    This equation is rather hard to analyze, but we can think it more simply

    L = first number which L * i + sb_i >= 0, this is where the solution may not be product
    (L + 101) * i + sb_i >= 101 * i which breaks the conditions
    so at most 100 make sense values.

*/