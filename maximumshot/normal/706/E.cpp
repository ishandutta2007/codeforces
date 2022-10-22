#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1005;

int n, m, q;
int a[N][N];
pii le[N][N], ri[N][N], dn[N][N], up[N][N];
pii u[N], r[N], d[N], l[N];
pii u2[N], r2[N], d2[N], l2[N];

void read() {
    scanf("%d %d %d", &n, &m, &q);

    for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++)
            scanf("%d", &a[i][j]);
    for(int i = 0;i <= n + 1;i++) {
        for(int j = 0;j <= m + 1;j++) {
            le[i][j] = {i, j - 1};
            ri[i][j] = {i, j + 1};
            up[i][j] = {i - 1, j};
            dn[i][j] = {i + 1, j};
        }
    }
}

bool solve() {

    read();

    for(int iter = 0;iter < q;iter++) {
        int A, B, C, D, H, W;
        scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &H, &W);

        int i1, j1, i2, j2;

        i1 = A;
        i2 = C;
        j1 = j2 = 0;

        for(int it = 0;it < B;it++) tie(i1, j1) = ri[i1][j1];
        for(int it = 0;it < D;it++) tie(i2, j2) = ri[i2][j2];

        pii p1, p2, p3, p4;

        for(int it = 0;it < W;it++, tie(i1, j1) = ri[i1][j1], tie(i2, j2) = ri[i2][j2]) {
            p1 = {i1, j1};
            p2 = {i2, j2};
            p3 = up[p1.first][p1.second];
            p4 = up[p2.first][p2.second];
            swap(up[p1.first][p1.second], up[p2.first][p2.second]);
            swap(dn[p3.first][p3.second], dn[p4.first][p4.second]);
        }
        tie(i1, j1) = le[i1][j1];
        tie(i2, j2) = le[i2][j2];
        for(int it = 0;it < H;it++, tie(i1, j1) = dn[i1][j1], tie(i2, j2) = dn[i2][j2]) {
            p1 = {i1, j1};
            p2 = {i2, j2};
            p3 = ri[p1.first][p1.second];
            p4 = ri[p2.first][p2.second];
            swap(ri[p1.first][p1.second], ri[p2.first][p2.second]);
            swap(le[p3.first][p3.second], le[p4.first][p4.second]);
        }
        tie(i1, j1) = up[i1][j1];
        tie(i2, j2) = up[i2][j2];
        for(int it = 0;it < W;it++, tie(i1, j1) = le[i1][j1], tie(i2, j2) = le[i2][j2]) {
            p1 = {i1, j1};
            p2 = {i2, j2};
            p3 = dn[p1.first][p1.second];
            p4 = dn[p2.first][p2.second];
            swap(dn[p1.first][p1.second], dn[p2.first][p2.second]);
            swap(up[p3.first][p3.second], up[p4.first][p4.second]);
        }
        tie(i1, j1) = ri[i1][j1];
        tie(i2, j2) = ri[i2][j2];
        for(int it = 0;it < H;it++, tie(i1, j1) = up[i1][j1], tie(i2, j2) = up[i2][j2]) {
            p1 = {i1, j1};
            p2 = {i2, j2};
            p3 = le[p1.first][p1.second];
            p4 = le[p2.first][p2.second];
            swap(le[p1.first][p1.second], le[p2.first][p2.second]);
            swap(ri[p3.first][p3.second], ri[p4.first][p4.second]);
        }
        tie(i1, j1) = dn[i1][j1];
        tie(i2, j2) = dn[i2][j2];
    }

    int i, j;
    i = j = 0;
    tie(i, j) = ri[i][j];
    tie(i, j) = dn[i][j];

    for(int it = 0;it < n;it++) {
        for(int it2 = 0;it2 < m;it2++, tie(i, j) = ri[i][j]) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
        for(int it2 = 0;it2 < m;it2++, tie(i, j) = le[i][j]) {}
        tie(i, j) = dn[i][j];
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}