#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2505;

inline ll Sqr(int x) {
    return 1ll * x * x;
}

struct pt {
    int x, y;

    pt() : x(0), y(0) { }

    void read() {
        scanf("%d %d", &x, &y);
    }

    ll distSqr(pt const & other) {
        return Sqr(x - other.x) + Sqr(y - other.y);
    }

    double dist(pt const & other) {
        return sqrt(distSqr(other));
    }
};

int n;
pt p[N];
double dp[N][N][2];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 0;i < n;i++) {
        p[i].read();
    }

    for(int j, i = 0;i < n;i++) {
        j = (i + 1) % n;
        dp[i][j][0] = dp[i][j][1] = p[i].dist(p[j]);
    }

    for(int len = 3;len <= n;len++) {
        for(int r, l = 0;l < n;l++) {
            r = (l + len - 2) % n;
            for(int x = 0;x < 2;x++) {
                int last = x ? r : l;

                dp[l][(r + 1) % n][1] = max(dp[l][(r + 1) % n][1],
                        dp[l][r][x] + p[x ? r : l].dist( p[(r + 1) % n] ) );

                dp[(l - 1 + n) % n][r][0] = max(dp[(l - 1 + n) % n][r][0],
                        dp[l][r][x] + p[x ? r : l].dist( p[ (l - 1 + n) % n ] ) );
            }
        }
    }

    double res = 0.0;

    for(int j, i = 0;i < n;i++) {
        j = (i - 1 + n) % n;
        res = max(res, dp[i][j][0]);
        res = max(res, dp[i][j][1]);
    }

    printf("%.10lf\n", res);

    return 0;
}