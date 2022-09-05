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

const int N = 1e5 + 5;

char c[N];
int a[N];
ll T;
int n;

int main() {
    read(n); read(T); scanf("%s", c + 1);
    for (int i = 1; i <= n; i++) a[i] = c[i] - 'a';
    T -= (1 << a[n]); T += (1 << a[n - 1]);
    for (int i = 1; i <= n - 2; i++) T += (1 << a[i]);
    if (T < 0 || T % 2 != 0) {
        printf("No\n");
        return 0;
    }
    T /= 2;
    sort(a + 1, a + n - 1);
    for (int i = n - 2; i >= 1; i--) {
        if (T >= (1 << a[i])) {
            T -= (1 << a[i]);
        }
    }
    if (T == 0) printf("Yes\n");
    else printf("No\n");
    return 0;
}