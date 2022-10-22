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

int const K = 300005;
int const N = 1005;

int n, m, k;
int mat[N][N];

struct picture {
    int color;
    int li, lj, ri, rj;
    void read() {
        char type;
        scanf("%d %d %d %d %c", &li, &lj, &ri, &rj, &type);
        color = type - 'a';
    }
} p[K];

int diff[K];
ll total_diff = 0;
int d[N][N];

inline int get_sum(int li, int lj, int ri, int rj) {
    return d[ri][rj] - d[li - 1][rj] - d[ri][lj - 1] + d[li - 1][lj - 1];
}

int cnt[N][N];
int cnt_col[N][N];
ll sum_col[N][N];
ll cur_diff[N][N];
ll sum_diff[N][N];
ll sum_cnt_col[N][N];

ll tmp[K];

inline ll get_sum_diff(int li, int lj, int ri, int rj) {
    return sum_diff[ri][rj] - sum_diff[li - 1][rj] - sum_diff[ri][lj - 1] + sum_diff[li - 1][lj - 1];
}

inline ll get_sum_col(int li, int lj, int ri, int rj) {
    return sum_col[ri][rj] - sum_col[li - 1][rj] - sum_col[ri][lj - 1] + sum_col[li - 1][lj - 1];
}

inline ll get_sum_cnt_col(int li, int lj, int ri, int rj) {
    return sum_cnt_col[ri][rj] - sum_cnt_col[li - 1][rj] - sum_cnt_col[ri][lj - 1] + sum_cnt_col[li - 1][lj - 1];
}

void build() {
    for(int i = 1;i <= k;i++) {
        cnt[ p[i].ri ][ p[i].rj ]++;
        cnt[ p[i].li - 1 ][ p[i].rj ]--;
        cnt[ p[i].ri ][ p[i].lj - 1 ]--;
        cnt[ p[i].li - 1][ p[i].lj - 1 ]++;
    }
    for(int i = n;i >= 1;i--) {
        for(int j = m;j >= 1;j--) {
            cnt[i - 1][j] += cnt[i][j];
            cnt[i][j - 1] += cnt[i][j];
            cnt[i - 1][j - 1] -= cnt[i][j];
        }
    }
    for(int c = 0;c < 26;c++) {
        for(int i = 0;i <= n;i++) {
            for(int j = 0;j <= m;j++) {
                cnt_col[i][j] = 0;
            }
        }
        for(int i = 1;i <= k;i++) {
            if(p[i].color != c) continue;
            cnt_col[ p[i].ri ][ p[i].rj ]++;
            cnt_col[ p[i].li - 1 ][ p[i].rj ]--;
            cnt_col[ p[i].ri ][ p[i].lj - 1 ]--;
            cnt_col[ p[i].li - 1][ p[i].lj - 1 ]++;
        }
        for(int i = n;i >= 1;i--) {
            for(int j = m;j >= 1;j--) {
                cnt_col[i - 1][j] += cnt_col[i][j];
                cnt_col[i][j - 1] += cnt_col[i][j];
                cnt_col[i - 1][j - 1] -= cnt_col[i][j];
            }
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                cur_diff[i][j] += 1ll * abs( mat[i][j] - c ) * cnt_col[i][j];
            }
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                sum_col[i][j] = (mat[i][j] == c) * cnt[i][j];
                sum_col[i][j] += sum_col[i - 1][j] + sum_col[i][j - 1] - sum_col[i - 1][j - 1];

                sum_cnt_col[i][j] = sum_cnt_col[i - 1][j] + sum_cnt_col[i][j - 1] - sum_cnt_col[i - 1][j - 1];
                sum_cnt_col[i][j] += cnt_col[i][j];
            }
        }
        for(int i = 1;i <= k;i++) {
            tmp[i] -= 1ll * get_sum_col(p[i].li, p[i].lj, p[i].ri, p[i].rj) * abs(c - p[i].color);
            tmp[i] += 1ll * get_sum_cnt_col(p[i].li, p[i].lj, p[i].ri, p[i].rj) * abs(c - p[i].color);
        }
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            sum_diff[i][j] = sum_diff[i - 1][j] + sum_diff[i][j - 1] - sum_diff[i - 1][j - 1] + cur_diff[i][j];
        }
    }
}

int main() {

    scanf("%d %d %d", &n, &m, &k);

    if(k == 1) {
        puts("0");
        return 0;
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            char c;
            scanf(" %c", &c);
            mat[i][j] = c - 'a';
        }
    }

    for(int i = 1;i <= k;i++) {
        p[i].read();
    }

    for(int c = 0;c < 26;c++) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + (mat[i][j] == c);
            }
        }
        for(int i = 1;i <= k;i++) {
            diff[i] += abs(c - p[i].color) * get_sum(p[i].li, p[i].lj, p[i].ri, p[i].rj);
        }
    }

    for(int i = 1;i <= k;i++) {
        total_diff += diff[i];
    }

    ll res = inf64;

    build();

    for(int i = 1;i <= k;i++) {
        tmp[i] += total_diff - diff[i] + 1ll * diff[i] * (k - 1) + diff[i];
    }

    for(int i = 1;i <= k;i++) {
        tmp[i] -= (get_sum_diff(p[i].li, p[i].lj, p[i].ri, p[i].rj) - diff[i]);
    }

    for(int i = 1;i <= k;i++) {
        res = min(res, tmp[i]);
    }

    cout << res << "\n";

    return 0;
}