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

string T;

int inline ask(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    string o; cin >> o;
    return o == "y" ? 1 : 0;
}

bool inline check(int a, int l) {
    return ask(a - 1, a + l - 1);
}

int main() {
    while (cin >> T, T != "end") {
        int p = 1;
        while (p * 2 <= 1e9) {
            if (check(p, p)) p <<= 1;
            else break;
        }
        int l = 0, r = p - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(p, mid)) l = mid;
            else r = mid - 1;
        }
        printf("! %d\n", p + r);
        fflush(stdout);
    }
    return 0;
}