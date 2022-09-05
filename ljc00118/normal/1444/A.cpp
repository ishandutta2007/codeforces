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

int T;
ll a, b;

int main() {
    read(T);
    while (T--) {
        read(a); read(b);
        if (a % b == 0) {
            ll ans = 1, tmp = a;
            for (int i = 2; i * i <= b; i++) {
                if (b % i == 0) {
                    int cnt1 = 0, cnt2 = 0;
                    while (b % i == 0) b /= i, ++cnt1;
                    while (tmp % i == 0) tmp /= i, ++cnt2;
                    ll pw = 1;
                    for (int j = 1; j <= cnt2 - cnt1 + 1; j++) pw *= i;
                    ans = max(ans, a / pw);
                }
            }
            if (b != 1) {
                int cnt = 0;
                while (tmp % b == 0) tmp /= b, ++cnt;
                ll pw = 1;
                for (int j = 1; j <= cnt; j++) pw *= b;
                ans = max(ans, a / pw);
            }
            print(ans, '\n');
        } else {
            print(a, '\n');
        }
    }
    return 0;
}