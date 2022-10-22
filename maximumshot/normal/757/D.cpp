#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int sum(int a, int b) {
    return (a + b) % mod;
}
inline int mul(int a, int b) {
    return (1ll * a * b) % mod;
}
inline void add(int & x, int y) {
    x = sum(x, y);
}

int const LOG = 20;
int const N = 79;
int const LEN = 6;

int n;
char s[N];
int dp[N + 1][1 << LOG];
vec< int > mas;

inline bool check(int mask) {
    if(mask == 0) return 0;
    int i = LOG - 1;
    while(!( (1 << i) & mask )) i--;
    while(i >= 0) {
        if(!( (1 << i) & mask )) {
            return 0;
        }
        i--;
    }
    return 1;
}

int main() {

    mas.reserve(1 << LOG);
    for(int i = 0;i < (1 << LOG);i++) {
        if(check(i)) {
            mas.push_back( i );
        }
    }

    scanf("%d %s", &n, s);

    for(int i = 0;i <= n;i++) {
        add(dp[i][0], 1);
        for(int mask = 0;mask < (1 << LOG);mask++) {
            if(!dp[i][mask]) continue;
            for(int value = 0, j = i + 1;j <= n;j++) {
                value <<= 1;
                if(s[j - 1] == '1') value |= 1;
                if(value > LOG) break;
                if(value > 0) {
                    add(dp[j][mask | (1 << (value - 1))], dp[i][mask]);
                }
            }
        }
    }

    int res = 0;

    for(int mask : mas) {
        for(int i = 0;i <= n;i++) {
            add(res, dp[i][mask]);
        }
    }

    printf("%d\n", res);

    return 0;
}