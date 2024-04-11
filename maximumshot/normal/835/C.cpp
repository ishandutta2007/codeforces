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

int const C = 11;
int const X = 105;

int n, q, c;
int cnt[C][X][X];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &q, &c);

    for(int x, y, s, i = 0;i < n;i++) {
        scanf("%d %d %d", &x, &y, &s);
        cnt[s][x][y]++;
    }

    for(int s = 0;s <= c;s++) {
        for(int x = 0;x < X;x++) {
            for(int y = 0;y < X;y++) {
                if(x > 0) cnt[s][x][y] += cnt[s][x - 1][y];
                if(y > 0) cnt[s][x][y] += cnt[s][x][y - 1];
                if(x > 0 && y > 0) cnt[s][x][y] -= cnt[s][x - 1][y - 1];
            }
        }
    }

    for(int t, xl, xr, yl, yr, iter = 0;iter < q;iter++) {
        scanf("%d %d %d %d %d", &t, &xl, &yl, &xr, &yr);
        int res = 0;
        for(int s = 0;s <= c;s++) {
            int tmp = cnt[s][xr][yr] - cnt[s][xr][yl - 1] - cnt[s][xl - 1][yr] + cnt[s][xl - 1][yl - 1];
            res += ((s + t) % (c + 1)) * tmp;
        }
        printf("%d\n", res);
    }

    return 0;
}