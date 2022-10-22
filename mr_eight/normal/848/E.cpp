//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i, a, b) for (register int i = a, i##end = b; i <= i##end; ++i)
#define UF(i, a, b) for (register int i = a, i##end = b; i >= i##end; --i)
#define re register
#define ri re int
#define il inline
#define pii pair<int, int>
#define cp complex<double>
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
// using namespace __gnu_pbds;
const double Pi = acos(-1);
namespace fastIO {
template <class T>
inline void read(T &x) {
    x = 0;
    bool fu = 0;
    char ch = 0;
    while (ch > '9' || ch < '0') {
        ch = getchar();
        if (ch == '-')
            fu = 1;
    }
    while (ch <= '9' && ch >= '0') x = (x * 10 - 48 + ch), ch = getchar();
    if (fu)
        x = -x;
}
inline int read() {
    int x = 0;
    bool fu = 0;
    char ch = 0;
    while (ch > '9' || ch < '0') {
        ch = getchar();
        if (ch == '-')
            fu = 1;
    }
    while (ch <= '9' && ch >= '0') x = (x * 10 - 48 + ch), ch = getchar();
    return fu ? -x : x;
}
char _n_u_m_[40];
template <class T>
inline void write(T x) {
    if (x == 0) {
        putchar('0');
        return;
    }
    T tmp = x > 0 ? x : -x;
    if (x < 0)
        putchar('-');
    register int cnt = 0;
    while (tmp > 0) {
        _n_u_m_[cnt++] = tmp % 10 + '0';
        tmp /= 10;
    }
    while (cnt > 0) putchar(_n_u_m_[--cnt]);
}
template <class T>
inline void write(T x, char ch) {
    write(x);
    putchar(ch);
}
}  // namespace fastIO
using namespace fastIO;
#define Mod 998244353
int N, Ans;
int R[16] = { 0, 4, 8, -1, 16, -10, 4, -12, -48, 26, -44, 15, -16, -4, -4, -1 };
int A[16] = { 0, 0, 0, 24, 4, 240, 204, 1316, 2988, 6720, 26200, 50248, 174280, 436904, 1140888, 3436404 };
int main() {
    scanf("%d", &N);
    for (int i = 16; i <= N; ++i) {
        int x = 0;
        for (int j = 0; j < 16; ++j) x = (x + (ll)R[(i - j - 1) & 15] * A[j]) % Mod;
        A[i & 15] = x;
    }
    printf("%d\n", (A[N & 15] + Mod) % Mod);
    return 0;
}