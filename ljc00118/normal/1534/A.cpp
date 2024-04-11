#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 55;

char c[N][N];
int T, n, m;

bool check(int x) {
    int cando = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] != '.') {
                int now = c[i][j] == 'R';
                if (now != ((i ^ j ^ x) & 1)) cando = 0;
            }
        }
    }
    if (!cando) return 0;
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((i ^ j ^ x) & 1) putchar('R');
            else putchar('W');
        }
        putchar('\n');
    }
    return 1;
}

int main() {
    read(T);
    while (T--) {
        read(n); read(m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", c[i] + 1);
        }
        int cando = 0;
        for (int i = 0; i <= 1; i++) {
            if (check(i)) {
                cando = 1;
                break;
            }
        }
        if (!cando) printf("NO\n");
    }
    return 0;
}