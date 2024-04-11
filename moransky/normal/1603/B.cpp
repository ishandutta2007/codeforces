// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
int main() {
    int T; read(T);
    while (T--) {
        LL x, y; read(x), read(y);
        LL n;
        if (x == y) printf("%lld\n", x), n = x;
        else if (x > y) printf("%lld\n", x + y), n = x + y;
        else {
            LL t = y / x;
            LL o = x * t;
            printf("%lld\n", (o + y) / 2), n = (o + y) / 2;
        }
    }
    return 0;
}