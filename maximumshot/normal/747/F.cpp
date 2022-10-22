#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

ll C[100][100];

ll get_cnt(ll max_len, vec< ll > mas) {
    if(max_len == 0) return 1;
    ll tot = 0;
    for(ll x : mas) tot += x;
    if(tot < max_len) return 0;
    vec< vec< ll > > dp(16, vec< ll >(max_len + 1));
    dp[0][0] = 1;
    for(ll can = 1;can <= mas[0] && can <= max_len;can++) {
        dp[0][can] = 1;
    }
    for(int x = 1;x < 16;x++) {
        dp[x] = dp[x - 1];
        for(ll len = 1;len <= max_len;len++) {
            for(ll can = 1;can <= mas[x] && can <= len;can++) {
                dp[x][len] += dp[x - 1][len - can] * C[len][can];
            }
        }
    }
    return dp[15][max_len];
}

void print_digit(ll x) {
    if(x < 10) {
        cout << x;
    }else {
        cout << char(x - 10 + 'a');
    }
}

int main() {

    C[0][0] = 1;
    for(int i = 1;i < 100;i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1;j < i;j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    ll k, t;

    cin >> k >> t;

    vec< ll > mas(16, t);
    ll max_len = 1, T;

    while(1) {
        T = 0;
        for(int dig = 1;dig < 16;dig++) {
            mas[dig]--;
            T += get_cnt(max_len - 1, mas);
            mas[dig]++;
        }
        if(T < k) {
            k -= T;
            max_len++;
        }else {
            break;
        }
    }

    if(max_len == 1) {
        print_digit(k);
        return 0;
    }

    for(int i = 0;i < max_len;i++) {
        for(int dig = !i;dig < 16;dig++) {
            if(!mas[dig]) continue;
            mas[dig]--;
            T = get_cnt(max_len - 1 - i, mas);
            if(T < k) {
                k -= T;
                mas[dig]++;
                continue;
            }
            print_digit(dig);
            break;
        }
    }

    return 0;
}