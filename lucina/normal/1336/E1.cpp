#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10, mod = 998244353;
using ll = long long ;



void plusle (int &a, int b) {
    if (( a += b) >= mod ) a -= mod ;
}

int mul (int a, int b) {
    return 1LL * a * b % mod;
}

int power (int a, int b) {
    int res = 1;
    for (; b > 0 ; b >>= 1 , a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res ;
}


ll basis[40];

int im_bit[40];
int topIm_bit ;
int my_free;

int dp[36][36][1 << 12];
int ans[40];
int n, m;
bool mark[45];



void dfs (int pos, ll cur) {

    if (pos == topIm_bit + 1) {
        return (void) (ans[__builtin_popcountll(cur)] ++ );
    }

    dfs(pos + 1, cur);

    dfs(pos + 1, cur ^ basis[im_bit[pos]]);
}

void print_ans () {
    my_free = power(2, my_free);
    for (int i = 0 ; i <= m ; ++ i) {
        printf("%d ", 1LL * ans[i] * my_free % mod);
    }
    exit(0);

}


int main () {


    scanf("%d %d", &n, &m);

    memset(basis, -1, sizeof(basis));

    for (int iter = 1 ; iter <= n; ++ iter) {
        ll x;
        scanf("%lld", &x);

        for (int j = m - 1; j >= 0 ; -- j) {
            if (!(x >> j & 1)) continue;
            if ((x >> j & 1) && basis[j] != -1) {
                x ^= basis[j];
            } else {
                basis[j] = x;
                break;
            }
        }

        if (x == 0) ++ my_free;
    }

    int k = 0;

    for (int i = m - 1 ; i >= 0 ; -- i) {
        if (basis[i] != -1) {
            im_bit[++ topIm_bit] = i;
            mark[i] = true;
        }
    }

    k = topIm_bit;

    for (int i = 1 ; i <= k ; ++ i) {
        for (int j = i + 1 ; j <= k ; ++ j) {
            if (basis[im_bit[i]] >> im_bit[j] & 1) {
                basis[im_bit[i]] ^= basis[im_bit[j]];
            }
        }
    }

    if (k <= 25) {
        dfs(1, 0);
        print_ans();
    }

    int dif = m - k;

    int new_basis[40];

    dp[0][0][0] = 1;

    for (int i = 1 ; i <= k ; ++ i) {
        ll x = basis[im_bit[i]] ^ (1LL << im_bit[i]);

        int carry = 0;

        int &v = new_basis[i];
        v = 0;

        for (int j = 0 ; j < m ; ++ j) {
            if (mark[j]) {
                ++ carry;
                continue;
            }

            if (x >> j & 1) {
                v ^= (int)((1LL << j) >> carry);
            }
        }
    }


    for (int i = 1 ; i <= k ; ++ i)
    for (int j = 0 ; j <= i ; ++ j) {
        for (int x = 0 ; x < (1 << dif) ; ++ x) {
            plusle(dp[i][j][x], dp[i - 1][j][x]);
            plusle(dp[i][j][x], j > 0 ? dp[i - 1][j - 1][x ^ new_basis[i]] : 0);
        }
    }

    for (int i = 0 ; i <= k ; ++ i) {
        for (int x = 0 ; x < (1 << dif) ; ++ x) {
            plusle(ans[i + __builtin_popcount(x)], dp[k][i][x]);
        }
    }

    print_ans();

}
/*
    Good Luck
        -Lucina
*/