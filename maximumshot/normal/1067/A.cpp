#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 1e5 + 5;
const int X = 205;
const int mod = 998244353;

void add(int &x, int y) {
    if((x += y) >= mod) x -= mod;
}

int sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

int n;
int a[N];
int dp[N][X][2];
int sm[N][X][2];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    if(a[1] == -1) {
        for(int x = 1;x <= 200;x++) {
            dp[1][x][1] = 1;
        }
    }else {
        dp[1][ a[1] ][1] = 1;
    }

    for(int y = 0;y < 2;y++) {
        for(int x = 1;x < X;x++) {
            sm[1][x][y] = dp[1][x][y];
            add(sm[1][x][y], sm[1][x - 1][y]);
        }
    }

    for(int i = 2;i <= n;i++) {
        if(a[i] == -1) {
            for(int x = 1;x <= 200;x++) {
                add(dp[i][x][0], sub(sm[i - 1][200][0], sm[i - 1][x - 1][0]));
                add(dp[i][x][0], dp[i - 1][x][1]);
                add(dp[i][x][1], sm[i - 1][x - 1][0]);
                add(dp[i][x][1], sm[i - 1][x - 1][1]);
//                for(int y = x;y <= 200;y++) {
//                    add(dp[i][x][0], dp[i - 1][y][0]);
//                    if(x == y)
//                        add(dp[i][x][0], dp[i - 1][y][1]);
//                }
//                for(int y = 1;y < x;y++) {
//                    add(dp[i][x][1], dp[i - 1][y][0]);
//                    add(dp[i][x][1], dp[i - 1][y][1]);
//                }
            }
        }else {
            int x = a[i];
            for(int y = x;y <= 200;y++) {
                add(dp[i][x][0], dp[i - 1][y][0]);
                if(x == y)
                    add(dp[i][x][0], dp[i - 1][y][1]);
            }
            for(int y = 1;y < x;y++) {
                add(dp[i][x][1], dp[i - 1][y][0]);
                add(dp[i][x][1], dp[i - 1][y][1]);
            }
        }
        for(int y = 0;y < 2;y++) {
            for(int x = 1;x < X;x++) {
                sm[i][x][y] = dp[i][x][y];
                add(sm[i][x][y], sm[i][x - 1][y]);
            }
        }
    }

    int res = 0;

    if(a[n] == -1) {
        for(int x = 1;x <= 200;x++) {
            add(res, dp[n][x][0]);
        }
    }else {
        res = dp[n][a[n]][0];
    }

    printf("%d\n", res);

    return 0;
}