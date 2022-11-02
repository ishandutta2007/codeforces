// 
#include <assert.h>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,s,t) for(int i=(s),i##END=(t);i<=i##END;++i)
#define per(i,t,s) for(int i=(t),i##END=(s);i>=i##END;--i)
#define REP(i,s,t) for(int i=(s),i##END=(t);i<i##END;++i)
#define PER(i,t,s) for(int i=(t),i##END=(s);i>i##END;--i)
#define elif else if
namespace MyMinMax{
template <typename T>
inline T mn(const T x, const T y) { return x < y ? x : y; }
template <typename T>
inline T mx(const T x, const T y) { return x > y ? x : y; }
template <typename T>
inline bool chmin(T &x, const T y) { return (x > y) && ((x = y), 1); }
template <typename T>
inline bool chmax(T &x, const T y) { return (x < y) && ((x = y), 1); }
template <typename T, typename ...Args>
inline T mx(const T x, const Args ...args) { return mx(x, mx(args...)); }
template <typename T, typename ...Args>
inline T mn(const T x, const Args ...args) { return mn(x, mn(args...)); }
}
using namespace MyMinMax;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL INFll = 0x3f3f3f3f3f3f3f3fll;
/* My Code begins here */

inline int query(int x, int y) {
    int tmp; printf("? %d %d\n", x, y);
    fflush(stdout); scanf("%d", &tmp); return tmp;
}

const int n = 1e9;
signed main() {
    int ld, rd, lu, ru;
    ld = query(1, 1); rd = query(n, 1); lu = query(1, n); ru = query(n, n);

    int l = 1, r = n, ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1; const int x = query(mid, 1);
        if(x + mid == ld + 1) l = mid + 1, ans = x;
        else r = mid - 1;
    }

    int d = ans + 1;
    l = 1 + ld - ans;
    r = n - rd + ans;
    int u = n - lu + l - 1;

    printf("! %d %d %d %d\n", l, d, r, u); fflush(stdout);
}