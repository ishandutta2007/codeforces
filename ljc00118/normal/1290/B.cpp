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

const int N = 2e5 + 5;

int s[N][26];
char c[N];
int n, q;

int main() {
    scanf("%s", c + 1); n = strlen(c + 1);
    for (int i = 1; i <= n; i++) {
        memcpy(s[i], s[i - 1], sizeof(s[i]));
        ++s[i][c[i] - 'a'];
    }
    read(q);
    while (q--) {
        int l, r; read(l); read(r);
        if (l == r) {
            printf("Yes\n");
            continue;
        }
        if (c[l] != c[r]) {
            printf("Yes\n");
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (s[l - 1][i] != s[r][i]) {
                ++cnt;
            }
        }
        if (cnt <= 2) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}