#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
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

const int N = 2e5 + 5;

int a[N], b[N], c[N], ab[N], bc[N];
int _a, _b, _c, ans = N;

int main() {
    read(_a); read(_b); read(_c);
    for(register int i = 1; i <= _a; i++) read(a[i]);
    for(register int i = 1; i <= _b; i++) read(b[i]);
    for(register int i = 1; i <= _c; i++) read(c[i]);
    sort(a + 1, a + _a + 1); sort(b + 1, b + _b + 1); sort(c + 1, c + _c + 1);
    int __a = 1, __b = 1, __c = _c;
    while(__a <= _a && __b <= _b) {
        if(a[__a] < b[__b]) {
            ab[__a] = _a - __a + __b - 1;
            ++__a;
        } else {
            ++__b;
        }
    }
    while(__a <= _a) {
        ab[__a] = _a - __a + __b - 1;
        ++__a;
    }
    __b = _b;
    while(__b >= 1 && __c >= 1) {
        if(c[__c] > b[__b]) {
            bc[__c] = __c - 1 + _b - __b;
            --__c;
        } else {
            --__b;
        }
    }
    while(__c >= 1) {
        bc[__c] = __c - 1 + _b - __b;
        --__c;
    }
    ab[0] = _a; bc[_c + 1] = _c;
    for(register int i = _c; i >= 1; i--) bc[i] = min(bc[i], bc[i + 1]);
    for(register int i = 0; i <= _a; i++) {
        int pos = _c + 1;
        if(c[_c] >= a[i]) pos = lower_bound(c + 1, c + _c + 1, a[i]) - c;
        ans = min(ans, ab[i] + bc[pos]);
    }
    print(ans, '\n');
    return 0;
}