#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
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

const int N = 1 << 21;

ull a[N], b[N];
char c[N];
int cnt[N];
int n;

void fwt(ull *a, int opt) {
    for(register int mid = 1; mid < (1 << n); mid <<= 1) {
        for(register int i = 0; i < (1 << n); i += (mid << 1)) {
            for(register int j = 0; j < mid; j++) {
                if(opt == 1) a[i + j + mid] += a[i + j];
                else a[i + j + mid] -= a[i + j];
            }
        }
    }
}

int main() {
    read(n);
    for(register int i = 0; i < (1 << n); i++) cnt[i] = cnt[i >> 1] + (i & 1);
    scanf("%s", c);
    for(register int i = 0; i < (1 << n); i++) a[i] = (c[i] - '0') * (1ll << (cnt[i] << 1));
    scanf("%s", c);
    for(register int i = 0; i < (1 << n); i++) b[i] = (c[i] - '0') * (1ll << (cnt[i] << 1));
    fwt(a, 1); fwt(b, 1);
    for(register int i = 0; i < (1 << n); i++) a[i] = a[i] * b[i];
    fwt(a, -1);
    for(register int i = 0; i < (1 << n); i++) putchar(((a[i] >> (cnt[i] << 1)) & 3) + '0');
    putchar('\n');
    return 0;
}