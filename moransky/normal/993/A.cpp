// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define y1 dmy

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

int x1 = 2e9, y1 = 2e9, x2 = -2e9, y2 = -2e9;
double len;
int sx = 0, sy = 0;
int L = 2e9, R = -2e9;

bool chk(int x, int y) {
    return x1 <= x && x <= x2 && y1 <= y && y <= y2 && abs(x - sx) + abs(y - sy) <= len;
}

int main() {
    for (int i = 1; i <= 4; i++) {
        int x, y; read(x), read(y);
        chkMin(x1, x);
        chkMin(y1, y);
        chkMax(x2, x);
        chkMax(y2, y);
    }
   
    for (int i = 1; i <= 4; i++) {
        int x, y; read(x), read(y);
        sx += x, sy += y;
        chkMin(L, x);
        chkMax(R, x);
    }
    len = (R - L + 1.0) / 2; sx /= 4, sy /= 4;
    for (int i = -100; i <= 100; i++) {
        for (int j = -100; j <= 100; j++) {
            if (chk(i, j)) {
                puts("YES"); return 0;
            }
        }
    }

    puts("NO");
    return 0;
}