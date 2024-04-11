// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

int n, k, a[50][50];
 
int main() {
    int T; read(T);
    while (T--) {
        memset(a, 0, sizeof a);
        read(n), read(k);
        int t = (n + 1) / 2;
        if (k <= t) {
            int x = 1;
            while (k--) {
                a[x][x] = 1;
                x += 2;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    putchar(a[i][j] ? 'R' : '.');
                }
                puts("");
            }
        } else puts("-1");
    }
    return 0;
}