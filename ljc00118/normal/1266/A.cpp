#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 105;

char c[N];
int cnt[10];
int T, n, sum;

int main() {
    read(T);
    while (T--) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", c + 1); n = strlen(c + 1); sum = 0;
        for (int i = 1; i <= n; i++) ++cnt[c[i] - '0'], sum += (c[i] - '0');
        if (cnt[0] && cnt[0] + cnt[2] + cnt[4] + cnt[6] + cnt[8] >= 2 && sum % 3 == 0) {
            printf("red\n");
        } else {
            printf("cyan\n");
        }
    }
    return 0;
}