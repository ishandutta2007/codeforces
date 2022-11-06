#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
struct Mat { 
    int a[2][2]; 
} st, meta;
inline Mat operator*(const Mat &u, const Mat &v) {
    Mat ans;
    for (int i = 0; i < 2; ++i)
        for (int k = 0; k < 2; ++k)
            ans.a[i][k] = max(u.a[i][0] + v.a[0][k], u.a[i][1] + v.a[1][k]);
    return ans;
}
int n, pd[N], pt[N];
namespace Seg {
    const int xb = N - 5;
    Mat f[N << 1];
    inline void Pre() {
        for (int i = xb + 1; i < (N << 1); ++i) {
            f[i].a[0][0] = -1;
            f[i].a[1][0] = -1e15;
        }
        for (int i = xb; i; --i) f[i] = f[i << 1 | 1] * f[i << 1];
    }
    inline void Add(int x, int y) {
        f[xb + x].a[0][0] += y;
        f[xb + x].a[0][1] += y;
        for (int i = (xb + x) >> 1; i; i >>= 1) f[i] = f[i << 1 | 1] * f[i << 1];
    }
    inline Mat Ask(int x, int y) {
        Mat lans = meta, rans = meta;
        for (int l = xb + x - 1, r = xb + y + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
            if (~l & 1) lans = f[l ^ 1] * lans;
            if ( r & 1) rans = rans * f[r ^ 1];
        }
        return rans * lans;
    }
}
signed main() {
    meta.a[1][0] = -1e15;
    meta.a[0][1] = -1e15;
    Seg::Pre();
    scanf("%lld", &n);
    char opt[3];
    for (int i = 1, x, y; i <= n; ++i) {
        scanf("%s%lld", opt, &x);
        if (*opt == '+') {
            scanf("%lld", &y);
            Seg::Add(x, y);
            pt[i] = x; pd[i] = y;
        } else if (*opt == '-') {
            Seg::Add(pt[x], -pd[x]);
        } else {
            printf("%lld\n", (Seg::Ask(1, x) * st).a[0][0]);
        }
    }
    return 0;
}