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

ull fpow(ull x, ull y) {
    ull ans = 1;
    while (y) {
        if (y & 1) ans *= x;
        y >>= 1; x *= x;
    }
    return ans;
}

const int N = 1e5 + 5;

struct atom { ull a[5]; };

atom operator + (const atom a, const atom b) {
    atom ans;
    for (int i = 0; i <= 4; i++) ans.a[i] = a.a[i] + b.a[i];
    return ans;
}

atom operator - (const atom a, const atom b) {
    atom ans;
    for (int i = 0; i <= 4; i++) ans.a[i] = a.a[i] - b.a[i];
    return ans;
}

atom operator * (const atom a, const ull b) {
    atom ans;
    for (int i = 0; i <= 4; i++) ans.a[i] = a.a[i] * b;
    return ans;
}

atom operator * (const atom a, const atom b) {
    atom ans;
    static ull tem[9];
    memset(tem, 0, sizeof(tem));
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            tem[i + j] += a.a[i] * b.a[j];
        }
    }
    for (int i = 0; i <= 4; i++) ans.a[i] = tem[i];
    for (int i = 5; i <= 8; i++) ans.a[i - 5] -= tem[i];
    return ans;
}

atom shift(atom a, int b) {
    int rev = (b % 10 >= 5);
    b %= 5;
    static ull tem[5];
    for (int i = 0; i <= 4; i++) {
        if (i + b <= 4) tem[i + b] = a.a[i];
        else tem[i + b - 5] = -a.a[i];
    }
    for (int i = 0; i <= 4; i++) {
        a.a[i] = tem[i];
        if (rev) a.a[i] = -a.a[i];
    }
    return a;
}

atom fpow(atom x, int y) {
    atom ans; memset(ans.a, 0, sizeof(ans.a)); ans.a[0] = 1;
    while (y) {
        if (y & 1) ans = ans * x;
        y >>= 1; x = x * x;
    }
    return ans;
}

atom a[N];
int n;

void fwt(atom *a) {
    int n = 100000;
    for (int mid = 1; mid < n; mid *= 10) {
        for (int i = 0; i < n; i += (mid * 10)) {
            for (int j = 0; j < mid; j++) {
                atom tem[10];
                for (int k = 0; k < 10; k++) {
                    atom res; memset(res.a, 0, sizeof(res.a));
                    for (int t = 0; t < 10; t++) {
                        res = res + shift(a[i + j + mid * t], k * t);
                    }
                    tem[k] = res;
                }
                for (int k = 0; k < 10; k++) a[i + j + mid * k] = tem[k];
            }
        }
    }
}

void ifwt(atom *a) {
    int n = 100000;
    for (int mid = 1; mid < n; mid *= 10) {
        for (int i = 0; i < n; i += (mid * 10)) {
            for (int j = 0; j < mid; j++) {
                atom tem[10];
                for (int k = 0; k < 10; k++) {
                    atom res; memset(res.a, 0, sizeof(res.a));
                    for (int t = 0; t < 10; t++) {
                        res = res + shift(a[i + j + mid * t], k * t);
                    }
                    tem[k] = res;
                }
                reverse(tem + 1, tem + 10);
                for (int k = 0; k < 10; k++) a[i + j + mid * k] = tem[k];
            }
        }
    }
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        int x; read(x);
        ++a[x].a[0];
    }
    fwt(a);
    for (int i = 0; i < 100000; i++) a[i] = fpow(a[i], n);
    ifwt(a);
    ull inv = fpow(3125, (1ull << 63) - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 3; j++) assert(a[i].a[j] == -a[i].a[j + 1]);
        print((a[i].a[0] + a[i].a[1]) * inv / 32 % (1ull << 58), '\n');
    }
    return 0;
}