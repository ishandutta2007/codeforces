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

int T, n;

int main() {
    read(T); while(T--) {
        read(n);
        int ans = 0, have_zero = 0;
        for(register int i = 0; i <= 25; i++) {
            if(n & (1 << i)) ans = i;
        }
        for(register int i = 0; i < ans; i++) {
            if((n & (1 << i)) == 0) have_zero = 1;
        }
        if(have_zero) print((1 << (ans + 1)) - 1, '\n');
        else {
            ans = 1;
            for(register int i = 2; i * i <= n; i++) {
                if(n % i == 0) {
                    ans = n / i;
                    break;
                }
            }
            print(ans, '\n');
        }
    }
    return 0;
}