// Skyqwq
#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
    if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

LL n;
 
int k;

char s[80];

bool inline ask(LL l, LL r) {
    printf("%lld %lld\n", l, r);
    fflush(stdout);
    scanf("%s", s);
    return (*s == 'Y') ? 1 : 0;
}

LL inline rd(LL l, LL r) {
    return (1ll * rand() * rand()  % (r - l + 1)) + l;
}

int main() {
    srand(114514);
    read(n), read(k);
    LL l = 1, r = n;
    for (int i = 0; i < 4500; i++) {
        l = max(1ll, l - k), r = min(r + k, n);
        if (r - l + 1 <= 65) {
            LL p = rd(l, r);
            if (ask(p, p)) {
                break;
            }
        } else {
            LL mid = (l + r) >> 1;
            if (ask(l, mid)) {
                r = mid;
            } else l = mid + 1;
        }
    }
    return 0;
}