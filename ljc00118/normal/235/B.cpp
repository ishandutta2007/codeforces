#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5;

double f[3][N], p[N];
int n;

int main() {
    cin >> n;
    for(register int i = 1; i <= n; i++) scanf("%lf", &p[i]);
    for(register int i = 1; i <= n; i++) {
        f[0][i] = (f[0][i - 1] + 1.0) * p[i];
        f[1][i] = f[1][i - 1] + (2.0 * f[0][i - 1] + 1.0) * p[i];
//        f[2][i] = f[2][i - 1] + (3.0 * f[1][i - 1] + 3.0 * f[0][i - 1] + 1.0) * p[i];
    }
    printf("%.12lf\n", f[1][n]);
    return 0;
}