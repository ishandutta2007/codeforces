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

int n, m;
char a[N][N];
int d[N][N];

inline int f(int li, int lj, int ri, int rj) {
    ri = min(ri, n);
    rj = min(rj, m);
    return d[ri][rj] - d[li - 1][rj] - d[ri][lj - 1] + d[li - 1][lj - 1];
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        scanf("%s", a[i] + 1);
        for(int j = 1;j <= m;j++) {
            d[i][j] = (a[i][j] == '1') + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
        }
    }

    int r = inf;
    int mk = max(n, m);

    for(int k = 2;k <= mk;k++) {
        int tmp = 0;
        for(int i = 1;i <= n;i += k) {
            for(int c, j = 1;j <= m;j += k) {
                c = f(i, j, i + k - 1, j + k - 1);
                c = min(c, k * k - c);
                tmp += c;
            }
        }
        r = min(r, tmp);
    }

    printf("%d\n", r);

    return 0;
}