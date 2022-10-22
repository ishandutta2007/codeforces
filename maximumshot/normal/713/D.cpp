#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1005;
int const LOG = 10;

int n, m;
int mat[N][N];
int rmq[LOG][N][LOG][N];
int res[N][N];
int le[N][N];
int up[N][N];
int _log[N];

void build() {
    for(int I = 0;I < LOG;I++) {
        for(int i = 1;i + (1 << I) - 1 <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(I == 0) rmq[I][i][0][j] = res[i][j];
                else rmq[I][i][0][j] = max(rmq[I - 1][i][0][j], rmq[I - 1][i + (1 << (I - 1))][0][j]);
            }
            for(int J = 1;J < LOG;J++) {
                for(int j = 1;j + (1 << J) - 1 <= m;j++) {
                    rmq[I][i][J][j] = max(
                            rmq[I][i][J - 1][j],
                            rmq[I][i][J - 1][j + (1 << (J - 1))]
                    );
                }
            }
        }
    }
}

int get_max(int li, int lj, int ri, int rj) {
    int lgi = _log[ri - li + 1];
    int lgj = _log[rj - lj + 1];
    return max(
            max(
                    rmq[lgi][li][lgj][lj],
                    rmq[lgi][ri - (1 << lgi) + 1][lgj][lj]
            ),
            max(
                    rmq[lgi][li][lgj][rj - (1 << lgj) + 1],
                    rmq[lgi][ri - (1 << lgi) + 1][lgj][rj - (1 << lgj) + 1]
            )
    );
}

bool solve() {

    _log[1] = 0; for(int i = 2;i < N;i++) _log[i] = ((1 << (_log[i - 1] + 1)) <= i?_log[i - 1] + 1 : _log[i - 1]);

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            scanf("%d", &mat[i][j]);
            if(mat[i][j]) {
                le[i][j] = le[i][j - 1] + 1;
                up[i][j] = up[i - 1][j] + 1;
                res[i][j] = min(
                        min(le[i][j], up[i][j]),
                        res[i - 1][j - 1] + 1
                );
            }
        }
    }

    build();

    int t;
    scanf("%d", &t);

    for(int result, bl, br, bm, li, lj, ri, rj, iter = 0;iter < t;iter++) {
        scanf("%d %d %d %d", &li, &lj, &ri, &rj);
        bl = 1;
        br = min(ri - li + 1, rj - lj + 1);
        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(get_max(li + bm - 1, lj + bm - 1, ri, rj) >= bm) bl = bm;
            else br = bm - 1;
        }
        if(bl < br && get_max(li + br - 1, lj + br - 1, ri, rj) >= br) result = br;
        else if(get_max(li + bl - 1, lj + bl - 1, ri, rj) >= bl) result = bl;
        else result = 0;
        printf("%d\n", result);
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}