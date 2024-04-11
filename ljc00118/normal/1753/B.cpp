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

const int N = 5e5 + 5;

int cnt[N];
int n, x;

int main() {
    read(n); read(x);
    for (int i = 1; i <= n; i++) {
        int a; read(a); ++cnt[a];
    }
    for (int i = 1; i < x; i++) {
        if (cnt[i] % (i + 1) != 0) {
            printf("No\n");
            return 0;
        }
        cnt[i + 1] += cnt[i] / (i + 1);
    }
    printf("Yes\n");
    return 0;
}