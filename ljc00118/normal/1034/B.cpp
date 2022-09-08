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

int n, m;

int main() {
    read(n); read(m);
    if(n > m) swap(n, m);
    if(n == 1) {
        int ans = m / 6 * 6;
        m %= 6;
        if(m >= 4) ans += (m - 3) * 2;
        cout << ans << endl;
        return 0;
    }
    if(n == 2) {
        if(m == 2) cout << 0 << endl;
        else if(m == 3) cout << 4 << endl;
        else if(m == 7) cout << 12 << endl;
        else cout << (ll)n * m << endl;
        return 0;
    }
    cout << (ll)n * m / 2 * 2 << endl;
    return 0;
}