#include<cstdio>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<cassert>


void solve () {
    int res = std::numeric_limits<int>::max();
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int A = a, B  = b, C = c ;
    if (b % a == 0 && c % b == 0) {
        printf("0\n%d %d %d\n", a , b, c);
        return;
    }
    for (int j = 1 ; j <= 11000 ; ++ j) {
        int aa, bb,  cc;
        int op = std::abs(b - j);
        int lb = j * (c / j);
        int ub = j * ((c - 1) / j + 1);
        int u = std::abs(ub - c), v = lb == 0 ? std::numeric_limits<int>::max(): std::abs(lb - c);
        if (u < v ) {
            op += u;
            cc = ub;
        }
        else op += v, cc = lb;
        int sq = std::sqrt(j);
        int now = std::numeric_limits<int>::max();
        for (int v = 1 ; v <= sq ; ++ v) {
            if (j % v == 0){
                if (std::abs(v - a) < now) {
                    now = std::abs(v - a);
                    aa = v;
                }
                if (std::abs(j / v - a) < now) {
                    now = std::abs(j / v - a);
                    aa = j / v;
                }
            }
        }
        op += now;
        if (op < res) {
            A = aa;
            B = j;
            C = cc;
            res = op;
        }
    }
    using std::abs;
    assert(abs(A - a) + abs(B - b) + abs(C - c) == res);
    printf("%d\n%d %d %d\n", res, A, B, C);
}

int main () {
    int T;
    for (scanf("%d", &T) ; T -- ; solve())
    ;
}